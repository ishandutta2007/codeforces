#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> st;
    set<int> s;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        s.insert(c[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (!s.count(b - c[i])) {
            st.push_back(c[i]);
        }
    }
    while (st.size()) {
        int x = st.back();
        st.pop_back();
        if (s.count(x)) {
            if (!s.count(a - x)) {
                cout << "NO\n";
                return 0;
            }
            s.erase(x);
            s.erase(a - x);
            if (s.count(b - (a - x))) {
                st.push_back(b - (a - x));
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (s.count(c[i])) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
}