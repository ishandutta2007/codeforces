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


int solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, k, ans = 1;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> b(k);
	map<int, int> used;
	vector<int> inv(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		inv[a[i]] = i;
		used[i] = 0;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> b[i];
		b[i]--;
		b[i] = inv[b[i]];
//		cerr << b[i] << ' ';
		used[b[i]]++;
	}
	for (int i = 0; i < k; i++)
	{
	//	cerr << i << endl;
	/*	for (auto it = used.begin(); it != used.end(); it++)
		{
			cerr << it->first << ' ' << it->second << endl;
		}*/
		auto it = used.find(b[i]);
		int cp = 0;
		if (it != used.begin())
		{
			if (!(--it)->second)
				cp++;
			it++;
		}
		if ((++it) != used.end())
		{
			if (!(it->second))
				cp++;
		}
		it--;
		//	cerr<<"Here"<<' '<<i<<' '<<cp<<endl;
		used.erase(it->first);
		ans = mlt(ans, cp);
	}
	return ans;
}

int main()
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
		cout << solve() << endl;
	int n;
	cin>>n;
}