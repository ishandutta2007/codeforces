#include <bits/stdc++.h>

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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 411;
    
int n, m, a, b;
int g[MAXN][MAXN], dist[MAXN];    
queue<int> q;

void bfs() {
	forn(i, n)
		dist[i] = INF;
	dist[0] = 0;
	q.push(0);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (int w = 0; w < n; w++) {
			if (g[v][w] && dist[w] > dist[v] + 1) {
				dist[w] = dist[v] + 1;
				q.push(w);
			}
		}
	}
}

int main() {

	scanf("%d%d", &n, &m);
	forn(i, m) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a][b] = g[b][a] = 1;	
	}
	
	if (g[0][n - 1] == 1) {
		forn(i, n)
			forn(j, n)
				if (i != j)
					g[i][j] ^= 1;	
	}
	
	bfs();
	int ans = max(1, dist[n - 1]);
	cout << (ans == INF ? -1 : ans);
	
	return 0;
}