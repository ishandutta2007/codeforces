#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    set<int> st;
    multiset<int> diff;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (auto it = st.begin(); ; ++it) {
        auto nxt = next(it);
        if (nxt == st.end())
            break;
        diff.insert(*nxt - *it);
    }
    cout << (st.empty() ? 0 : *st.rbegin() - *st.begin() - (diff.empty() ? 0 : *diff.rbegin())) << '\n';
    while (q--) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 0) {
            auto it = st.find(x);
            int nxt_num = INT_MAX;
            auto nxt = next(it);
            if (nxt != st.end()) {
                nxt_num = *nxt;
                diff.erase(diff.find(nxt_num - *it));
            }
            int prv_num = INT_MIN;
            if (it != st.begin()) {
                auto prv = prev(it);
                prv_num = *prv;
                diff.erase(diff.find(*it - prv_num));
            }
            if (nxt_num != INT_MAX && prv_num != INT_MIN) {
                diff.insert(nxt_num - prv_num);
            }
            st.erase(it);
        } else {
            auto it = st.insert(x).first;
            int nxt_num = INT_MAX;
            auto nxt = next(it);
            if (nxt != st.end()) {
                nxt_num = *nxt;
            }
            int prv_num = INT_MIN;
            if (it != st.begin()) {
                auto prv = prev(it);
                prv_num = *prv;
            }
            if (nxt_num != INT_MAX && prv_num != INT_MIN) {
                diff.erase(diff.find(nxt_num - prv_num));
            }
            if (nxt_num != INT_MAX) {
                diff.insert(nxt_num - x);
            }
            if (prv_num != INT_MIN) {
                diff.insert(x - prv_num);
            }
        }
        cout << (st.empty() ? 0 : *st.rbegin() - *st.begin() - (diff.empty() ? 0 : *diff.rbegin())) << '\n';
    }
}