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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;
const int MAXN = 1111;
const int MAXM = 1000500;

int n, q, m, a, b, c, u;
pair<pii, pii> edges[MAXM];
int color[MAXN], setId[MAXN];
int sets[MAXN][MAXN];
int sz[MAXN];

int id;
int idu, idv, f;

void mergeTo(int from, int to, int x) {
	forn(i, sz[from]) {
		u = sets[from][i];
		setId[u] = to;
		color[u] ^= x;
		sets[to][sz[to]++] = u;
	}
	sz[from] = 0;
}

bool add(int u, int v) {
	if (color[u] == -1 && color[v] == -1) {
		color[u] = 0;
		color[v] = 1;
		id = setId[u];
		setId[v] = id;
		sets[id][sz[id]++] = v;
		return 1;	
	}
	
	if (color[u] == -1)
		return add(v, u);
		
	if (color[v] == -1) {
		color[v] = color[u] ^ 1;
		
		id = setId[u];
		setId[v] = setId[u];
		sets[id][sz[id]++] = v;
		return 1;
	}
	
	idu = setId[u];
	idv = setId[v];
	
	if (idu == idv)
		return color[u] != color[v];
		
	f = color[u] == color[v];
	
	if (sz[idu] <= sz[idv]) {
		mergeTo(idu, idv, f);	
	} else {
		mergeTo(idv, idu, f);	
	}
	return 1;
}

int main() {

	scanf("%d%d%d", &n, &m, &q);
	forn(i, m) {
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		edges[i] = {{c, i}, {a, b}};
	}
	
	sort(edges, edges + m);
	reverse(edges, edges + m);
	
	forn(iii, q) {
		int L, R;
		scanf("%d%d", &L, &R);	
		L--, R--;

		forn(i, n) {
			color[i] = -1;	
			setId[i] = i;
			sets[i][0] = i;
			sz[i] = 1;
		}
		
		int ans = -1;
		forn(i, m)
			if (L <= edges[i].X.Y && edges[i].X.Y <= R) {
				if (!add(edges[i].Y.X, edges[i].Y.Y)) {
					ans = edges[i].X.X;
					break;
				}
			}
			
		printf("%d\n", ans);
	}
	
	return 0;
}