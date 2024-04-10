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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 200500;

int n, x, y;
int a, b;
vi g[MAXN];
int deg[MAXN], rest[MAXN], used[MAXN];
vi leaves, nleaves;
int V, edges;
ll ans;

int main() {

	scanf("%d%d%d", &n, &x, &y);
	forn(i, n - 1) {
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	ans = 0;
	
	if (x >= y) {
		bool c = 0;
		forn(i, n)
			if ((int)g[i].size() == n - 1) {
				c = 1;
				break;
			}
			
		if (c) {
			ans = 1ll * (n - 2) * y;
			ans += x;
		} else
			ans = 1ll * (n - 1) * y;
	} else {
		forn(i, n) {
			used[i] = 0;
			deg[i] = g[i].size();
		}
			
		forn(i, n)
			if (deg[i] == 1) {
				//cout << "add " << i << '\n';
				leaves.pb(i);
				used[i] = 1;
			}

		forn(i, n)
			rest[i] = 2;
			
		V = n;
		edges = n - 1;
		bool stop = 0;
		
		while (!stop && !leaves.empty()) {
			nleaves.clear();
			//cout << V << ' ' << leaves.size() << '\n';
			
			if (V == 2 && leaves.size() == 2) {
				int a = leaves[0];
				int b = leaves[1];
				
				//db(rest[a]);
				//db(rest[b]);
				if (rest[a] > 0 && rest[b] > 0) {
					edges--;
					ans += x;
				}
				
				break;
			}
			
			for (auto v: leaves) {
				//cout << "watch " << v << '\n';
				int rt = -1;
				for (auto w: g[v])
					if (!used[w]) {
						rt = w;
						break;
					}

				if (rt == -1) {
					stop = 1;
					break;
				}
				
				if (rest[v] > 0 && rest[rt] > 0) {
					//cout << "add: " << v << " -> " << rt << '\n';
					edges--;
					ans += x;
					rest[rt]--;	
					rest[v]--;
				}
				
				//erase v
				deg[v]--;
				
				if (deg[v] < 0) {
					//cout << "!\n";
					stop = 1;
					break;
				}
				
				deg[rt]--;
				if (deg[rt] == 1) {
					nleaves.pb(rt);
				}
				
				if (deg[rt] == 0) {
					//cout << "!!\n";					
					stop = 1;
					break;
				}
			}
			
			V -= leaves.size();
			leaves = nleaves;
			
			for (auto v: leaves)
				used[v] = 1;				
		}
		
		ans += 1ll * edges * y;
	}
	
	cout << ans << '\n';
	
	return 0;
}