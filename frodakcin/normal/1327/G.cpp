#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>

template<class T> bool ckmax(T *a, T b) {return *a<b?*a=b,1:0;}
template<class T> bool ckmin(T *a, T b) {return b<*a?*a=b,1:0;}

using ll = long long;
const int MK = 1e3 + 10;//FIX CONSTRAINTS
const int MS = 4e5 + 100;
const int MC = 14;
const ll INF = 0x1111111111111112;
int l[MK], g[MK][MC], c[MK][MC], S, K, X = 1;
ll v[MK];
std::vector<int> down[MK];
std::queue<int> q;
char s[MS];

void create_aho()
{
	q.push(1);
	l[1] = 0;
	for(int i = 0;i < MC;++i)
		g[0][i] = 1;//placeholder for default
	for(int n;!q.empty();q.pop())
	{
		n = q.front();
		memcpy(g[n], c[n], sizeof(g[n]));
		if(l[n]) down[l[n]].push_back(n);
		for(int i = 0;i < MC;++i)
			if(c[n][i])
			{
				l[c[n][i]] = g[l[n]][i];
				q.push(c[n][i]);
			}
			else
				g[n][i] = g[l[n]][i];
	}
}
void setval(int n = 1)
{
	//printf("LINK: %d %d\n", n, l[n]);
	for(int x : down[n])
		v[x] += v[n], setval(x);
}

ll dp[2][1<<MC][MK];
int M, a[MC+1];
struct range
{
public:
	int n; ll v;
	range(int n = 1, ll v = 0) : n(n), v(v) {}
	void move(char x)
	{
		v += ::v[n = g[n][x]];
	}
	void move(int l, int r) //[)
	{
		for(int i = l;i < r;++i)
			move(s[i]);
	}
};
std::vector<int> bits[MC+1];
bool cur = 0;
void init()
{
	range x;
	x.move(0, a[0]);
	dp[cur][0][x.n] = x.v;
}
range to[MK];
ll rval;
bool big;
void handle(int m)
{
	for(int i = 1;i <= X;++i)
		to[i] = range(-1, v[i]);
	big = a[m] - a[m-1] > X + 1;
	if(big)
	{
		to[1].n = 1;
		to[1].move(a[m-1]+1, a[m-1]+X+1);
		range z(to[1].n, 0LL);
		z.move(a[m-1]+X+1, a[m]);
		to[1].n = z.n;
		to[1].v += rval = z.v;
	}
	auto get = [&](int n)
	{
		if(!~to[n].n)
		{
			to[n].n = n;
			if(big)
				to[n].move(a[m-1]+1, a[m-1]+X+1), to[n].v += rval, to[n].n = to[1].n;
			else
				to[n].move(a[m-1]+1, a[m]);
		}
		return to[n];
	};
	for(int i : bits[m-1])
		for(int j = 1;j <= X;++j)
			if(dp[cur][i][j] != -INF)
			{
				ll p = dp[cur][i][j];
				for(int k = 0;k < MC;++k)
					if(!(i>>k&1))
					{
						range x = get(g[j][k]);
						//printf("JUMP: %d -> %d\n", g[j][k], x.n);
						ckmax(dp[!cur][i|1<<k]+x.n, dp[cur][i][j]+x.v);
					}
			}
	memset(dp[cur], 0xee, sizeof(dp[cur]));
	cur = !cur;
}
int main(void)
{
	for(int i = 0;i < 1<<MC;++i)
		bits[__builtin_popcount(i)].push_back(i);
	scanf("%d", &K);
	for(int i = 0, y;i < K;++i)
	{
		scanf(" %s%d", s, &y);
		int n = 1;
		for(int j = 0;s[j];++j)
		{
			s[j] -= 'a';
			if(c[n][s[j]])
				n = c[n][s[j]];
			else
				n = c[n][s[j]] = ++X;
		}
		//printf("INS: %d %d\n", i, n);
		v[n] += y;
	}
	create_aho();
	setval();
	scanf(" %s", s);
	for(;s[S];++S)
		if(s[S] != '?')
			s[S] -= 'a';
		else
			a[M++] = S, s[S] = 0xff;
	a[M] = S;
	memset(dp, 0xee, sizeof(dp));
	init();
	for(int i = 1;i <= M;++i)
		handle(i);
	ll ans = -INF;
	for(int x : bits[M])
		for(int y = 1;y <= X;++y)
			ckmax(&ans, dp[cur][x][y]);
	printf("%lld\n", ans);
	return 0;
}