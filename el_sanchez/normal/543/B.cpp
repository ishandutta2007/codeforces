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

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;        
const int MAXN = 3111;

int n, m, v, w, ans, cur[2];
int s[2], t[2], l[2];
vi g[MAXN];
int dist[MAXN][MAXN];
int used[MAXN];
queue<int> q;

void bfs(int v) {
	memset(used, 0, sizeof(used));
	forn(i, n)
		dist[v][i] = INF;
	dist[v][v] = 0;
	q.push(v);
	used[v] = 1;
	
	while (!q.empty()) {
		w = q.front();
		q.pop();	
		
		for (auto z: g[w]) {
			if (!used[z]) {
				dist[v][z] = dist[v][w] + 1;
				q.push(z);
				used[z] = 1;
			}
		}		}
}

int main() {

	cin >> n >> m;
	forn(i, m) {
		scanf("%d%d", &v, &w);
		v--, w--;
		g[v].pb(w);
		g[w].pb(v);	
	}
	forn(i, 2) {
		cin >> s[i] >> t[i] >> l[i];
		s[i]--, t[i]--;	
	}
	
	forn(i, n)
		bfs(i);

	ans = dist[s[0]][t[0]] + dist[s[1]][t[1]];
	if (dist[s[0]][t[0]] > l[0] || dist[s[1]][t[1]] > l[1]) {
		cout << -1;
		return 0;
	}
	
	forn(v, n)
		forn(w, n) {
			bool f = 1;
			forn(i, 2) {
				cur[i] = dist[s[i]][v] + dist[v][w] + dist[w][t[i]];
				if (cur[i] > l[i])
					f = 0;
			}
			
			if (f)
				ans = min(ans, cur[0] + cur[1] - dist[v][w]);		
			
			f = 1;
			forn(i, 2) {
				if (i == 0)
					cur[i] = dist[s[i]][v] + dist[v][w] + dist[w][t[i]];
				else
					cur[i] = dist[s[i]][w] + dist[w][v] + dist[v][t[i]];
				
				if (cur[i] > l[i])
					f = 0;
			}
			
			if (f)
				ans = min(ans, cur[0] + cur[1] - dist[v][w]);		
		}   			
		
	ans = m - ans;
	cout << ans;
	
	return 0;
}