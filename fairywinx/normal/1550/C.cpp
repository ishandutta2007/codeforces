#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> nxt(n, make_pair(-1, -1));
    {
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && a[st.back()] <= a[i]) {
                nxt[st.back()].first = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }
    {
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (st.size() && a[st.back()] >= a[i]) {
                nxt[st.back()].second = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }

    int r = 0;
    long long ans = 0;
    multiset<int> a1, a2;
    vector<vector<int>> del1(n), del2(n);
    for (int i = 0; i < n; ++i) {
        while (r < n) {
            if ((a2.size() && a[r] >= *a2.begin()) || (a1.size() && a[r] <= *a1.rbegin())) {
                break;
            } else {
                if (nxt[r].first >= i) {
                    a1.emplace(a[r]);
                    del1[nxt[r].first].push_back(a[r]);
                } if (nxt[r].second >= i) {
                    a2.emplace(a[r]);
                    del2[nxt[r].second].push_back(a[r]);
                }
                ++r;
            }
        }
        while (del1[i].size()) {
            a1.erase(a1.find(del1[i].back()));
            del1[i].pop_back();
        }
        while (del2[i].size()) {
            a2.erase(a2.find(del2[i].back()));
            del2[i].pop_back();
        }
        ans += r - i;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}