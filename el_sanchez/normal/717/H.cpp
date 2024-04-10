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
const int MAXN = 50100;
const int MAXT = 1000100;

int n, m, T, id[MAXN], used[MAXN], choice[MAXN], usedT[MAXN], cnt[2];
vi g[MAXN];
vi lst[MAXN], cur;

int main() {
	
	scanf("%d%d", &n, &m);
	forn(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	T = 0;
	forn(i, n) {
		int L;
		scanf("%d", &L);
		lst[i].resize(L);
		forn(j, L) {
			scanf("%d", &lst[i][j]);	
			T = max(lst[i][j], T);
			lst[i][j]--;
		}
	}
	
	forn(i, n)
		id[i] = i;
	random_shuffle(id, id + n);
	memset(usedT, -1, sizeof(usedT));
	
	forn(i, n) {
		int v = i;	
		
		used[v] = 1;
		cnt[0] = cnt[1] = 0;
		for (auto w: g[v]) {
			if (used[w]) {
				cnt[usedT[choice[w]]]++;
			}
		}
		
		int conf = 0;
		if (cnt[0] > cnt[1])
			conf = 1;

		cur.clear();
		for (auto lid: lst[v]) {
			if (usedT[lid] == -1 || usedT[lid] == conf)
				cur.pb(lid);
		}
		
		if (cur.empty()) {
			for (auto lid: lst[v]) {
				cur.pb(lid);
			}
		}

		int f = rand() % cur.size();
		int t = cur[f];
		choice[v] = t;
		usedT[t] = conf;	
	}
	
	forn(i, T)
		if (usedT[i] == -1)
			usedT[i]++;
			
	forn(i, n)
		printf("%d ", choice[i] + 1);
	cout << '\n';
	//cout << T << '\n';
	forn(i, T)
		printf("%d ", usedT[i] + 1);		
		
	return 0;
}