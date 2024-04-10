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
const int INF = (int)1e9;
const int MAXN = 1005000;
const int M = (int)1e9 + 7;

int P[3] = {10000019, 10000079, 10000103};
int MOD[3] = {1000000007, 1000000009, 1000000021};

struct h {
	int a[2];
	int id;
	
	h() {
		memset(a, 0, sizeof(a));
		id = 0;
	}
};

bool cmp(h a, h b) {
	forn(i, 2) {
		if (a.a[i] != b.a[i]) {
			return a.a[i] < b.a[i];	
		}
	}
	return a.id < b.id;
}

bool eq(h a, h b) {
	forn(i, 2) {
		if (a.a[i] != b.a[i]) {
			return 0;	
		}
	}
	return 1;
}

int n, m;
int used[MAXN];
vi cur;
int cnt[MAXN];
h hashes[MAXN];
int pw[3][MAXN], f[MAXN];
vector<pii> upd[MAXN];
int MAGIC = 533331;

int main() {

	f[0] = 1;
	forab(i, 1, MAXN) {
		f[i] = 1ll * f[i - 1] * i % M;
	}
	
	while (cin >> n >> m) {
		memset(used, 0, sizeof(used));
		memset(cnt, 0, sizeof(cnt));
		int tmr = 0;
		int magic = 0;

		forn(i, n) {
			upd[i].clear();
			
			int k;
			scanf("%d", &k);
			tmr++;
			cur.clear();
			forn(j, k) {
				int v;
				scanf("%d", &v);
				
				magic = (magic + v) % MAGIC;
				v--;
				
				if (used[v] != tmr) {
					cur.pb(v);
					cnt[v] = 0;
				}
				used[v] = tmr;
				cnt[v]++;
			}
			
			for (auto v: cur) {
				upd[i].pb({v, cnt[v]});
			}
		}
		/*
		forn(i, n) {
			cout << "---\n";
			for (auto v: upd[i]) {
				cout << v.X << ' ' << v.Y << '\n';
			}
		}
		*/
		P[magic % 2] += magic;
		
		forn(i, 2) {
			pw[i][0] = 1;
			forab(j, 1, MAXN) {
				pw[i][j] = 1ll * pw[i][j - 1] * P[i] % MOD[i];
			}
		}
		
		forn(i, m) {
			hashes[i] = h();
			if (used[i] == 0) {
				hashes[i].a[0] = -1;	
			}
			hashes[i].id = i;
		}
		
		forn(i, n) {
			for (auto v: upd[i]) {
				forn(j, 3) {
					hashes[v.X].a[j] = (hashes[v.X].a[j] + 0ll + 1ll * v.Y * pw[j][i + 1]) % MOD[j];
				}
			}
		}
		
		sort(hashes, hashes + m, cmp);
		
		int ans = 1;
		int L = 0;
		for (int i = 1; i <= m; i++) {
			if (i == m || !eq(hashes[L], hashes[i])) {
				//cout << "block: " << i - L << '\n';
				ans = 1ll * ans * f[i - L] % M;
				
				L = i;
			}
		}
		
		cout << ans << '\n';
	}
		
	return 0;
}