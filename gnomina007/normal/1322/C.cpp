#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:256000000")
#pragma GCC optimize("O3")
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
#include<ctime>
 
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
 
int mod = 1000000007;
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
	return(x > y) ? gcd(y, x) : gcd(y%x, x);
}
std::mt19937 generator(25428);
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++)
	{
		int n, m;
		cin >> n >> m;
		vl nums(n);
		for (int i = 0; i < n; i++)cin >> nums[i];
		vl hashes(n);
		vl randleft(n);
		for (int i = 0; i < n; i++)
		{
			randleft[i] = (long long)generator() * 1LL * (1 << 30) + generator();
	//		cerr << randleft[i] << endl;
		}
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			hashes[y-1] ^= randleft[x - 1];
		}
		vpll prs(n);
		for (int i = 0; i < n; i++)prs[i] = mp(hashes[i], nums[i]);
		ll val = 0, cur=0;
		sort(prs.begin(), prs.end());
		for (int i = 0; i < n; i++)
		{
		//	cerr << prs[i].first<<' '<<prs[i].second << endl;
			if ((i == 0) || prs[i].first == prs[i - 1].first)cur+=prs[i].second;
			else
			{
				if (prs[i - 1].first != 0)
				{
					val = gcd(cur, val);
				}
				cur = prs[i].second;
			}
		}
	//	cerr << cur << endl;
		val = gcd(cur, val);
		cout << val << '\n';
	}
}
int main()
{
    
	ios::sync_with_stdio(false);
	cin.tie(0);
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}