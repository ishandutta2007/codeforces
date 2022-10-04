#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector <int> tm(n, -1);
    vector <pair <int, int>> st;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            a[p] = x;
            tm[p] = i;
        }
        else {
            int x;
            cin >> x;
            while (!st.empty() && st.back().first <= x) st.pop_back();
            st.push_back({x, i});
        }
    }
    for (int i = 0; i < n; ++i) {
        int l = -1, r = (int)st.size();
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (st[m].second > tm[i]) r = m;
            else l = m;
        }
        if (r < st.size()) a[i] = max(a[i], st[r].first);
    }
    for (int i = 0; i < n; ++i) cout << a[i] << ' ';
}