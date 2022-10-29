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
const int INF = 1e9;
const int MAXN = 200500;

int n, a[MAXN], b[MAXN];
int used[MAXN];
vi g[MAXN];

void dfs(int v, int c) {
	used[v] = c;
	for (auto w: g[v]) {
		if (used[w] == 0) {
			dfs(w, 3 - c);	
		}
	}
}

int main() {
	
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d%d", &a[i], &b[i]);
		a[i]--, b[i]--;
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	
	forn(i, n) {
		g[2 * i].pb(2 * i + 1);
		g[2 * i + 1].pb(2 * i);
	}
	
	forn(i, n * 2) {
		if (used[i] == 0) {
			dfs(i, 1);	
		}
	}

	forn(i, n) {
		printf("%d %d\n", used[a[i]], used[b[i]]);	
	}
	
    return 0;
}