#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>

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
bool isg(pll p1, pll p2, pll p3)
{
	ll p11 = p1.first - p3.first, p21 = p1.second - p3.second;
	ll p12 = p2.first - p3.first, p22 = p2.second - p3.second;
	//cout << (p11*p22 - p21 * p12) << endl;
	return (p11*p22 >=p21*p12);
}
vpll lowest_hull(vpll points)
{
	vpll cur_hull;
	pll zero = mp(0, 0);
	cur_hull.pb(zero);
	for (int i = 0; i < points.size(); i++)
	{
		int sz = cur_hull.size();
		cur_hull.pb(points[i]);
		if (i == 1)
		{
		//	cout << "sdsd " << isg(cur_hull[sz - 1], cur_hull[sz]) <<' '<<cur_hull[sz-1].first<<' '<< cur_hull[sz - 1].second<<' '<< cur_hull[sz].first << ' ' << cur_hull[sz].second<<endl;
		}
		while ((sz>=2)&&!isg(cur_hull[sz - 1], cur_hull[sz], cur_hull[sz-2]))
		{
			cur_hull.pop_back();
			cur_hull.pop_back();
			cur_hull.pb(points[i]);
			sz = cur_hull.size()-1;
		}
	}
	return cur_hull;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{

	int n;
	cin >> n;
	vpll points;
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		sum += x;
		points.pb(mp(i + 1, sum));
	}
	vpll ch = lowest_hull(points);
	for (int i = 1; i < ch.size(); i++)
	{
		//cout << ch[i].first << ' '<< ch[i].second << endl;
		ld val = (ch[i].second - ch[i - 1].second)*1.0 / (ch[i].first - ch[i - 1].first);
		for (int j = 0; j < ch[i].first - ch[i - 1].first; j++)
		{
cout.precision(15);
			cout << val <<'\n';
		}
	}
//	cout << endl;

}
int main()
{
	solve();
	int n;
	cin >> n;
}