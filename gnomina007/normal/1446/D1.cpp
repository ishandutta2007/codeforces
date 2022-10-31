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

int big_check(vector<int> &v, vector<vector<int>> &cols, int mx, int cand)
{
	if (mx == cand)
		return 0;
	int n = v.size();
	vector<int> mxbal(n + 1, -1), mnbal(n + 1, -1);
	int bal = 0;
	mnbal[0] = 0;
	mxbal[0] = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] == mx)
			bal++;
		if (v[i] == cand)
			bal--;
		if (bal >= 0)
		{
			if (mnbal[bal] == -1)
				mnbal[bal] = i + 1;
			mxbal[bal] = i + 1;
		}
	}
	int cr = 0;
	for (int i = 0; i <= n; i++)
		if (mnbal[i] != -1)
			cr = max(cr, mxbal[i] - mnbal[i]);
	return cr;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<vector<int>> cols(n + 1);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
		cols[x].pb(i);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		if (cols[i].size() > cols[mx].size())
			mx = i;
	int curr=0;
	for (int i = 0; i < cols.size(); i++)
	{
		if (cols[i].size() != 0)
			curr=max(curr, big_check(v, cols, mx, i));
	}
	cout<<curr<<'\n';
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