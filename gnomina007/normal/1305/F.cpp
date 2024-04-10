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
int bound = 20, inf =9999999;
ll ch(ll div, vl &checked, vl &a)
{
	for (int i = 0; i < checked.size(); i++)
	{
		if (div == checked[i])
		{
			return (ll)inf;
		}
	}
	ll val = 0;
	for (int i = 0; i < a.size(); i++)
	{
		ll df = a[i] % div;
		if(a[i]>df)	val += min(df, div - df);
		else val += div - df;
	}
	return val;
}
ll tr(ll x, vl &checked, vl &a)
{
//	cerr << x << endl;
	if (x > 0)
	{
		ll curx = x;
		vl dec;
		for (ll y = 2; y*y <= curx; y++)
		{
			while (curx%y == 0)
			{
				dec.pb(y);
				curx /= y;
			}
		}
		if (curx > 1)
		{
			dec.pb(curx);
		}
		ll cm = (ll)inf;
		for (int i = 0; i < dec.size(); i++)
		{
			cm = min(cm, ch(dec[i], checked, a));
		}
		return cm;
	}
	else return inf;
}

std::mt19937 generator(228);
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	vl a, checked;
	ll cans = 0, cmn = inf;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
	//	x = rand() % inf+700000000000;
		a.pb(x);
	}
	ld cl = (ld)clock() / (ld)CLOCKS_PER_SEC;
	while((ld)clock() / (ld)CLOCKS_PER_SEC-cl<2.0)
	{
	//	cerr << step << endl;
		int pos = generator() % a.size();
		cmn = min(cmn, tr(a[pos], checked, a));
	//	cerr << "111" << endl;
//		cerr << a[pos] <<' '<< cmn << endl;
		cmn = min(cmn, tr(a[pos]-1, checked, a));
	//	cerr << a[pos]-1 << ' '<<cmn << endl;
		cmn = min(cmn, tr(a[pos]+1, checked, a));
	//	cerr << a[pos]+1 << ' '<<cmn << endl;
	}
	cout << cans + cmn << endl;
}
int main()
{
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}