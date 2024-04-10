#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5;
int b[N], f[N], v[N], a[N], c[N];
multiset<pair<int, int>, greater<>> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        fill(f, f+n+2, 0);
        fill(v, v+n+2, 0);
        fill(c, c+n+2, 0);
        int m = n;
        for (int i = 0; i < n; i++)
            cin >> b[i], f[b[i]]++;
        s.clear();
        for (int i = 1; i <= n+1; i++)
            if (f[i] > 0) s.insert({f[i], i});
        for (int i = 0; i < x; i++) {
            auto [cnt, r] = *s.begin(); s.erase(s.begin());
            c[r]++; m--;
            if (cnt > 1) s.insert({cnt-1, r});
        }
        for (int i = 0; i < n; i++) {
            if (c[b[i]] > 0)
                c[b[i]]--, v[i] = 1, a[i] = b[i];
        }
        for (int i = 0; i < n-y; i++) {
            auto [cnt, r] = *s.begin(); s.erase(s.begin());
            if (cnt <= m/2) {
                s.insert({cnt, r});
                break;
            }
            if (cnt > 1) s.insert({cnt-1, r});
            c[r]++; m--;
        }
        int k = min_element(f+1, f+n+2)-f;
        for (int i = 0; i < n; i++) {
            if (!v[i] && c[b[i]] > 0)
                c[b[i]]--, v[i] = 1, a[i] = k;
        }
        if (s.empty()) {
            debug("Test");
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << "\n";
            continue;
        }
        auto [cnt, r] = *s.begin(); s.erase(s.begin());
        if (cnt > m/2) {
            cout << "NO\n";
            continue;
        }
        y -= x;
        s.insert({cnt, r});
        vector<pair<int, int>> vv;
        for (int i = 0; i < n; i++)
            if (!v[i]) vv.pb({b[i], i});
        sort(all(vv));
        for (int i = 0; i < vv.size(); i++) {
            auto [val, j] = vv[i];
            if (i >= y) a[j] = k;
            else a[j] = vv[(i+(m/2))%m].first;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}