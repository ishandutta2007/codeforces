#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>

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
typedef vector<vector<int>>vvi;
typedef vector<vector<ll>>vvl;
typedef vector< pair<ll, ll>>vpll;
typedef vector< pair<ld, ld>>vpld;
typedef pair<ld, ld>pld;
#define mp make_pair
#define pb push_back

const int mod = 998244353;
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
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vi a(n);
	vvi ibits(31);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j <= 30; j++)
		{
			if (ibit(a[i], j))
			{
				ibits[j].pb(i);
			}
		}
	}
	int cur = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (ibits[i].size() == 1)
		{
			cur = ibits[i][0];
			break;
		}
	}
	cout << a[cur] << ' ';
	for (int i = 0; i < n; i++)
	{
		if (i != cur)
		{
			cout <<a[i] << ' ';
		}
	}
}
int main()
{
	solve();
	int n;
	cin >> n;
}