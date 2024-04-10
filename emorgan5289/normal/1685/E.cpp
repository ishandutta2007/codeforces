#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 1<<18;
int n, q, p[N], pi[N];
int v[2*N], u[2*N], vl[2*N], vr[2*N];

int sgn(int x) {
    if (x > n) return 1;
    if (x < n) return -1;
    return 0;
}

void build() {
    for (int i = 0; i < N; i++)
        vl[N+i] = vr[N+i] = i;
    for (int i = 0; i < 2*n+1; i++)
        v[N+i] = sgn(p[i]) + (i == 0 ? 0 : v[N+i-1]);
    for (int i = N-1; i > 0; i--) {
        vl[i] = vl[2*i], vr[i] = vr[2*i+1];
        v[i] = min(v[2*i], v[2*i+1]);
    }
}

void push(int i) {
    v[i] += u[i];
    if (i < N)
        u[2*i] += u[i], u[2*i+1] += u[i];
    u[i] = 0;
}

void range_add(int l, int r, int d, int i = 1) {
    if (l <= vl[i] && r >= vr[i])
        u[i] += d;
    push(i);
    if (l > vr[i] || r < vl[i] || (l <= vl[i] && r >= vr[i]))
        return;
    range_add(l, r, d, 2*i);
    range_add(l, r, d, 2*i+1);
    v[i] = min(v[2*i], v[2*i+1]);
}

int argmin() {
    int i = 1;
    while (i < N) {
        push(i), push(2*i), push(2*i+1);
        i = v[2*i] <= v[2*i+1] ? 2*i : 2*i+1;
    }
    return i-N;
}

int get(int i) {
    int j = 1;
    while (j < N) {
        push(j);
        j = vl[2*j+1] <= i ? 2*j+1 : 2*j;
    }
    push(N+i);
    return v[N+i];
}

struct {

    int a[N], bad = 0;

    void put(int x, int i) {
        if (a[(i+1)%(n+1)] < a[i]) bad--;
        if (a[i] < a[(i+n)%(n+1)]) bad--;
        a[i] = x;
        if (a[(i+1)%(n+1)] < a[i]) bad++;
        if (a[i] < a[(i+n)%(n+1)]) bad++;
    }

    bool sorted() {
        return bad == 1;
    }

} pl, pr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < 2*n+1; i++) {
        cin >> p[i], p[i]--;
        pi[p[i]] = i;
    }

    build();

    for (int x = 0; x < 2*n+1; x++) {
        if (p[x] >= n) pr.put(x, p[x]-n);
        if (p[x] <= n) pl.put(x, p[x]);
    }

    while (q--) {
        int x, y; cin >> x >> y; x--, y--;
        if (x > y) swap(x, y);

        range_add(x, y-1, sgn(p[y])-sgn(p[x]));

        swap(p[x], p[y]);
        swap(pi[p[x]], pi[p[y]]);

        if (p[x] >= n) pr.put(x, p[x]-n);
        if (p[x] <= n) pl.put(x, p[x]);
        if (p[y] >= n) pr.put(y, p[y]-n);
        if (p[y] <= n) pl.put(y, p[y]);

        bool is_bbs = get(argmin()) == get(pi[n]);
        bool l_sorted = pl.sorted();
        bool r_sorted = pr.sorted();

        // if not a BBS, pick the argmin
        if (!is_bbs)
            cout << ((argmin()+1)%(2*n+1)) << "\n";

        // if a BBS and not sorted, ans is left or right of pi[n]
        else if (!r_sorted)
            cout << pi[n] << "\n";
        else if (!l_sorted)
            cout << ((pi[n]+1)%(2*n+1)) << "\n";

        // if a BBS and sorted, ans is -1 
        else
            cout << "-1\n";
    }
}