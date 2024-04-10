#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 1111;

vi a, b;

struct node {
	node *l, *r;
	int key, pr, cnt, flag;

	node(int _key) {
		l = r = NULL;
		key = _key;
		pr = rand();
		cnt = 1;
		flag = -1;
	}
};

int cnt(node *v) {
	return (v ? v -> cnt : 0);
}

inline void upd_cnt(node *&v) {
	if (v)
		v -> cnt = cnt(v -> l) + 1 + cnt(v -> r);
}

void push(node *&v) {
	if (v) {
		if (v -> flag != -1) {
			v -> key = a[(v -> flag) + cnt(v -> l)];
			if (v -> l)
				v -> l -> flag = v -> flag;
			if (v -> r)
				v -> r -> flag = v -> flag + cnt(v -> l) + 1;
			v -> flag = -1;
		}
	}
}

void split(node *v, int key, node *&l, node *&r) {
	if (!v) {
		l = r = NULL;
		return;
	}
	push(v);

	int cur_key = cnt(v -> l);
	if (key <= cur_key) {
		split(v -> l, key, l, v -> l);
		r = v;
	} else {
		split(v -> r, key - cnt(v -> l) - 1, v -> r, r);
		l = v; 
	}
	upd_cnt(v);
} 

void merge(node *&v, node *l, node *r) {
	push(l);
	push(r);

	if (!l)
		v = r;
	else if (!r)
		v = l;
	else if (l -> pr < r -> pr) {
		v = l;
		merge(v -> r, v -> r, r);
	} else {
		v = r;
		merge(v -> l, l, v -> l);
	}
	upd_cnt(v);
}

int find(node *&p, int key) {
    if (p == NULL)
        return -1;
	push(p);

	int cur_key = cnt(p -> l);
    if (key == cur_key)
        return p -> key;
    else {
        if (key < cur_key)
            return find(p -> l, key);
        else
            return find(p -> r, key - cnt(p -> l) - 1);
    }
}

int n, m, q, len, x, y;
node *t, *t1, *t2, *t3;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	forn(i, n)
		cin >> a[i];
	forn(i, n)
		cin >> b[i];

	t = NULL;
	forn(i, n) {
		t1 = new node(b[i]);
		merge(t, t, t1);
	}

	forn(i, m) {
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d%d%d", &x, &y, &len);
			x--, y--;
			split(t, y, t1, t2);
			split(t2, len, t2, t3);
			t2 -> flag = x;
			merge(t, t1, t2);
			merge(t, t, t3);
		} else {
			scanf("%d", &x);
			x--;
			printf("%d\n", find(t, x));
		}
	}

    return 0;
}