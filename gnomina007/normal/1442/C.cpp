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

//bnd -  
vector<int> bfs_dists(vector<vector<pair<int, int>>> &gr, int start, int bnd)
{
	vector<int> dists(gr.size(), -1);
	vector<pair<int, int>> cands(2 * bnd + 2);
	//rb -  ,  - 
	int lb = bnd, rb = bnd + 1;
	cands[lb] = {start, 0};
	while (lb < rb)
	{
		pair<int, int> vert = cands[lb];
		lb++;
		//	cerr << vert.first << ' ' << vert.second << endl;
		if (dists[vert.first] == -1)
		{
			dists[vert.first] = vert.second;
			for (auto v:gr[vert.first])
			{
				if (dists[v.first] == -1)
				{
					if (v.second == 0)
					{
						//					cerr << "Here " << v.first << endl;
						lb--;
						cands[lb] = {v.first, vert.second};
					}
					else
					{
						//	cerr << "There" << ' ' << v.first << endl;
						rb++;
						cands[rb - 1] = {v.first, vert.second + 1};
					}
				}
			}
		}
	}
	return dists;
}

ll inf = 1e18;

vector<ll> dijk(vector<vector<pair<int, ll>>> &gr, int start)// gr , ,  pq !
{
	priority_queue<pair<ll, int>> pq;//   !!!!!
	vector<ll> dists(gr.size(), -1);
	pq.push({0, start});
	while (!pq.empty())
	{
		pair<ll, int> top = pq.top();
		pq.pop();
		if (dists[top.second] == -1)
		{
			int v = top.second;
			dists[v] = -top.first;
			//	cerr<<v<<' '<<dists[v]<<endl;
			for (auto e:gr[v])
			{
				pq.push({-e.second - dists[v], e.first});
			}
		}
	}
	return dists;
}

int TIMES = 22;

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		edges.push_back({x, y});
	}
	vector<vector<pair<int, int>>> smal(TIMES * n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < TIMES; j++)
		{
			if (j % 2 == 0)
				smal[edges[i].first + j * n].push_back({edges[i].second + j * n, 1});
			else
				smal[edges[i].second + j * n].push_back({edges[i].first + j * n, 1});
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < TIMES - 1; j++)
		{
			smal[i + j * n].push_back({i + (j + 1) * n, 0});
		}
	}
	ll cr = inf;
	vector<int> dists = bfs_dists(smal, 0, m * TIMES + n * TIMES + 2);
	for (int j = 0; j < TIMES; j++)
	{
		if (dists[n * j + n - 1] != -1)
		{
			ll val = dists[n * j + n - 1] - 1;
			val += (1 << j);
			cr = min(cr, val);
		}
	}
	//assert(cr!=inf);
	if (cr != inf)
	{
		cout << cr << endl;
		exit(0);
	}
	vector<vector<pair<int, ll>>> biggy(2 * n);
	ll CON = 1e7;
	for (int i = 0; i < m; i++)
	{
		biggy[edges[i].first].push_back({edges[i].second, 1});
	}
	for (int i = 0; i < m; i++)
	{
		biggy[edges[i].second + n].push_back({edges[i].first + n, 1});
	}
	for (int i = 0; i < n; i++)
	{
		biggy[i].push_back({i + n, CON});
	}
	for (int i = 0; i < n; i++)
	{
		biggy[i + n].push_back({i, CON});
	}
	vector<ll> dst = dijk(biggy, 0);
	if (dst[2 * n - 1] < dst[n - 1])
		dst[n - 1] = dst[2 * n - 1];
	ll tim = dst[n - 1] / CON, dif = dst[n - 1] % CON;
	int a = 1;
	for (int i = 0; i < tim; i++)
		a = mlt(a, 2);
	a = sum(a, mod - 1);
	a = sum(a, dif);
	cout << a << endl;
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