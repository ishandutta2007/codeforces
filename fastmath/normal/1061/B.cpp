#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

int n, m;
int a[MAXN];

bool check(int want, int m) {
    int ost = want - m;
    int p = n - 1 - ost;
    for (int i = 0; i < ost; ++i) {
        if (a[p + i] < i + 1) return 0;
    }   
    return 1;
}    

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);                 

    int mx = a[n - 1];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }
    ans -= n;

    int add = max(0ll, mx - n);
    ans -= add;

    int want = min(n, mx);

    int l = 0;
    int r = want;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(want, m)) r = m;
        else l = m;
    }   
    
    cout << ans - (r - 1) << '\n';
    return 0;
}