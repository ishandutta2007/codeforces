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
std::mt19937 generator(228);
int inf = 1212121;
void dfs(int start, int cur, vii &dist, vii &gr)
{
	for (int i = 0; i < gr[cur].size(); i++)
	{
		int x = gr[cur][i];
		if (dist[start][x] == inf)
		{
			dist[start][x] = dist[start][cur] + 1;
			dfs(start,x, dist, gr);
		}
	}
}
bool newca(vii &matr, vi &cands, int i1, int i2)
{
	int gd = 0;
//	cerr << cands[i1]+1 << ' ' << cands[i2]+1 << endl;
	for (int i = 0; i < cands.size(); i++)
	{
		if (i != i1)
		{
			if (i != i2)
			{
				if ((matr[cands[i]][cands[i1]] - matr[cands[i]][cands[i2]] != matr[cands[i1]][cands[i2]])&& (matr[cands[i]][cands[i2]] - matr[cands[i]][cands[i1]] != matr[cands[i1]][cands[i2]]))return true;
			}
		}
	}
	return false;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	vi cands;
	int n;
	cin >> n;
	vii matr(n, vi(n, inf));
	for (int i = 0; i < n; i++) matr[i][i] = 0;
	vpi edges;
	vii gr(n);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		edges.pb(mp(x - 1, y - 1));
		edges.pb(mp(y - 1, x - 1));
		gr[x - 1].pb(y - 1);
		gr[y - 1].pb(x - 1);
	}
	for (int i = 0; i < n; i++)dfs(i, i, matr, gr);
	for (int i = 0; i < n; i++)cands.pb(i);
	while (cands.size() > 1)
	{
		if (cands.size() == 2)
		{
			cout <<"?"<<' '<< cands[0]+1 << ' ' << cands[1]+1 << endl;
			cout.flush();
			int pos;
			cin >> pos;
			cands = { pos-1 };
		}
		else
		{
			bool gd = false;
			int x1, x2;
			while (!gd)
			{
			//	cerr << "Here" << endl;
				x1 = generator() % cands.size();
				x2 = generator() % cands.size();
				if (x1 != x2)gd = newca(matr, cands, x1, x2);
			}
			cout << "?" << ' ' << cands[x1]+1 << ' ' << cands[x2]+1 << endl;
			cout.flush();
			x1 = cands[x1];
			x2 = cands[x2];
			int x;
			cin >> x;
			x--;
			if (x == x1)
			{
				vi newc;
				newc.pb(x1);
				for (int i = 0; i < cands.size(); i++)
				{
					int pos = cands[i];
					if (pos != x1)
					{
						if (matr[x1][x2] == (matr[pos][x2] - matr[pos][x1]))newc.pb(pos);
					}
				}
				cands = newc;
			}
			else
			{
				if (x == x2)
				{
					vi newc;
					newc.pb(x2);
					for (int i = 0; i < cands.size(); i++)
					{
						int pos = cands[i];
						if (pos != x2)
						{
							if (matr[x1][x2] == (matr[pos][x1] - matr[pos][x2]))newc.pb(pos);
						}
					}
					cands = newc;
				}
				else
				{
					vi newc;
					for (int i = 0; i < cands.size(); i++)
					{
						int pos = cands[i];
						if (pos != x2)
						{
							if (pos!=x1)newc.pb(pos);
						}
					}
					cands = newc;
				}
			}
		}
	}
	cout << "!" << ' ' << cands[0]+1 << endl;
	cout.flush();
}
int main()
{
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}