#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        set<int> st;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            st.insert(v[i]);
        }
        bool good = false;
        for (int i = 0; i < n; ++i) {
            if (st.contains(k + v[i])) {
                good = true;
                break;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}