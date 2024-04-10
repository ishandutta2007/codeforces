#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

struct item {
    int value, prior, cnt;
    item * l, * r;
    item(int v) : value(v) {
        prior = rand();
        cnt = 1;
        l = r = nullptr;
    }
};

inline int cnt(item * i) {
    if (i) {
        return i->cnt;
    } else {
        return 0;
    }
}

inline int upd_cnt(item * i) {
    if (i) {
        i->cnt = 1 + cnt(i->l) + cnt(i->r);
    }
}

void merge(item * & res, item * l, item * r) {
    if (!l) {
        res = r;
        return;
    }
    if (!r) {
        res = l;
        return;
    }
    if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        res = l;
    } else {
        merge(r->l, l, r->l);
        res = r;
    }
    upd_cnt(res);
}

void split(item * & l, item * & r, item * tree, int i) {
    if (!tree) {
        l = nullptr;
        r = nullptr;
        return;
    }
    if (cnt(tree->l) >= i) {
        split(l, tree->l, tree->l, i);
        upd_cnt(tree);
        r = tree;
    } else {
        split(tree->r, r, tree->r, i - cnt(tree->l) - 1);
        upd_cnt(tree);
        l = tree;
    }
}

void update_all(item * tree) {
    if (!tree) return;
    update_all(tree->l);
    update_all(tree->r);
    upd_cnt(tree);
}

int sum1[222222], sum2[222222];
const int N = 222222;
int n, a[222222], b[222222], n1[222222], n2[222222], res[222222];

int get (int sum[], int r)
{
    r++;
	int result = 0;
	for (; r > 0; r -= r & (-r))
		result += sum[r];
	return result;
}

void inc (int sum[], int i, int delta)
{
    i++;
	for (; i < N; i += i & (-i))
		sum[i] += delta;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    srand(time(NULL));
    cin >> n;
    for (int i = 1; i < n; i++) {
        inc(sum2, i, 1);
        inc(sum1, i, 1);
    }
    for (int i = 0; i< n; i++) {
        scanf("%d", &a[i]);
        n1[i] = get(sum1, a[i]);
        inc(sum1,a[i], -1);
    }
    for (int i = 0; i< n; i++) {
        scanf("%d", &b[i]);
        n2[i] = get(sum2, b[i]);
        inc(sum2, b[i], -1);
    }
    for (int i = n-1, j=0; i>=0; i--) {
        res[i] = (n1[i]+n2[i] + j)%(n-i);
        if (n1[i]+n2[i]+j >= n-i)  j=1;
        else j=0;
    }

    item * tree = nullptr;
    vector<item *> v;
    for (int i = 0; i < n; i++) {
        item * nxt = new item(i);
        while (v.size() && v.back()->prior < nxt -> prior) {
            v.pop_back();
        }
        if (!v.size()) {
            nxt->l = tree;
            tree = nxt;
        } else {
            nxt ->l = v.back()->r;
            v.back()->r = nxt;
        }
        v.push_back(nxt);
    }
    update_all(tree);

    for (int i = 0; i < n; i++) {
        item * l, * m, * r;
        split(l, m, tree, res[i]);
        split(m, r, m, 1);
        int ress = m->value;
        merge(tree, l, r);
        printf("%d ", ress);
    }
    return 0;
}