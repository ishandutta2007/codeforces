#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int n;
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    set <int> ms;
    const int INF = 1e9 + 7;
    int mn = INF;
    int mx = -INF;
    map <int, int> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ms.insert(a[i]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        d[a[i]]++;
    }   
    if (ms.size() == 2 && d[mn] == d[mx]) {
        cout << "YES\n";
        cout << mn << ' ' << mx << '\n';
    }   
    else {
        cout << "NO\n";
    }   

    return 0;
}