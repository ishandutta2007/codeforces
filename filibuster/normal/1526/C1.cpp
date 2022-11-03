#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 2e5 + 13;


//void solve() {
//    int n;
//    cin >> n;
//
//    vector<int> a(n * 2);
//    for(int i = 0; i < n * 2; i++) {
//        cin >> a[i];
//    }
//
//    sort(a.begin(), a.end());
//
//    for(int i = 0; i < n; i++) {
//        cout << a[i] << ' ' << a[n + i] << ' ';
//    }
//    cout << endl;
//}

li t[N * 4], d[4 * N];

void build() {};

void push(int v) {
    d[v * 2 + 1] += d[v];
    t[v * 2 + 1] += d[v];
    d[v * 2 + 2] += d[v];
    t[v * 2 + 2] += d[v];
    d[v] = 0;
}

void upd(int v, int l, int r, int ql, int qr, int x) {
    if(l >= qr || r <= ql)
        return;

    if(ql <= l && r <= qr) {
        d[v] += x;
        t[v] += x;
        return;
    }

    push(v);

    int m = (l + r) / 2;
    upd(v * 2 + 1, l, m, ql, qr, x);
    upd(v * 2 + 2, m, r, ql, qr, x);

    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

//void get(int v, int l, int r, int ql, i)


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    vector<int> a(n);
    vector<pii> b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(b.rbegin(), b.rend());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        upd(0, 0, n, b[i].s, n, b[i].f);
        if(t[0] < 0) {
            upd(0, 0, n, b[i].s, n, -b[i].f);
        } else {
            ans++;
        }
    }

    cout << ans << endl;
}