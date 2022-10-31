//#include <bits/stdc++.h>
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
#include<ctime>
#include<unordered_map>

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
#pragma GCC optimize "-O3"

//const int mod = 998244353;
const int mod = 1e9 + 7;

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

const int maxn = 1e7 + 2;
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

const int MAXA = 1e6 + 2;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	if (a == 0)
		return b;
	if (a < b)
		return gcd(b, a);
	return gcd(b, a % b);
}

void addnm(map<vector<vector<int>>, vector<vector<pair<int, int>>>> &p, int n, int m)
{
	//cerr << "Here " << n << ' ' << m << endl;
	vector<vector<pair<int, int>>> intposes;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			for (int h = 0; h < 2; h++)
				for (int g = 0; g < 2; g++)
				{
					vector<pair<int, int>> pq;
					for (int hh = 0; hh < 2; hh++)
						for (int gg = 0; gg < 2; gg++)
							if (hh != h || gg != g)
								pq.pb({i + hh, j + gg});
					intposes.pb(pq);
				}
	int sz = intposes.size();
	for (int mask = 0; mask < (1 << sz); mask++)
	{
		vector<vector<int>> vp(n, vector<int>(m));
		vector<vector<pair<int, int>>> pqr;
		int val = 0;
		for (int i = 0; i < sz; i++)
			if (ibit(mask, i))
			{
				val++;
				pqr.pb(intposes[i]);
				for (auto pr:intposes[i])
					vp[pr.first][pr.second] ^= 1;
			}
		if (val <= m * n)
			//	cerr<<pqr.size()<<endl;
			p[vp] = pqr;
	}
}

void desk(map<vector<vector<int>>, vector<vector<pair<int, int>>>> &p)
{
	addnm(p, 2, 2);
	addnm(p, 3, 2);
	addnm(p, 2, 3);
	addnm(p, 3, 3);
}

void
tq(vector<vector<int>> &m, int x1, int y1, int x2, int y2, map<vector<vector<int>>, vector<vector<pair<int, int>>>> &p,
   vector<vector<int>> &ans)
{
	vector<vector<int>> ma(x2 - x1, vi(y2 - y1));
	for (int i = x1; i < x2; i++)
		for (int j = y1; j < y2; j++)
			ma[i - x1][j - y1] = m[i][j];

	vector<vector<pair<int, int>>> fq = p[ma];
	for (auto vec:fq)
	{
		vector<int> p1;
		for (auto q:vec)
		{
			p1.pb(q.first + x1 + 1);
			p1.pb(q.second + y1 + 1);
		}
		ans.pb(p1);
	}
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	map<vector<vector<int>>, vector<vector<pair<int, int>>>> p;
	desk(p);
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int n, m;
		cin >> n >> m;
		vector<int> xes, yes;
		for (int i = 0; i <= n - 2; i += 2)
			xes.pb(i);
		xes.pb(n);
		for (int i = 0; i <= m - 2; i += 2)
			yes.pb(i);
		yes.pb(m);
		vector<vector<int>> ans;
		vvi matr(n, vi(m));
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < m; j++)
				if (s[j] == '1')
					matr[i][j] = 1;
		}
		for (int i = 0; i < xes.size() - 1; i++)
			for (int j = 0; j < yes.size() - 1; j++)
				tq(matr, xes[i], yes[j], xes[i + 1], yes[j + 1], p, ans);
		vvi mcheck(n, vi(m));
		for (auto v:ans)
		{
			for (int i=0; i<6; i+=2)
				mcheck[v[i]-1][v[i+1]-1]^=1;
		}
	//	outp2(mcheck, "CH");
		cout << ans.size() << '\n';
		for (auto v:ans)
		{
			for (auto pj:v)
				cout << pj << ' ';
			cout << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tests = 1;
	//cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		solve();
	}
}