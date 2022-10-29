#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 100500;

struct node {
    int key, pr, ans;
	int flag1, flag2;
    node *l, *r, *par;
    node(int _key){
        key = _key;
		pr = rand();
        l = r = par = NULL;
		flag1 = flag2 = ans = 0;
    }
};

void update(node *&v, node *pv) {
	if (v)
		v -> par = pv;
}

void push(node *&p) {
	if (!p)
		return;

	if (p->flag1) {
		p->key += p->flag1;
		if (p->l)
			p->l->flag1 += p->flag1;
		if (p->r)
			p->r->flag1 += p->flag1;

		p->flag1 = 0;
	}

	if (p->flag2) {
		p->ans += p->flag2;
		if (p->l)
			p->l->flag2 += p->flag2;
		if (p->r)
			p->r->flag2 += p->flag2;

		p->flag2 = 0;
	}
}

void split(node *v, int key, node *&l, node *&r, node *lp, node *rp) {
	push(v);

	if (!v) {
		l = r = NULL;
		return;
	}

	if (v->key > key) {
		split(v -> l, key, l, v -> l, lp, v);
		r = v;
	} else {
		split(v -> r, key, v -> r, r, v, rp);
		l = v;
	}

	update(l, lp);
	update(r, rp);
}

void merge(node *&v, node *l, node *r, node *vp) {
	push(l);
	push(r);

	if (!l)
		v = r;
	else if (!r)
		v = l;
	else if (l -> pr < r -> pr) {
		v = l;
		merge(v -> r, v -> r, r, v);
	} else {
		v = r;
		merge(v -> l, l, v -> l, v);
	}
	
	update(v, vp);
}

void scan(node *&v) {
	if (v->par == NULL) {
		push(v);
		return;
	}
	scan(v->par);
	push(v);
}

node *t;

string s;
int n, m;
vector<pii> a;
vector<pair<pii, int>> q;
vector<node*> x;
vi ans;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> s;
	n = s.size();
	cin >> m;
	a.resize(m);
	forn(i, m) {
		cin >> a[i].ff >> a[i].ss;
		a[i].ff--;
		a[i].ss--;

		q.pb(mp(mp(a[i].ff, 0), i));
		q.pb(mp(mp(a[i].ss, 1), i));
	}
	forn(i, m)
		x.push_back(NULL);

	t = NULL;
	int last = -1;

	sort(all(q));
	ans.resize(m, 0);

	int id;
	node *t1, *t2;

	for (int i = 0; i < q.size(); i++) {
		int c = q[i].ff.ff;
	
		if (last < c) {
			forab(j, last + 1, c + 1)
				if (s[j] == '(') {
					if (t)
						t->flag1++;
				} else {
					split(t, 0, t1, t2, NULL, NULL);
					if (t2) {
						t2->flag1--;
						t2->flag2 += 2;
					}
					merge(t, t1, t2, NULL);
				}
			last = c;
		}
			
		if (q[i].ff.ss == 0) {
			id = q[i].ss;
			x[id] = new node(s[c] == '(');
			if (s[c] == '(') {
				split(t, 0, t1, t2, NULL, NULL);
				merge(t, t1, x[id], NULL);
				merge(t, t, t2, NULL);
			} else
				merge(t, x[id], t, NULL);
		}

		if (q[i].ff.ss == 1) {
			id = q[i].ss;
			scan(x[id]);
			ans[id] = x[id]->ans;
		}
	}

	forn(i, m)
		printf("%d\n", ans[i]);
	
	return 0;
}