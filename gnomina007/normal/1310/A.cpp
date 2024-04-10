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

int mod=998244353;
const int bound = 2021;
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
	return(x > y) ?  gcd(y, x) : gcd(y%x, x);
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vpi inp(n);
	vi x(n), y(n);
	for (int i = 0; i < n; i++)cin >> x[i];
	for (int i = 0; i < n; i++)cin >> y[i];
	for (int i = 0; i < n; i++)inp[i]=mp(y[i],x[i]);
	sort(inp.begin(), inp.end());
	reverse(inp.begin(), inp.end());
	set<pair<int, int>>segs;
	ll ans = 0;
	set<pair<int,int>>::iterator iit, it;
	for (int i = 0; i < n; i++)
	{
	/*	cerr << "Here" <<' '<<i<< endl;
		for (it = segs.begin(); it != segs.end(); it++)
		{
			cerr << (*it).second << ' ' << (*it).first << endl;
		}
		cerr << endl;*/
		int x = inp[i].second;
		pair<int,int> pra = mp(x+1, -1);
		it = segs.lower_bound(pra);
		pii sg = *it;
		pra = mp(x + 1, x);
		if (it == segs.end())
		{
			pii pra1 = mp(x, -1);
			iit = segs.lower_bound(pra1);
			if (iit != segs.end())
			{
				pii sg1 = *iit;
				segs.erase(sg1);
				pra = mp(x + 1, sg1.second);
				segs.insert(pra);
			}
			else
			{
				segs.insert(pra);
			}
		}
		else
		{
			if (sg.second > x)
			{
				if (sg.second == x + 1)
				{
					segs.erase(sg);
					pra = mp(sg.first, x);
				}
				pii hz = mp(x, -1);
				it = segs.lower_bound(hz);
				pii sg1 = *it;
				if (sg1.first == x)
				{
					segs.erase(sg1);
					pra = mp(pra.first, sg1.second);
				}
				segs.insert(pra);
			}
			else
			{
				ans += (ll)inp[i].first * 1LL * (ll)(sg.first - x);
				pra = mp(sg.first + 1, sg.second);
				pii prr = mp(pra.first, pra.first + 1);
				it = segs.lower_bound(prr);
				segs.erase(sg);
				pii sg1 = *it;
				if (sg1.second == pra.first)
				{
					pra = mp(sg1.first, pra.second);
					segs.erase(sg1);
				}
				segs.insert(pra);
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}