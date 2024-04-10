#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int m, aa[100005], tt[100005], xx[100005];
int n, k, a[100005], b[100005];
map<int, int> mp, mp2;

struct node {
    node *l, *r;
    int sum;
    node() : l(NULL), r(NULL), sum(0) { }

} e[100005];

int get(node* v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (v == NULL) return 0;
    if (l == tl && r == tr) {
        return v->sum;
    }
    int tm = (tl + tr) >> 1;
    return get(v->l, tl, tm, l, min(r, tm)) + get(v->r, tm + 1, tr, max(l, tm + 1), r);
}

void add(node* v, int idx, int val, int l, int r) {
    if (l == r) {
        v->sum += val;
        return;
    }
    int tm = (l + r) >> 1;
    if (idx <= tm) {
        if (!v->l) v->l = new node();
        add(v->l, idx, val, l, tm);
    } else {
        if (!v->r) v->r = new node();
        add(v->r, idx, val, tm + 1, r);
    }
    v->sum = (v->l ? v->l->sum : 0) + (v->r ? v->r->sum : 0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> aa[i] >> tt[i] >> xx[i];
        mp[xx[i]] = 1;
        mp2[tt[i]] = 1;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it)
        if (it->second)
            a[n++] = it->first;
    for (int i = 0; i < n; ++i)
        mp[a[i]] = i;
    for (int i = 0; i < m; ++i)
        xx[i] = mp[xx[i]];

    for (auto it = mp2.begin(); it != mp2.end(); ++it)
        if (it->second)
            b[k++] = it->first;
    for (int i = 0; i < k; ++i)
        mp2[b[i]] = i;
    for (int i = 0; i < m; ++i)
        tt[i] = mp2[tt[i]];

    for (int i = 0; i < m; ++i) {
        if (aa[i] == 1) {
            add(&e[xx[i]], tt[i], 1, 0, k - 1);
        } else if (aa[i] == 2) {
            add(&e[xx[i]], tt[i], -1, 0, k - 1);
        } else {
            cout << get(&e[xx[i]], 0, k - 1, 0, tt[i]) << "\n";
        }
    }

    return 0;
}