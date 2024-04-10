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

ld solveused(int h)// 1- n
{
	ld val = 1.0;
	for (int i = 1; i < h; i++)
		val /= (2.0);
	return 1.0 - val;
}

//
ld solvefreewithoutroot(int h)// ,    =h,     1- n
{
	ld val = 1.0;
	for (int i = 1; i <= h; i++)
	{
		ld prob = 1.0 / (i * (i + 1));
		for (int j = 1; j < i; j++)
			prob /= 2.0;
		val -= prob;
	}
	return val;
}

ld solvefreefatheronlvl(int h)// ,     1- n  h
{
	ld val = 1.0;
	for (int i = 1; i < h; i++)
	{
		ld prob = 1.0 / (i * (i + 1));
		for (int j = 1; j < i; j++)
			prob /= 2.0;
		val -= prob;
	}
	ld pb = 1.0 / h;
	for (int i = 1; i < h; i++)
		pb /= 2.0;
	val -= pb;
	return val;
}

int con = 500;

void ins(vector<int> &v, int x)
{
	vector<int> v1 = v;
	for (int i = x; i < v1.size(); i++)
		v1[i] = sum(v1[i], v1[i - x]);
	v = v1;
}

void div(vector<int> &v, int x)
{
	vector<int> v1 = v;
	for (int i = x; i < v1.size(); i++)
		v1[i] = dif(v1[i], v[i - x]);
	v = v1;
}

int biggy(int n, int m)
{
	vector<int> nums;
	nums.pb(n);
	int cur = 0;
	for (int i = 1; i < con; i++)
	{
		cur += i;
		nums.pb(cur);
		nums.pb(cur);
	}
	vector<int> anses(m + 1);
	anses[0] = 1;
	for (auto x:nums)
		ins(anses, x);
	return anses[m];
}

int smally(int n, int m)
{
	vector<int> nums(m + 1);
	nums[0] = 1;
	vector<int> vl, vr;
	int cur = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		cur += i;
		vr.pb(cur);
	}
	cur = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		cur += i;
		vl.pb(cur);
	}
	//outp1(nums, "NUMs");
	ins(nums, n);
	//outp1(nums, "NUMS");
	for (auto it:vr)
	{
		//	cerr<<"itt"<<' '<<it<<endl;
		ins(nums, it);
	}
//	outp1(nums, "NUMS");
	int ans = 0;
	cur = m;
	for (int j = 0; j < n; j++)
	{
		if (cur >= 0)
			ans = sum(ans, nums[cur]);
		if (j < n - 1)
			ins(nums, vl[j]);
		div(nums, vr.back());
		//	outp1(nums, "NUMS");
		vr.pop_back();
		cur -= (j + 1);
	}
	return ans;
}

int inf = 1e9 + 10;

int dp(vector<int> &v, int lb, int rb, int bit)
{
//	cerr << "DPSTART " << lb << ' ' << rb << ' ' << bit << endl;
	if (bit == -1)
		return 1;
	int cofn = 1 << bit;
	int pos = -1;
	for (int i = lb; i < rb; i++)
	{
		if (v[i] < cofn)
			pos = i;
	}
	if (pos == rb - 1)
	{
		int vp = dp(v, lb, rb, bit - 1);
		//cerr << "DPEND " << lb << ' ' << rb << ' ' << bit << endl;
	//	cerr << vp << endl;
		return vp;
	}
	if (pos == -1)
	{
		for (int i = lb; i < rb; i++)
			v[i] -= cofn;
		int vp = dp(v, lb, rb, bit - 1);
		//cerr << "DPEND " << lb << ' ' << rb << ' ' << bit << endl;
	//	cerr << vp << endl;
		return vp;
	}
	int vp = max(dp(v, lb, pos + 1, bit), dp(v, pos + 1, rb, bit)) + 1;
//	cerr << "DPEND " << lb << ' ' << rb << ' ' << bit << endl;
	//cerr<<vp<<endl;
	return vp;
}

int BIT = 30;

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << n-dp(v, 0, n, BIT) << '\n';
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