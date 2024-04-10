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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 5111;

struct node {
    pii key;
	int pr, cnt;
    node *l, *r;
    node(pii _key){
        key = _key;
		pr = rand();
        cnt = 1;
        l = r = NULL;
    }
};

int cnt(node *p) {
    return p ? p->cnt : 0;
}

void upd_cnt (node *&p) {
    if (p)
        p->cnt = 1 + cnt(p->l) + cnt(p->r);
}

void split(node *p, pii key, node *&l, node *&r) {
    if (p == NULL) {
        l = r = NULL;
        return;
    }

    if (key < p->key) {
        split(p->l, key, l, p->l);
        r = p;
    } else {
        split(p->r, key, p->r, r);
        l = p;
    }
    upd_cnt(p);
}

void merge(node *&p, node *l, node *r) {
    if (l == NULL)
        p = r;
    else if (r == NULL)
        p = l;
    else if (l->pr < r->pr) {
        p = l;
        merge(l->r, l->r, r);
    } else {
        p = r;
        merge(r->l, l, r->l);
    }
    upd_cnt(p);
}

void insert(pii key, int pr, node *&p) {
    if (p == NULL) {
        p = new node(key);
		p->pr = pr;
        return;
    }
    if (pr > p->pr) {
        if (key > p->key)
            insert(key, pr, p->r);
        else
            insert(key, pr, p->l);
    } else {
        node *t = new node(key);
		t->pr = pr;
        split(p, key, t->l, t->r);
        p = t;
    }
    upd_cnt(p);
}

void erase(pii key, node *&p) {
    if (p == NULL)
        return;
	if (p->key == key)
		merge(p, p->l, p->r);
	else {
	    if (key < p->key)
            erase(key, p->l);
        else
            erase(key, p->r);
	}
	upd_cnt(p);
}

int n, m;
vi color, used;
vector<vi> g, queries;
vector<pii> q;
vector<node*> root;
vector<map<int, int> > lib;
vi ans, link;

void init() {
	color.resize(n);
	used.resize(n, 0);
	root.resize(n, NULL);
	g.resize(n);
	queries.resize(n);
	q.resize(m);
	ans.resize(m);
	link.resize(n);
	lib.resize(n);
}

void intersect(int vid, int wid, node *&w) {
	if (!w)
		return;
	if (w->l)
		intersect(vid, wid, w->l);
	if (w->r)
		intersect(vid, wid, w->r);

	int ckey = w->key.ss;
	if (lib[link[vid]].find(ckey) == lib[link[vid]].end()) {
		lib[link[vid]][ckey] = w->key.ff;
		insert(w->key, rand(), root[vid]);
	} else {
		erase(mp(lib[link[vid]][ckey], ckey), root[vid]);
		w->key.ff += lib[link[vid]][ckey];
		insert(w->key, rand(), root[vid]);
		lib[link[vid]][ckey] = w->key.ff;		
	}

	lib[link[wid]].erase(ckey);
	delete w;
}

void dfs(int v, int par) {
	used[v] = 1;

	forn(i, g[v].size()) {
		int w = g[v][i];
		if (!used[w]) {
			dfs(w, v);
		}
	}

	if (v == 0) {
		v = v;
	}
	//merging
	int maxid = -1;
	forn(i, g[v].size()) {
		int w = g[v][i];
		if (w != par) {
			if (maxid == -1 || cnt(root[w]) > cnt(root[maxid]))
				maxid = w;
		}
	}

	if (maxid != -1) {
		link[v] = link[maxid];
		root[v] = root[maxid];
		forn(i, g[v].size()) {
			int w = g[v][i];
			if (w != par && w != maxid) {
				intersect(v, w, root[w]);
			}
		}

		if (lib[link[v]].find(color[v]) == lib[link[v]].end()) {
			lib[link[v]][color[v]] = 1;
			insert(mp(1, color[v]), rand(), root[v]);
		} else {
			erase(mp(lib[link[v]][color[v]], color[v]), root[v]);
			lib[link[v]][color[v]]++;
			insert(mp(lib[link[v]][color[v]], color[v]), rand(), root[v]);
		}
	} else {
		root[v] = new node(make_pair(1, color[v]));
		link[v] = v;
		lib[link[v]][color[v]] = 1;
	}

	node *t1 = NULL, *t2 = NULL;
	for (int i = 0; i < queries[v].size(); i++) {
		int qid = queries[v][i];
		split(root[v], mp(q[qid].ss, 0), t1, t2);
		ans[qid] = cnt(t2);
		merge(root[v], t1, t2);
	}
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	init();
	forn(i, n)
		cin >> color[i];
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	forn(i, m) {
		cin >> q[i].ff >> q[i].ss;
		q[i].ff--;
		queries[q[i].ff].push_back(i);
	}

	dfs(0, 0);

	forn(i, m)
		printf("%d\n", ans[i]);

	return 0;
}