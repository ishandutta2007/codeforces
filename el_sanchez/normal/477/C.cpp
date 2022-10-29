#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;        
const int MAXN = 2222;
const ll MOD = 1E9 + 7;
  
struct query {
	int l, r, id, cost;
	
	query() {};
	query(int l, int r, int id, int cost): l(l), r(r), id(id), cost(cost) {};
};

bool operator<(query a, query b) {
	if (a.l != b.l)
		return a.l < b.l;
	return a.r < b.r;
}

int n, m, ansid;
int strings, chars;
int dp[MAXN][MAXN], nxt[MAXN], mincost[MAXN];
string s, p;
vector<query> q;
vi costs;
vi res;

int main() {

	cin >> s;
	cin >> p;
	n = s.size();
	m = p.size();

	for (int i = 0; i < n; i++) {
		int pos = 0;
		int j = i;
		while (j < n && pos < m) {
			if (s[j] == p[pos])
				pos++;
			j++;	
		}	
		
		if (pos == m) {
			j--;
			q.pb(query(i, j, i, j - i + 1 - m));
			//cout << i << ' ' << q.back().cost << '\n';	
		}
	}
	
	sort(all(q));
	for (int i = 0; i < (int)q.size(); i++) {
		nxt[i] = i + 1;
		while (nxt[i] < (int)q.size() && q[i].r >= q[nxt[i]].l)
			nxt[i]++;	
	}
	
	forn(i, q.size() + 1)
		forn(j, n + 1)
			dp[i][j] = INF;
	dp[0][0] = 0;
			
	for (int i = 0; i < (int)q.size(); i++) {
		for (int j = 0; j <= n; j++) {
		    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if (dp[i][j] == INF)
				continue;
			dp[nxt[i]][j + 1] = min(dp[nxt[i]][j + 1], dp[i][j] + q[i].cost);
		}
		//cout << '\n';
	}
	
	forn(i, n + 1) {
		mincost[i] = INF;
		forn(j, q.size() + 1)
			mincost[i] = min(mincost[i], dp[j][i]);	
		//cout << mincost[i] << '\n';
	}
			
	res.resize(n + 1, 0);
	
	for (int i = 0; i <= n; i++) {
		if (mincost[i] == INF)
			continue;

		for (int j = mincost[i]; j <= n - i * m; j++)
			res[j] = max(res[j], i);	
	}
	
	forn(i, n + 1)
		cout << res[i] << ' ';
		
	return 0;
}