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
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	set<pld>points;
	vpld pnts;
	ld sumx=0, sumy=0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		sumx += x * 1.0;
		sumy += y * 1.0;
		points.insert(mp((ld)x, (ld)y));
		pnts.pb(mp((ld)x, (ld)y));
	}
	ld nn = n * 1.0;
	sumx /= nn;
	sumy /= nn;
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		ld nx = 2.0*sumx - pnts[i].first, ny = 2.0*sumy - pnts[i].second;
		pld pr = mp(nx, ny);
		if (points.find(pr) == points.end())
		{
			cur = 0;
			break;
		}
	}
	if (cur == 1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
int main()
{
	solve();
	int n;
	cin >> n;
}