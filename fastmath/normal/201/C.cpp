#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
    
int n;
int a[MAXN];
void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) cin >> a[i];
}

int ans = 0;
int l[MAXN], r[MAXN];
int pref[MAXN];
void solve() {
    l[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == 1) l[i] = 0;
        else l[i] = l[i - 1] + ((a[i - 1] >> 1) << 1);
    }

    r[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] == 1) r[i] = 0;
        else r[i] = r[i + 1] + ((a[i] >> 1) << 1);
    }

    pref[0] = 0;
    for (int i = 1; i < n; ++i) {
        int t = a[i - 1] - 1;
        pref[i] = pref[i - 1] + 1 + ((t >> 1) << 1);
    }

    int best = -1;
    for (int i = 0; i < n; ++i) {
        best = max(best, l[i] - pref[i]);
        ans = max(ans, best + pref[i] + r[i]);
    }   
}

void print() {
    cout << ans << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}