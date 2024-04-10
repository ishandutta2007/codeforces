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
const int MAXN = 100500;

int n, m, k, ans;
int maxsz, cursz, rest;
int cap[MAXN], used[MAXN];
vi g[MAXN];

void dfs(int v) {
	used[v] = 1;
	cursz++;
	for (auto w: g[v]) {
		if (!used[w]) {
			dfs(w);
		}
	}
}

int main() {
	
	cin >> n >> m >> k;
	forn(i, k) {
		scanf("%d", &cap[i]);
		cap[i]--;	
	}
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);	
	}
	
	ans = -m;
	maxsz = 0;
	rest = n;
	forn(i, k) {
		cursz = 0;
		dfs(cap[i]);
		rest -= cursz;

		if (cursz > maxsz) {
			maxsz = cursz;
		}
		
		ans += cursz * (cursz - 1) / 2;
	}
	
	while (rest > 0) {
		ans += maxsz;
		maxsz++;
		rest--;	
	}
	
	cout << ans << '\n';
	
    return 0;
}