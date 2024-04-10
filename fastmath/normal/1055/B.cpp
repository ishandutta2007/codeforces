#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int n, m, l;
int a[MAXN];

int ans = 0;

int get() {
    return ans;
}

int tl[MAXN], tr[MAXN];
void upd(int p, int d) {
    if (a[p] <= l && a[p] + d > l) {
        if (p && a[p - 1] > l) {
            --ans;
        }
        if (p + 1 < n && a[p + 1] > l) {
            --ans;
        }   
        ++ans;
    }   
    a[p] += d;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        upd(i, x);
    }   

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            cout << get() << '\n';
        }   
        else {
            int p, d;
            cin >> p >> d;
            --p;
            upd(p, d);
        }   
    }   

    return 0;
}