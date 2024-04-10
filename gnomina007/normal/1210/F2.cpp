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
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
 
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
 
const int rsto = bp(100, mod - 2);
 
void recalc(map<vector<int>, int> &dyn, const vector<int> &probs, int t, vector<vvi> &trans)
{
	vector<int> goodsz;
	map<vector<int>, int> newdyn;
	int n = probs.size();
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (ibit(mask, i))
				cnt++;
		if (cnt == t)
			goodsz.pb(mask);
	}
//	outp1(goodsz, "GOODSZ ");
	for (int mask = 0; mask < (1 << n); mask++)
	{
		//cerr << "MASK " << mask << endl;
		int prb = 1;
		vector<int> added;
		for (int i = 0; i < n; i++)
		{
			if (ibit(mask, i))
			{
				added.pb(i);
				prb = mlt(prb, probs[i]);
			}
			else
				prb = mlt(prb, mod + 1 - probs[i]);
		}
		for (auto it = dyn.begin(); it != dyn.end(); it++)
		{
			vector<int> va = it->first;
			vector<int> used(trans[t + 1].size());
			for (int i = 0; i < va.size(); i++)
			{
				if (va[i])
				{
					for (auto pos:added)
					{
						int val=trans[t][i][pos];
						if (val!= -1)
							used[val] = 1;
					}
				}
			}
			if (!newdyn.count(used))
				newdyn[used] = mlt(prb, it->second);
			else
				newdyn[used] = sum(newdyn[used], mlt(prb, it->second));
		}
	}
	dyn = newdyn;
}
 
vector<vector<int>> enc;
vector<vector<vector<int>>> trans;
 
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	enc.resize(n + 1);
	trans.resize(n + 1);
//	cout<<clock()/(ld)CLOCKS_PER_SEC<<endl;
	vector<vector<int>> v(n, vi(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i][j] = mlt(v[i][j], rsto);
	for (int mask = 0; mask < (1 << n); mask++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (ibit(mask, i))
				cnt++;
		enc[cnt].push_back(mask);
	}
	for (int i = 0; i <= n; i++)
	{
		trans[i].resize(enc[i].size());
		for (int pos = 0; pos < enc[i].size(); pos++)
		{
			int j = enc[i][pos];
			for (int h = 0; h < n; h++)
			{
				if (ibit(j, h))
					trans[i][pos].pb(-1);
				else
				{
					int val = j + (1 << h);
					for (int q = 0; q < enc[i + 1].size(); q++)
					{
						if (enc[i + 1][q] == val)
						{
							trans[i][pos].pb(q);
						}
					}
				}
			}
		}
	}
	map<vector<int>, int> dyn;
	vector<int> q = {1};
	dyn[q] = 1;
	for (int i = 0; i < n; i++)
		recalc(dyn, v[i], i, trans);
	vector<int> vt = {1};
	cout << dyn[vt] << '\n';
//	cout<<clock()/(ld)CLOCKS_PER_SEC<<endl;
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