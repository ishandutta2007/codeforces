#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 3111;
const int K = 3;

int n, m, a, b;
int distTo[MAXN][MAXN];
int maxTo[MAXN][K + 1], maxFrom[MAXN][K + 1];
vi g[MAXN];
queue<int> q;

void bfs(int s) {
	forn(i, n)
		distTo[s][i] = INF;

	while (!q.empty())
		q.pop();

	distTo[s][s] = 0;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (auto w: g[v]) {
			if (distTo[s][w] == INF) {
				distTo[s][w] = distTo[s][v] + 1;
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
		g[a].pb(b);	
	}
		
	forn(i, n)
		bfs(i);
		
	forn(i, n) {
		forn(k, K)
			maxTo[i][k] = i;
		forn(v, n)
			if (v != i && distTo[i][v] != INF) { 
				forn(k, K)
					if (distTo[i][v] >= distTo[i][maxTo[i][k]]) {
						//shift:
						for (int p = K - 1; p > k; p--)
							maxTo[i][p] = maxTo[i][p - 1];
						//push
						maxTo[i][k] = v;
						break;
					}
			}

		forn(k, K)
			maxFrom[i][k] = i;
		forn(v, n)
			if (v != i && distTo[v][i] != INF) { 
				forn(k, K)
					if (distTo[v][i] >= distTo[maxFrom[i][k]][i]) {
						//shift:
						for (int p = K - 1; p > k; p--)
							maxFrom[i][p] = maxFrom[i][p - 1];
						//push
						maxFrom[i][k] = v;
						break;
					}
			}
	}
	
	int ans = 0, cur = 0;
	int res[4];
	memset(res, 0, sizeof(res));
	
	int v[4];
	bool ok;
	for (v[1] = 0; v[1] < n; v[1]++) {
		for (v[2] = 0; v[2] < n; v[2]++) {
			if (v[1] != v[2] && distTo[v[1]][v[2]] != INF) {
				forn(k1, K)
					forn(k2, K) {
						v[0] = maxFrom[v[1]][k1];
						v[3] = maxTo[v[2]][k2];
						
						ok = 1;
						for (int a = 0; a < 4; a++)
							for (int b = a + 1; b < 4; b++)
								if (v[a] == v[b]) {
									ok = 0;
									break;
								}
								
						if (ok) {
							cur = 0;
							forn(i, 3)
								cur += distTo[v[i]][v[i + 1]];
								
							if (cur > ans) {
								ans = cur;
								forn(t, 4)
									res[t] = v[t];
							}
						}
					}
			}
		}
	}
			
	//cout << ans << '\n';
	forn(j, 4)
		cout << res[j] + 1 << ' ';
	cout << '\n';
	
	return 0;
}