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
 
ll gcd(ll a, ll b)
{
	if (b > a)
		return gcd(b, a);
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
 
void smp(vector<pair<ll, int>> &v)
{
	vector<pair<ll, int>> v1;
	for (auto w:v)
	{
		if (v1.size() > 0 && v1.back().first == w.first)
		{
			v1.pop_back();
		}
		v1.pb(w);
	}
	v = v1;
}
 
void
dfs(const vector<vector<int>> &gr, const vector<ll> &nums, vector<pair<ll, int>> &st, int v,
		vector<int> &used, int dep, ll &ans)
{
	//cerr<<v<<' '<<dep<<endl;
	/*cerr<<"Before ";
	for(int i=0; i<st.size(); i++)
		cerr<<st[i].first<<' '<<st[i].second<<endl;
	cerr<<endl;*/
	used[v] = 1;
	vector<pair<ll, int>> st1 = st;
	st1.pb({nums[v], dep});
	for (int i=0; i<st1.size(); i++)
		st1[i].first = gcd(st1[i].first, nums[v]);
	int cr=-1;
	smp(st1);
	/*cerr<<"After ";
	for(int i=0; i<st1.size(); i++)
		cerr<<st1[i].first<<' '<<st1[i].second<<endl;
	cerr<<endl;*/
	for(auto at:st1)
	{
		ans+=at.first*(at.second-cr);
		cr=at.second;
		ans%=mod;
	}
	for(auto e:gr[v])
		if(!used[e])
			dfs(gr, nums, st1, e, used, dep+1, ans);
}
 
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vector<int> used(n);
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
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
	ll ans=0;
	vector<pair<ll, int>>st;
	dfs(gr, v,st, 0, used, 0, ans);
	cout<<ans<<'\n';
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