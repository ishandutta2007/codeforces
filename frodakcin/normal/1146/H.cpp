#include <iostream>
#include <cstdio>

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;
using ld = long double;
#define ALL(X) X.begin(),X.end()
#define pb push_back

ll gcd(ll a, ll b)
{
	if(!a)
		return b;
	return gcd(b%a, a);
}
struct vec
{
public:
	ll x, y;
	vec(ll x = 0LL, ll y = 0LL) : x(x), y(y) {}
	vec operator - (const vec& o) const
	{
		return vec(x - o.x, y - o.y);
	}
	vec operator + (const vec& o) const
	{
		return vec(x + o.x, y + o.y);
	}
	ll operator / (const vec& o) const
	{
		return x * o.y - o.x * y;
	}
	vec simpl(void) const
	{
		ll d = gcd(abs(x), abs(y));
		return vec(x/d, y/d);
	}
};

const int MN = 3e2 + 10;
int N;
ll f;
vec p[MN];

struct ST
{
public:
	vec dir;
	int n;
	bool f;
	ld ang;
	ST(const vec& x, int n, int f) : dir(x), n(n), f(f)
	{
		ang = atan2l(dir.y, dir.x);
	}
	bool operator < (const ST& o) const		//this should be fine
	{
		return ang < o.ang;
	}
};

vector<ST> ord[MN];
void pcpo(void)
{
	for(int i = 0;i < N;i++)
	{
		//ord[i].clear();
		for(int j = 0;j < N;j++)
			if(i!=j)
				ord[i].pb({(p[j] - p[i]).simpl(), j, 1}),
				ord[i].pb({(p[i] - p[j]).simpl(), j, 0});
		sort(ALL(ord[i]));
		//for(int j = 0;j < ord[i].size();j++)
		//	printf("%d: %d %.3Lg\n", i, ord[i][j].n, ord[i][j].ang);
	}
}

int dp[5][MN][MN];	//left, prev, cur
bool u[MN];

void solve(int n)
{
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < 4;j++)
			dp[j][n][i] = 0;
		dp[4][n][i] = i!=n;
	}
	for(int i = 4;i > 0;i--)		//4->3, 3->2, 2->1, 1->0
	{
		for(int j = 0;j < N;j++)
		{
			if(j==n) continue;
			
			ll cur = 0LL;
			bool can = 0;
			for(int k = 0;k < N;k++)
				u[k] = 0;
			for(ST& x : ord[j])
				if(!x.f)
					cur += dp[i][x.n][j], u[x.n] = 1, can |= x.n == n;
				else if(u[x.n])
					cur -= dp[i][x.n][j], can &= x.n != n;
			for(ST& x : ord[j])
				if(x.f)
					cur -= dp[i][x.n][j], dp[i-1][j][x.n] = can ? cur : 0LL, can &= x.n != n;
				else
					cur += dp[i][x.n][j], can |= x.n == n;
		}
	}
	for(int i = 0;i < N;i++)
		if(i != n)
			f += dp[0][i][n];
}

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++)
		scanf("%lld%lld", &p[i].x, &p[i].y);
	sort(p, p + N, [](const vec& a, const vec& b){return a.y>b.y||(!(b.y>a.y)&&a.x>b.x);});
	pcpo();
	for(;N>=5;N--)
	{
		solve(N-1);
		for(int i = 0;i < N-1;i++)
			for(int j = (N-1<<1) - 1;j >= 0;j--)
				if(ord[i][j].n == N-1)
					ord[i].erase(ord[i].begin() + j);
	}
	//cerr << dp[3][3][1] << "\n";
	printf("%lld\n", f);
	return 0;
}