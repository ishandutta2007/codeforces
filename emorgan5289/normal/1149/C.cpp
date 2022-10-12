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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5, S = 450;
int a[N], d[N], mn[N], mx[N];
int ans[N], pre[N], suf[N];
int pmax[N], smax[N];
int n;

void fix(int b) {
    mn[b] = inf, mx[b] = -inf;
    for (int i = b*S; i < (b+1)*S; i++)
        cmin(mn[b], a[i]+d[b]), cmax(mx[b], a[i]+d[b]);
    pmax[0] = a[b*S]+d[b];
    smax[S-1] = a[b*S+S-1]+d[b];
    for (int i = 1; i < S; i++)
        pmax[i] = max(pmax[i-1], a[b*S+i]+d[b]);
    for (int i = S-2; i >= 0; i--)
        smax[i] = max(smax[i+1], a[b*S+i]+d[b]);
    ans[b] = pre[b] = suf[b] = -inf;
    for (int i = 0; i < S; i++) {
        cmax(ans[b], -2*(a[b*S+i]+d[b])+pmax[i]+smax[i]);
        cmax(suf[b], -2*(a[b*S+i]+d[b])+smax[i]);
        cmax(pre[b], -2*(a[b*S+i]+d[b])+pmax[i]);
    }
}

void add(int l, int r, int x) {
    if (l/S == r/S) {
        int b = l/S;
        for (int i = l; i <= r; i++)
            a[i] += x;
        fix(b);
    } else {
        add(l, (l/S+1)*S-1, x);
        add((r/S)*S, r, x);
        for (int i = l/S+1; i < r/S; i++) {
            d[i] += x, mx[i] += x, mn[i] += x;
            pre[i] -= x, suf[i] -= x;
        }
    }
}

int get() {
    int r = -inf;
    int m = (2*n-3)/S+1;
    for (int i = 0; i < m; i++)
        cmax(r, ans[i]);
    pmax[0] = mx[0];
    smax[m-1] = mx[m-1];
    for (int i = 1; i < m; i++)
        pmax[i] = max(pmax[i-1], mx[i]);
    for (int i = m-2; i >= 0; i--)
        smax[i] = max(smax[i+1], mx[i]);
    for (int i = 1; i < m-1; i++)
        cmax(r, pmax[i-1]+smax[i+1]-2*mn[i]);
    for (int i = 0; i < m-1; i++) {
        cmax(r, pre[i]+smax[i+1]);
        cmax(r, pmax[i]+suf[i+1]);
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < 2*(n-1); i++) {
        a[i] = (i == 0 ? 0 : a[i-1])+(s[i] == '(' ? 1 : -1);
    }
    for (int i = 0; i < (2*n-3)/S+1; i++)
        fix(i);
    cout << get() << "\n";
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        if (l > r) swap(l, r);
        swap(s[l], s[r]);
        add(l, r-1, s[l] == '(' ? 2 : -2);
        cout << get() << "\n";
    }
}