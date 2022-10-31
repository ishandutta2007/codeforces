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

int mod=998244353;
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
vi getdyst(int from, vii &gr)
{
	vi used(gr.size()), dists(gr.size(), -1);
	queue<int> q;
	q.push(from);
	dists[from] = 0;
	used[from] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		for (int i = 0; i < gr[cur].size(); i++)
		{
			int nxt = gr[cur][i];
			if (!used[nxt])
			{
				used[nxt] = 1;
				q.push(nxt);
				dists[nxt] = dists[cur] + 1;
			}
		}
		q.pop();
	}
	return dists;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n, m, k;
	cin >> n >> m >> k;
	vi intr(k);
	for (int i = 0; i < k; i++)cin >> intr[i];
	vii gr(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	vi d1 = getdyst(0, gr), d2 = getdyst(n - 1, gr);
	int ans = d1[n - 1], curmax=-1;
	vpi md(k);
	//cerr << endl;
	for (int i = 0; i < n; i++)
	{
	//	cerr << d1[i] << ' ' << d2[i] << endl;
	}
	for (int i = 0; i < k; i++)md[i] = mp(d1[intr[i]-1] - d2[intr[i]-1], d2[intr[i]-1]);
	sort(md.begin(), md.end());
	vi sufmax(k);
	for (int i = k - 2; i >= 0; i--)
	{
		sufmax[i] = max(sufmax[i + 1],  md[i + 1].second);
	}
	for (int i = 0; i < k- 1; i++)
	{
		curmax = max(curmax, md[i].second +md[i].first+ sufmax[i]+1);
	//	cerr << curmax << endl;
	}
	//cerr << curmax << endl;
	curmax=min(curmax, ans);
	cout << curmax << endl;
}
int main()
{
	//prec();
	//cerr << "Here" << endl;
	solve();
	int n;
	cin >> n;
}