#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>
#include<queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<ll>> vvl;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<ld, ld>> vpld;
typedef vector<pair<int, int>> vpi;
typedef pair<ld, ld> pld;
#define mp make_pair
#define pb push_back

int mod = 998244353;
//int mod = 1e9 + 7;

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

void outp1(vl &ou, string s = " ")
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		cerr << ou[i] << ' ';
	}
	cerr << endl;
}

void outp1(vi &ou, string s = " ")
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		cerr << ou[i] << ' ';
	}
	cerr << endl;
}

void outp2(vector<vector<int>> &ou, string s = " ")
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		for (int j = 0; j < ou[i].size(); j++)
		{
			cerr << ou[i][j] << ' ';
		}
		cerr << '\n';
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

const int maxn = 301;
int fact[maxn], ofact[maxn];

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

int inf = 1e9 + 110;

int slv(vector<pair<int, int>> &edges, int mask, vector<int> &perm, int n, bool cool)
{
	if (n == 7 && mask == 63)
		return 0;
	vector<int> cols(n);
	cols[perm[0]] = 0;
	for (int i = 1; i < n; i++)
	{
		cols[perm[i]] = cols[perm[i - 1]];
		if (ibit(mask, i - 1))
			cols[perm[i]]++;

	}
//	if(cool)
	//   outp1(cols, "cols ");
	vector<vector<int>> used(6, vector<int>(6));
	for (auto ed: edges)
	{
		used[cols[ed.first]][cols[ed.second]]++;
		used[cols[ed.second]][cols[ed.first]]++;
	}
	int cur = 0;
	//if (cool)
	//   outp2(used, "USED ");
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (used[i][j] >= 1)
				cur++;
		}
		if (used[i][i])
			cur++;
	}
//	if(cool)
	//  cerr << cur << endl;
	return cur;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		edges.push_back({x, y});
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i;
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	int ans = 0;
	for (int i = 0; i < fact; i++)
	{
		for (int mask = 0; mask < (1 << (n - 1)); mask++)
		{
			//cerr << i << ' ' << mask << endl;
			//	outp1(v, "PERM ");
			bool cool = false;
			//		if(i==671&&mask==62)
			//			cool=true;
			ans = max(ans, slv(edges, mask, v, n, cool));
		}
		next_permutation(v.begin(), v.end());
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tests = 1;
	//cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
}