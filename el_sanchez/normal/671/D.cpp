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
const ll LINF = 1E18;
const int MAXN = 300500;
const int MAXK = 524288;
    
struct vertex {
	ll val, upd;
	bool flag;

	vertex() {
		val = upd = flag = 0;
	}
};

vertex t[2 * MAXK + 3];

void initTree() {
	forn(i, 2 * MAXK + 3)
		t[i].val = LINF;	
}

ll add(ll a, ll x) {
	if (a == LINF)
		return a;
	
	a += x;
	if (a >= LINF)
		a = LINF;
	return a;	
}

void push(int v, int L, int R) {
	if (t[v].flag) {
		if (R - L > 1) {
			t[2 * v].val = add(t[2 * v].val, t[v].upd);
			t[2 * v + 1].val = add(t[2 * v + 1].val, t[v].upd);
			
			t[2 * v].upd = add(t[2 * v].upd, t[v].upd);
			t[2 * v + 1].upd = add(t[2 * v + 1].upd, t[v].upd);
			
			t[2 * v].flag = t[2 * v + 1].flag = 1;
		}
		
		t[v].upd = 0;
		t[v].flag = 0;
	}
}

void upd(int v, int L, int R, int lx, int rx, ll x) {
	push(v, L, R);

	if (rx <= L || R <= lx)
		return;
	if (lx <= L && R <= rx) {
		t[v].val = add(t[v].val, x);
		t[v].upd = add(t[v].upd, x);
		t[v].flag = 1;
		return;
	}
	
	upd(v * 2, L, (L + R) >> 1, lx, rx, x);
	upd(v * 2 + 1, (L + R) >> 1, R, lx, rx, x);
	t[v].val = min(t[v * 2].val, t[v * 2 + 1].val);
}

void assign(int v, int L, int R, int pos, ll x) {
	push(v, L, R);

	if (L + 1 == R) {
		t[v].val = x;
		t[v].upd = 0;
		t[v].flag = 0;
		return;	
	}
	
	if (pos < ((L + R) >> 1)) {
		assign(v * 2, L, (L + R) >> 1, pos, x);
	} else {
		assign(v * 2 + 1, (L + R) >> 1, R, pos, x);
	}
	
	t[v].val = min(t[v * 2].val, t[v * 2 + 1].val);
}

ll get(int v, int L, int R, int lx, int rx) {
	push(v, L, R);

	if (rx <= L || R <= lx)
		return LINF;
	if (lx <= L && R <= rx)
		return t[v].val;
	return min(get(v * 2, L, (L + R) >> 1, lx, rx),
               get(v * 2 + 1, (L + R) >> 1, R, lx, rx));
}

void upd(int L, int R, ll x) {
	upd(1, 1, MAXK + 1, L + 1, R + 2, x);
}

void assign(int pos, ll x) {
	assign(1, 1, MAXK + 1, pos + 1, x);	
}

ll get(int L, int R) {
	return get(1, 1, MAXK + 1, L + 1, R + 2);	
}

int n, m;
int used[MAXN];
vi g[MAXN];
vector<pii> open[MAXN], close[MAXN];
int ptr, qPos[MAXN];
int lb[MAXN], rb[MAXN];
ll ans;
ll dp[MAXN], S[MAXN];

void dfs(int v) {
	used[v] = 1;

	lb[v] = ptr;
	for (auto q: open[v])
		qPos[q.X] = ptr++;
		
	for (auto w: g[v])
		if (!used[w])
			dfs(w);	
			
	rb[v] = ptr - 1;
}

void calcDP(int v) {
	used[v] = 1;
	
	S[v] = 0;
	for (auto w: g[v])
		if (!used[w]) {
			calcDP(w);
			
			S[v] = add(S[v], dp[w]);
			upd(lb[w], rb[w], -dp[w]);
		}

	//open: assign cost
	for (auto q: open[v])
		assign(qPos[q.X], q.Y);
		
	//close: assign +inf
	for (auto q: close[v])
		assign(qPos[q.X], LINF);
	/*
	cout << "dfs(" << v << "):\n";
	forn(i, m) {
		cout << "val " << i << ": " << get(qPos[i], qPos[i]) << '\n';
	}
	*/
	upd(lb[v], rb[v], S[v]);
	dp[v] = get(lb[v], rb[v]);
}

int main() {
	
	scanf("%d%d", &n, &m);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);	
	}
	
	forn(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		
		open[a].pb({i, c});
		close[b].pb({i, c});			
	}
	
	ptr = 0;
	dfs(0);
	
	initTree();
	memset(used, 0, sizeof(used));
	calcDP(0);
	
	//forn(i, n)
	//	cout << i << ": " << dp[i] << '\n';
		
	ans = 0;
	for (auto v: g[0]) {
		ans = add(ans, dp[v]);
	}
	
	cout << (ans == LINF ? -1 : ans) << '\n';
		
	return 0;
}