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
const int MAXN = 200500;
const int BITS = 60;
const int SZ = BITS * 2;
const int MOD = (int)1E9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;	
}

ll cnk[SZ][SZ];
ll ocnk[SZ];

int n, m, a, b;
ll val[MAXN];
vector<pii> g[MAXN];
int used[MAXN];
ll xr[MAXN];
int ans;

int ptr, dim;
ll bas[MAXN], B[MAXN], times[BITS], x, y;
int vtimes[BITS];

int pos[BITS], tt[MAXN], tmr;

int csz;
int comp[MAXN];
//int ITER = 0;

void dfs(int v, int pe) {
	//ITER++;
	//if (ptr % 10000 == 0)
	//	cerr << ptr << endl;
	//cerr << "dfs(" << v << ")\n";
	tt[v] = tmr++;
	used[v] = 1;
	comp[csz++] = v;
	
	for (auto e: g[v]) {
		if (e.Y == pe)
			continue;
			
		int w = e.X;
		if (used[w]) {
			if (tt[w] < tt[v])
				bas[ptr++] = xr[w] ^ xr[v] ^ val[e.Y];		
		} else {
			xr[w] = xr[v] ^	val[e.Y];
			dfs(w, e.Y);
		}
	}
}

int main() {
	
	cnk[0][0] = 1;
	forab(i, 1, SZ) {
		cnk[i][0] = 1;
		forab(j, 1, SZ)
			cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
	}
	
	for (int i = 0; i < SZ; i++) {
		ocnk[i] = 0;
		for (int j = 1; j < SZ; j += 2)
			ocnk[i] += cnk[i][j];	
	}
	
	cin >> n >> m;
	forn(i, m) {
		scanf("%d%d%I64d", &a, &b, &val[i]);
		a--, b--;
		g[a].pb({b, i});
		g[b].pb({a, i});	
	}
	
	ans = 0;
	forn(root, n)
		if (!used[root]) {
			tmr = 0;
			//cerr << root << endl;
			ptr = 0;
			csz = 0;
			xr[root] = 0;
			dfs(root, -1);	
			//cerr << root << endl;
			
			memset(pos, -1, sizeof(pos));
			
			dim = 0;
			for (int j = 0; j < ptr; j++) {
				while (bas[j] != 0) {
					int hbit = 63 - __builtin_clzll(bas[j]);
					assert(hbit < BITS);
					if (pos[hbit] == -1) {
						pos[hbit] = j;
						break;	
					} else {
						bas[j] ^= bas[pos[hbit]];	
					}
				}
			}
			
			dim = 0;
			forn(i, BITS) {
				if (pos[i] != -1)
					B[dim++] = bas[pos[i]];	
			}
			/*
			cout << csz << '\n';
			cout << dim << '\n';
			forn(i, dim)
				cout << i << ": " << B[i] << '\n';
			*/	
			forn(i, BITS) {
				int cnt = 0;
				forn(j, dim)
					cnt += (B[j] >> i) & 1;											
					
				times[i] = (1ll << (dim - cnt)) * 1ll * ocnk[cnt];
			}
			
			memset(vtimes, 0, sizeof(vtimes));
			
			forn(i, csz) {
				int v = comp[i];
				
				forn(j, BITS)
					vtimes[j] += (xr[v] >> j) & 1;
			}
			/*
			forn(i, 4)
				cout << vtimes[i] << '\n';
			*/	
			forn(i, BITS) {
				x = vtimes[i] % MOD;
				y = (csz - vtimes[i]) % MOD;
				
				int t = 1ll * times[i] % MOD;
				int it = 1ll * ((1ll << dim) - times[i]) % MOD;
				int adder = 1ll * (1ll << i) % MOD;
				
				//cout << x << ' ' << y << '\n';
				//cout << t << ' ' << it << '\n';
				
				//get 1
				int m1 = 1ll * x % MOD * 1ll * y % MOD * 1ll * it % MOD;
				m1 = 1ll * m1 * adder % MOD;

				add(ans, m1);

				//get 0 
				int m2 = 1ll * x * (x - 1) / 2 % MOD;
				m2 = (0ll + m2 + 1ll * y * (y - 1) / 2 % MOD) % MOD;
				m2 = 1ll * m2 * t % MOD;
				m2 = 1ll * m2 * adder % MOD;
				
				add(ans, m2);
				
				//cout << "ANS: " << ans << '\n';
			}
		}
	
	cout << ans << '\n';
	//cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	
	return 0;
}