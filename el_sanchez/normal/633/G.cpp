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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
const int MAXK = 131072;
const int M = 1005;

int n, m, q, id, v, w;
int a[MAXN];
int L[MAXN], R[MAXN], sz;
vi g[MAXN];
bitset<M> t[2 * MAXK + 3];
int flag[2 * MAXK + 3];
bitset<M> tmp, primes;

void build() {
	forn(i, 2 * MAXK + 3) {
		t[i].reset();
		flag[i] = 0;
	}
		
	for (int i = 0; i < n; i++)
		t[MAXK + L[i]][a[i] % m] = 1;
	for (int i = MAXK - 1; i >= 1; i--)
		t[i] = t[i * 2] | t[i * 2 + 1];
}

void dfs(int v, int pv) {
	L[v] = sz++;
	for (auto w: g[v])
		if (w != pv)
			dfs(w, v);
	R[v] = sz - 1;	
}

void apply(int v, int s) {
	tmp = t[v] >> (m - s);
	t[v] ^= (tmp << (m - s));
	t[v] <<= s;
	t[v] |= tmp;	
}

void push(int v) {
	if (flag[v] > 0) {
		if (v < MAXK) {
			apply(v * 2, flag[v]);
			apply(v * 2 + 1, flag[v]);		
			flag[v * 2] += flag[v];
			flag[v * 2 + 1] += flag[v];
			if (flag[v * 2] >= m)
				flag[v * 2] -= m;
			if (flag[v * 2 + 1] >= m)
				flag[v * 2 + 1] -= m;
		}
		
		flag[v] = 0;
	}	
}

void shift(int v, int lv, int rv, int lx, int rx, int s) {
	push(v);
	
	if (rv <= lx || rx <= lv)
		return;
	if (lx <= lv && rv <= rx) {
		flag[v] = s;
		apply(v, s);		
		return;
	}
	
	shift(v * 2, lv, (lv + rv) >> 1, lx, rx, s);
	shift(v * 2 + 1, (lv + rv) >> 1, rv, lx, rx, s);
	t[v] = t[v * 2] | t[v * 2 + 1];
}

bitset<M> e;

bitset<M> get(int v, int lv, int rv, int lx, int rx) {
    push(v);
	
	if (rv <= lx || rx <= lv)
		return e;
	if (lx <= lv && rv <= rx)
		return t[v];
	
	return get(v * 2, lv, (lv + rv) >> 1, lx, rx) |
	       get(v * 2 + 1, (lv + rv) >> 1, rv, lx, rx);
}

void shift(int v, int s) {
	shift(1, 1, MAXK + 1, L[v] + 1, R[v] + 2, s % m);	
}

bitset<M> get(int v) {
	return get(1, 1, MAXK + 1, L[v] + 1, R[v] + 2);	
}

int main() {
        
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	
	forn(i, n - 1) {
		scanf("%d%d", &v, &w);
		v--, w--;
		g[v].pb(w);
		g[w].pb(v);	
	}
	
	sz = 0;
	dfs(0, -1);
	
	build();
	
	primes.reset();
	for (int i = 2; i < m; i++) {
		bool ok = 1;
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0) {
				ok = 0;
				break;
			}
			
		if (ok)
			primes[i] = 1;
	}
	
	e.reset();
	
	//forn(i, n)
	//	cout << get(i) << '\n';
	
	scanf("%d", &q);
	forn(qq, q) {
		scanf("%d%d", &id, &v);
		v--;
		if (id == 1) {
			scanf("%d", &w);
			shift(v, w);
		} else {
			printf("%d\n", (get(v) & primes).count());	
		}
	}
	
	return 0;	
}