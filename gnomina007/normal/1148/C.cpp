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

void outp1(vi &ou, string s = " ")
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

int inf = 1e9 + 110;

void swp(vector<pair<int, int>>&swaps, vector<int>&p, int a, int b, vector<int>&pinv)
{
	swaps.pb({a, b});
	int x=p[a];
	p[a]=p[b];
	p[b]=x;
	pinv[p[a]]=a;
	pinv[p[b]]=b;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin>>n;
	vector<int>p(n), pinv(n);
	for(int i=0; i<n; i++)
	{
		cin >> (p[i]);
		p[i]--;
		pinv[p[i]]=i;
	}
	vector<int> order(n);
	for(int i=0; i<n; i++)
	{
		if(!(i%2))
			order[i]=n/2-i/2-1;
		else
			order[i]=n/2+i/2;
	}
//	cerr<<"sds "<<order[2]<<' '<<order[3]<<endl;
	vector<pair<int, int>>swaps;
	for(int i=0; i<n-2; i++)
	{
	//	cerr<<i<<' '<<order[i]<<endl;
	//	outp1(p, "perm ");
	//	outp1(pinv, "pinv ");
		int pos=pinv[order[i]];
		if(pos<n/2)
		{
			swp(swaps, p,pos, n-1, pinv);
			if(order[i]<n/2)
				swp(swaps, p,order[i], n-1, pinv);
			else
			{
				swp(swaps, p,0, n-1, pinv);
				swp(swaps, p,order[i], 0, pinv);
			}
		}
		else
		{
			swp(swaps, p,pos, 0, pinv);
			if(order[i]>=n/2)
				swp(swaps, p,order[i], 0, pinv);
			else
			{
				swp(swaps, p,0, n-1, pinv);
				swp(swaps, p,order[i], n-1, pinv);
			}
		}
	}
	if(p[0]!=0)
		swp(swaps, p, 0, n-1, pinv);
//	outp1(p, "perm" );
	cout<<swaps.size()<<endl;
	for(auto pr:swaps)
		cout<<pr.first+1<<' '<<pr.second+1<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tests = 1;
	//cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
}