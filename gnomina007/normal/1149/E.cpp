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

int inf = 1e9 + 110;

void reverse(vector<vector<int>> &v, vi &sign, ll &sumx, ll &sumy, int pos, vector<int> &init)
{
	//cerr<<pos<<' '<<sumx<<' '<<sumy<<endl;
//	cerr<<v[pos][0]<<' '<<v[pos][1]<<' '<<v[pos][2]<<'\n';
	//cerr<<"here "<<endl;
	if (sumx <= 1e6 + 1 && sumx >= -1e6 - 2)
		if (sumy <= 1e6 + 1 && sumy >= -1e6 - 2)
		{
			vector<int> reals(v.size());
			for (int i = 0; i < v.size(); i++)
			{
				reals[v[i][2]] = sign[i];
			}
			for (int i = 0; i < v.size(); i++)
				cout << reals[i] * init[i] << ' ';
			cout << '\n';
			exit(0);
		}
	if (sign[pos] == 1)
	{
		sign[pos] = -1;
		sumx -= 2 * v[pos][0];
		sumy -= 2 * v[pos][1];
	}
	else
	{
		sign[pos] = 1;
		sumx += 2 * v[pos][0];
		sumy += 2 * v[pos][1];
	}
	if (sumx <= 1e6 + 2 && sumx >= -1e6 - 2)
		if (sumy <= 1e6 + 2 && sumy >= -1e6 - 2)
		{
			vector<int> reals(v.size());
			for (int i = 0; i < v.size(); i++)
			{
				reals[v[i][2]] = sign[i];
			}
			for (int i = 0; i < v.size(); i++)
				cout << reals[i] * init[i] << ' ';
			cout << '\n';
			exit(0);
		}
}

int mexx(vector<int>&v)
{
	vector<int>u(v.size()+2);
	for(auto it:v)
	{
		if(it<u.size())
			u[it]=1;
	}
	for(int i=0; i<u.size(); i++)
		if(u[i]==0)
			return i;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;
	cin>>n>>m;
	vvi gr(n), revgr(n);
	vector<int>grundy(n,-1), degs(n);
	vector<ll>vals(n);
	for(int i=0; i<n; i++)
		cin>>vals[i];
	set<int> zerodeg;
	for(int i=0; i<m; i++)
	{
		int x, y;
		cin>>x>>y;
		x--;
		y--;
		degs[x]++;
		gr[x].pb(y);
		revgr[y].pb(x);
	}
	for(int i=0; i<n; i++)
		if(!degs[i])
			zerodeg.insert(i);
//	cerr<<"Here"<<endl;
	while(!zerodeg.empty())
	{
		int a=*zerodeg.begin();
		vi v;
		for(auto g:gr[a])
			v.pb(grundy[g]);
		grundy[a]=mexx(v);
		for(auto g:revgr[a])
		{
			degs[g]--;
			if(degs[g]==0)
			zerodeg.insert(g);
		}
		zerodeg.erase(a);
	}
	vector<int>xors(n+1);
	vector<vector<int>>verts(n+1);
	for(int i=0; i<n; i++)
	{
		xors[grundy[i]]^=vals[i];
		verts[grundy[i]].pb(i);
	}
	int pos=-1;
	for(int i=n; i>=0; i--)
		if(xors[i]!=0)
		{
			pos=i;
			break;
		}
	if(pos==-1)
		cout<<"LOSE"<<'\n';
	else{
		int p1=-1;
		for(auto ver:verts[pos])
		{
			//cerr<<vals[ver]<<' '<<xors[pos]<<endl;
			ll need = vals[ver]^xors[pos];
			if(need<vals[ver])
			{
				p1=ver;
				break;
			}
		}
	//	cerr<<p1<<endl;
		assert(p1!=-1);
		cout<<"WIN"<<'\n';
		vals[p1]=vals[p1]^xors[pos];
		for(auto ver:gr[p1])
		{
			int cal=grundy[ver];
			vals[ver]=xors[cal]^vals[ver];
			xors[cal]=0;
		}
		for(auto it:vals)
			cout<<it<<' ';
		cout<<'\n';
	}
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