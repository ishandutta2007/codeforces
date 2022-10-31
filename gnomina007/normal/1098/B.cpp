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

int con = 31;

int solve_type(vector<vector<char>> &ans, vector<vector<char>> &matr, int type, vector<char> &v)
{
	int an = 0;
	if (type == 0)
	{
		for (int i = 0; i < matr.size(); i++)
		{
			int c1 = 0, c2 = 0;
			for (int j = 0; j < matr[i].size(); j++)
			{
				if (matr[i][j] == v[2 * (i % 2) + j % 2])
					c1++;
				if (matr[i][j] == v[2 * (i % 2) + (j + 1) % 2])
					c2++;
			}
			an += max(c1, c2);
			for (int j = 0; j < matr[i].size(); j++)
			{
				if (c1 > c2)
					ans[i][j] = v[2 * (i % 2) + j % 2];
				else
					ans[i][j] = v[2 * (i % 2) + (j + 1) % 2];
			}
		}
	}
	else
	{
		for (int i = 0; i < matr[0].size(); i++)
		{
			int c1 = 0, c2 = 0;
			for (int j = 0; j < matr.size(); j++)
			{
				if (matr[j][i] == v[2 * (i % 2) + j % 2])
					c1++;
				if (matr[j][i] == v[2 * (i % 2) + (j + 1) % 2])
					c2++;
			}
			an += max(c1, c2);
			for (int j = 0; j < matr.size(); j++)
			{
				if (c1 > c2)
					ans[j][i] = v[2 * (i % 2) + j % 2];
				else
					ans[j][i] = v[2 * (i % 2) + (j + 1) % 2];
			}
		}
	}
	return an;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> matr(n, vector<char>(m)), cur(n, vector<char>(m)), ans = cur;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matr[i][j];
	vector<vector<char>> v1(6);
	v1[0] = {'A', 'C', 'G', 'T'};
	v1[1] = {'A', 'G', 'C', 'T'};
	v1[2] = {'A', 'T', 'C', 'G'};
	v1[3] = {'G', 'T', 'A', 'C'};
	v1[4] = {'C', 'T', 'A', 'G'};
	v1[5] = {'C', 'G', 'A', 'T'};
	int cr = 0;
	for (int mode = 0; mode < 2; mode++)
	{
		for (int j = 0; j < v1.size(); j++)
		{
			int val = solve_type(cur, matr, mode, v1[j]);
			if (cr < val)
			{
				cr = val;
				ans = cur;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << ans[i][j];
		cout<<'\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tests = 1;
	//cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
	//cout << "DONE" << endl;
	int n;
	cin >> n;
}