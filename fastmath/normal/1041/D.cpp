#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;
const int INF = 1e10 + 7;

int l[MAXN], r[MAXN], a[MAXN];
int pref[MAXN];

int getsum(int l, int r) {
    return pref[r] - pref[l];
}

int pr[MAXN];

int get(int l, int r) {
    return pr[r + 1] - pr[l];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);                                    

    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    for (int i = 0; i < n; ++i) {
        pr[i + 1] = pr[i] + (r[i] - l[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        a[i] = l[i + 1] - r[i];
    }
    a[n - 1] = INF;

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    int ans = h;
    for (int i = 0; i < n; ++i) {
        int l = i - 1;
        int r = n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (getsum(i, m) < h) l = m;
            else r = m;
        }
        ans = max(ans, h + get(i, l));
    }   

    cout << ans << '\n';
    return 0;
}