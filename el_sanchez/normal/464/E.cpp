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
const int MAXN = 110500;
const int MAXK = 131072;
const int SZ = 4;
const int MOD[SZ] = {1000000007, 989999917, 989999909, 989999887};
const int P[SZ] = {2, 23, 29, 31};

int PW[SZ][2 * MAXK + 3], PF[SZ][2 * MAXK + 3];
    
struct node {
	int h[SZ];
	int rz;
	int val, upd;
	bool flag;
	node *L, *R;
	
	node() {
		memset(h, 0, sizeof(h));
		rz = 1;
		val = upd = flag = 0;
		L = R = NULL;
	}
};

int getZero(node *v, int L, int R, int pos) {
	//cout << L << ".." << R << endl;
	//cout << v->flag << endl;
	
	if (L + 1 == R)
		return v->rz;

	int res;
	if (pos < ((L + R) >> 1)) {
		res = MAXK + 1;
		if (!v->R) {
			if (v->upd == 0)
				res = ((L + R) >> 1);	
			//else only ones
		} else
			res = v->R->rz;
		
		if (!v->L) {
			if (v->upd == 0)
				res = min(res, pos);
		} else {
			res = min(res, getZero(v->L, L, (L + R) >> 1, pos));
		}
	} else {
		res = MAXK + 1;
		if (!v->R) {
			if (v->upd == 0)
				res = pos;			
		} else {
			res = getZero(v->R, (L + R) >> 1, R, pos);		
		}
	}
	
	return res;
}

void setValue(node *&v, int x, int L, int R) {
	v->val = x;
	v->upd = x;
	v->flag = 1;
	
	forn(i, SZ)
		v->h[i] = PF[i][R - L - 1] * x;
	if (x)
		v->rz = MAXK + 1;
	else
		v->rz = L;
}

void push(node *&v, int L, int R) {
	assert(v);
	if (v->flag) {
		if (L + 1 < R) {
			if (!v->L)	
				v->L = new node();
			if (!v->R)	
				v->R = new node();
			
			setValue(v->L, v->upd, L, (L + R) >> 1);
			setValue(v->R, v->upd, (L + R) >> 1, R);
		}
		
		v->upd = v->flag = 0;
	}
}

node *upd(node *&v, int L, int R, int lx, int rx, int x) {
	//cerr << L << ".." << R << endl;
	//cerr << v->flag << endl;
	
	push(v, L, R);

	if (R <= lx || rx <= L)
		return v;
	if (lx <= L && R <= rx) {
		node *w = new node();
		setValue(w, x, L, R);
		return w;
	}
	
	node *w = new node();
	w->L = upd(v->L, L, (L + R) >> 1, lx, rx, x);
	w->R = upd(v->R, (L + R) >> 1, R, lx, rx, x);

	w->val = w->L->val;
	w->rz = min(w->L->rz, w->R->rz);
	forn(i, SZ)
		w->h[i] = (1ll * w->R->h[i] * PW[i][(R - L) >> 1] + w->L->h[i]) % MOD[i];
	return w;	
}

node *upd(node *&v, int L, int R, int x) {
	if (L > R)
		return v;
	//cout << "upd: [" << L << ".." << R << "] <- " << x << endl;
	return upd(v, 1, MAXK + 1, L, R + 1, x);	
}

node *add(node *&v, int bit) {
	bit++;

	//cout << "add: " << bit << endl;
	//cout << "old: " << v->h[0] << endl;
	
	int rightZero = getZero(v, 1, MAXK + 1, bit);
	assert(rightZero <= MAXK);
	
	//cout << rightZero << endl;
	
	node *r1 = upd(v, rightZero, rightZero, 1);
	node *r2 = upd(r1, bit, rightZero - 1, 0);		
	
	//cout << "new: " << r2->h[0] << endl;
	
	return r2;
}

typedef pair<node*, int> number;

bool eq(node *v1, node *v2) {
	forn(i, SZ)
		if (v1->h[i] != v2->h[i])
			return 0;

	return 1;
}

bool cmp(node *v1, node *v2, int L, int R) {
	if (eq(v1, v2))
		return 0;
		
	if (v1->flag) {
		if (v1->upd == 0)
			return 1;
		else
			return 0;
	} else if (v2->flag) {
		if (v2->upd == 0)
			return 0;
		else
			return 1;
	}
	
	if (L + 1 == R)
		return v1->val < v2->val;
		
	if (eq(v1->R, v2->R))
		return cmp(v1->L, v2->L, L, (L + R) >> 1);
	return cmp(v1->R, v2->R, (L + R) >> 1, R);
}

bool cmp(node *a, node *b) {
	return cmp(a, b, 1, MAXK + 1);	
}

struct comparator {
	bool operator()(number a, number b) {
		if (!eq(a.X, b.X))
			return cmp(a.X, b.X);
		return a.Y < b.Y;
	}
};

int n, m, s, f;
vector<pii> g[MAXN];
int used[MAXN], parent[MAXN]; 
node *dist[MAXN];
set<number, comparator> d;
node *MAX, *MIN;
node *newDist;

void dijkstra() {
	forn(i, n)
		if (i != s) {
			dist[i] = MAX;
			d.insert({MAX, i});
			used[i] = 0;
		}
	
	dist[s] = MIN;
	d.insert({MIN, s});
	used[s] = 0;
	parent[s] = -1;

	number cur;
	int v;
	while (!d.empty()) {
		cur = *d.begin();

		if (eq(cur.X, MAX))
			break;

		d.erase(cur);
		v = cur.Y;
		used[v] = 1;
		
		for (auto e: g[v]) {
			int w = e.X;
			int bit = e.Y;
			
			if (!used[w]) {
				newDist = add(dist[v], bit);
				//cerr << "? " << w << endl;
				if (cmp(newDist, dist[w])) {
					d.erase({dist[w], w});
					dist[w] = newDist;
					parent[w] = v;
					d.insert({dist[w], w});
				}
			}
		}
	}
}

int main() {
	
	forn(i, SZ) {
		PW[i][0] = PF[i][0] = 1;
		forab(j, 1, 2 * MAXK + 3) {
			PW[i][j] = (1ll * PW[i][j - 1] * P[i]) % MOD[i];	
			PF[i][j] = (PF[i][j - 1] + PW[i][j]) % MOD[i];
		}
	}
	
	scanf("%d%d", &n, &m);
	forn(i, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	scanf("%d%d", &s, &f);
	s--, f--;

	MIN = new node();	
	MIN->rz = 1;
	MIN->val = 0;
	MIN->upd = 0;
	MIN->flag = 1;
	
	MAX = new node();
	forn(i, SZ)
		MAX->h[i] = PF[i][MAXK - 1];
	MAX->rz = MAXK + 1;
	MAX->val = 1;
	MAX->upd = 1;
	MAX->flag = 1;
	
	dijkstra();
	//cerr << "end" << endl;
	
	if (!used[f]) {
		cout << -1 << '\n';
	} else {
		int len = dist[f]->h[0];

		cout << len << '\n';

		vi path;
		int v = f;
		while (v != -1) {
			path.pb(v);
			v = parent[v];	
		}
		
		reverse(all(path));
		
		cout << path.size() << '\n';
		for (auto v: path)
			printf("%d ", v + 1);
			
	}
	
	return 0;
}