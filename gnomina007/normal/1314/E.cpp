#include<vector>
#include<queue>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>

using namespace std;

//int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef vector<char>vc;
typedef vector<string>vs;
typedef vector<vector<int>>vii;
typedef vector<vector<char>>vvc;
typedef vector<vector<ll>>vll;
typedef vector< pair<ll, ll>>vpll;
typedef vector< pair<ld, ld>>vpld;
typedef vector< pair<int, int>>vpi;
typedef pair<ld, ld>pld;
#define mp make_pair
#define pb push_back

int mod=998244353;
const int bound = 2021;
int sum(int a, int b)
{
	int c = a + b;
	if (c >= mod)
	{
		c -= mod;
	}
	return c;
}
int dif(int a, int b)
{
	int c = a - b;
	if (c < 0)
	{
		c += mod;
	}
	return c;
}
int mlt(int a, int b)
{
	ll c = a * 1LL * b;
	return c % mod;
}
int ibit(int n, int i)
{
	return ((n >> i) & 1);
}
void outp(vii &ou)
{
	for (int i = 0; i < ou.size(); i++)
	{
		for (int j = 0; j < ou[i].size(); j++)
		{
			cout << ou[i][j] << ' ';
		}
		cout << '\n';
	}
}
int bp(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	int a = 0;
	if (!(y % 2))
	{
		a = bp(x, y / 2);
	}
	return (y % 2) ? mlt(bp(x, y - 1), x) : mlt(a, a);
}
int obr(int x)
{
	return bp(x, mod - 2);
}
const int maxn = 10000007;
int fact[1000007], ofact[1000007];
void prec()
{
	fact[0] = 1;
	ofact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		fact[i] = mlt(fact[i - 1], i);
	}
	//cerr << "sdsds" << endl;
	ofact[maxn - 1] = obr(fact[maxn - 1]);
	for (int i = maxn - 2; i > 0; i--)
	{
		ofact[i] = mlt(ofact[i + 1], i + 1);
	}
}
int c(int a, int b)
{
	return ((a <= b) && (a >= 0)) ? mlt(fact[b], mlt(ofact[a], ofact[b - a])) : 0;
}
ll gcd(ll x, ll y)
{
	//cerr << x << y << endl;
	if (x == 0)return y;
	return(x > y) ?  gcd(y, x) : gcd(y%x, x);
}
int solve1(int n)
{
	vii parts(n+1, vi( n+ 1));
	for (int i = 0; i < n + 1; i++)parts[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= n; k++)
		{
			parts[i][k] = parts[i][k - 1];
			if (i >= k)parts[i][k] = sum(parts[i][k], parts[i - k][k]);
		}
	int cur = 0;
	for (int i = 1; i <= n; i++)cur = sum(cur, parts[i][i]);
	return cur;
}
int solve2(int n)
{
	vii parts(n + 1, vi(n + 1));
	for (int i = 0; i < n + 1; i++)parts[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= n; k++)
		{
			parts[i][k] = parts[i][k - 1];
			if (i >= k*(k+1)/2)parts[i][k] = sum(parts[i][k], parts[i - k*(k+1)/2][k]);
		}
	int cur = 0;
	for (int i = 1; i <= n; i++)cur = sum(cur, parts[i][i]);
	return cur;
}
int getans(vi part, int k, int n)
{
/*	for (int i = 0; i < part.size() - 1; i++)
	{
		assert(part[i + 1] <= part[i]);
	}*/
	//sort(part.begin(), part.end());
	int sum = 0;
	for (int i = 0; i < part.size(); i++)
		sum += part[i];
	if (sum > n)return 0;
	if (k == 1)return 1;
	vi newp(sum);
	int cur = 0;
	for (int i = 0; i <part.size(); i++)
	{
		for (int j = 0; j < part[i]; j++)
		{
			newp[cur]=i+1;
			cur++;
		}
	}
	reverse(newp.begin(), newp.end());
	return getans(newp, k - 1,n);
}
int ans(vi curs, int curmin, int summ, int k, int n)
{
	if (summ >= bound)return 0;
	vi curs1 = curs;
	curs1.pb(curmin);
	int val = getans(curs, k, n);
	if (val == 0)return 0;
	if (curmin == 0)
	{
		return val;
	}
	else
		return sum(ans(curs, curmin - 1, summ, k,n), ans(curs1, curmin, summ + curs1.size()*curmin, k,n));
}
int solve_big(int n, int k)
{
	vi curs;
	return (mod+ans(curs, bound, 0, k, n)-1)%mod;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;
	cin >> n >> k;
	if (k == 1)cout << solve1(n) << endl;
	if (k == 2)cout << solve2(n) << endl;
	if (k >2)cout << solve_big(n,k) << endl;
}
int main()
{
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}