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

void outp2(vector<vector<ll>> &ou, string s = " ")
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

ll inf = 1e18;

void dfs(int &w, int &b, int &ans, vector<int> &used, vector<vector<int>> &gr, int v, vector<int> &cols)
{
	//cerr << v <<endl;
	used[v] = 1;
	int curmaxw = 0, curmaxb = 0;
	if (cols[v] == 1)
		curmaxw = 1;
	if (cols[v] == 2)
		curmaxb = 1;
	ans = max(ans, curmaxw);
	ans = max(ans, curmaxb);
	for (auto ve:gr[v])
	{
		if (!used[ve])
		{
			int w1 = 0, b1 = 0;
			dfs(w1, b1, ans, used, gr, ve, cols);
			if (cols[v] == 1)
				w1 = max(w1, b1 + 1);
			if (cols[v] == 2)
				b1 = max(b1, w1 + 1);
			ans = max(ans, b1 + curmaxw);
			ans = max(ans, b1 + curmaxb - 1);
			ans = max(ans, w1 + curmaxb);
			ans = max(ans, w1 + curmaxw - 1);
			curmaxb = max(curmaxb, b1);
			curmaxw = max(curmaxw, w1);
		}
	}
	w = curmaxw;
	b = curmaxb;
//	cerr << v << ' ' << w << ' ' << b << endl;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vector<int> cols(n);
	for (int i = 0; i < n; i++)
		cin >> cols[i];
	vector<vector<int>> gr(n);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	vector<int> used(n);
	int w = 0, b = 0, ans = 0;
	dfs(w, b, ans, used, gr, 0, cols);
	cout<<ans/2+1<<'\n';
}

int main()
{
	int tests = 1;
	cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
	int n;
	cin >> n;
}