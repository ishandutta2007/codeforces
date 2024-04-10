#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

struct line {
    long long a, b, c;
    line (int x1, int y1, int x2, int y2) {
        a = y2 - y1;
        b = x1 - x2;
        c = 1ll * y1 * (x2 - x1) - x1 * (y2 - y1);
        
        long long d = gcd(a, gcd(b, c));
        a /= d, b /= d, c /= d;
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        }
        if (a == 0 && b < 0) {
            a = -a;
            b = -b;
            c = -c;
        }
    }
};

bool operator<(const line a, const line b) {
    return tuple(a.a, a.b, a.c) < tuple(b.a, b.b, b.c);
}

long long calc(int n) {
    return 1ll * n * (n - 1) * (n - 2) / 6;
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i += 1) {
        cin >> a[i].first >> a[i].second;   
    }
    map<line, int> cnt;
    for (int i = 0; i < n; i += 1) {
        for (int j = i + 1; j < n; j += 1) {
            cnt[line(a[i].first, a[i].second, a[j].first, a[j].second)]++;
        }
    }
    vector<int> val(n * n);
    for (int i = 1; i <= n; i += 1) {
        val[i * (i - 1) / 2] = i;
    }
    long long ans = calc(n);
    for (auto i : cnt) {
        ans -= calc(val[i.second]);
    }
    cout << ans << '\n';
}