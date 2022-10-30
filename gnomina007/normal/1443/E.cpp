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

using namespace std;

int mod = 998244353;
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

void outp1(vi &ou, string s)
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		cerr << ou[i] << ' ';
	}
	cerr << endl;
}

void outp2(vector<vector<ll>> &ou, string s)
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

vector<int> nth(int n1, ll x)
{
	vector<int> coefs(n1);
	ll fact = 1, cur = x;
	for (int i = 1; i < n1; i++)
		fact *= i;
	for (int pos = 0; pos < n1; pos++)
	{
		coefs[pos] = cur / fact;
		cur %= fact;
		if (pos != n1 - 1)
			fact /= (n1 - 1 - pos);
	}
	vector<int> perm(n1+1), used(n1+1);
	for (int pos = 0; pos <n1; pos++)
	{
		int p = 0, curr = -1;
		//cerr<<"123 "<<coefs[pos]<<endl;
		while (curr < coefs[pos])
		{
			p++;
			if (!used[p])
				curr++;
		}
		perm[pos] = p;
		used[p]++;
	}
	perm.pop_back();
	return perm;
}


ll calc(vector<int> &perm, int n, int n1, int l)
{
	if (l > n)
		return n * 1LL * (n + 1) / 2;
	if (l <= n - n1 + 1)
		return l * 1LL * (l - 1) / 2;
	else
	{
		ll val = (n - n1) * 1LL * (n - n1 + 1) / 2;
		for (int c = n - n1 + 1; c < l; c++)
		{
			val += (n - n1) + perm[c-n+n1-1];
		}
		return val;
	}
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, q, n1;
	cin >> n >> q;
	n1 = 15;
	if (n < n1)
		n1 = n;
	ll add = 0;
	for (int qe = 0; qe < q; qe++)
	{
		int type;
		cin >> type;
		if (type == 2)
		{
			int x;
			cin >> x;
			add += x;
		}
		if (type == 1)
		{
			int l, r;
			cin >> l >> r;
			vector<int> perm = nth(n1, add);
		/*	for (int i = 0; i < perm.size(); i++)
				cerr << perm[i] << ' ';
			cerr << endl;*/
			cout << calc(perm, n, n1, r + 1) - calc(perm, n, n1, l) << endl;
		}
	}
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