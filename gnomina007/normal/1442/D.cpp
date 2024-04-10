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

void just_dyn(vector<ll> &vinit, vector<pair<int, ll>> &take_all, int l, int r, int sz)
{
	for (int i = l; i < r; i++)
	{
		for (int j = sz - 1; j >= take_all[i].first; j--)
		{
			vinit[j] = max(vinit[j], vinit[j - take_all[i].first] + take_all[i].second);
		}
	}
}

void rec(vector<vector<ll>> &without, vector<pair<int, ll>> &take_all,
         int l, int r, int sz, vector<ll> &vinit)// = +1
{
//	cerr<<"l, r "<<l<<' '<<r<<endl;
//	outp1(vinit, "vinit " );
	if (r - l >= 2)
	{
		int mid = (l + r) / 2;
		vector<ll> v1 = vinit;
		just_dyn(v1, take_all, l, mid, sz);
		rec(without, take_all, mid, r, sz, v1);// 1 ,  2
		v1 = vinit;
		just_dyn(v1, take_all, mid, r, sz);
		rec(without, take_all, l, mid, sz, v1);// 2 ,  1
	}
	else
	{
		without[l] = vinit;
	}
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k;
	cin >> n >> k;
	vector<vector<ll>> inp(n);
	vector<pair<int, ll>> take_all(n);
	vector<vector<ll>> dpwithout(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
		{
			ll x;
			cin >> x;
			inp[i].push_back(x);
			take_all[i].first++;
			take_all[i].second += x;
		}
	}
	vector<ll> vinit(k + 1, -inf);
	vinit[0] = 0;
	rec(dpwithout, take_all, 0, n, k + 1, vinit);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll cur = 0;
		ans = max(ans, dpwithout[i][k]);
		for (int j = 0; j < min((int) inp[i].size(), k + 2); j++)
		{
			cur += inp[i][j];
			if (j < k)
				ans = max(ans, cur + dpwithout[i][k - j - 1]);
		}
	}
	cout << ans << endl;
}

int main()
{
	int tests = 1;
	//cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
	int n;
	cin >> n;
}