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
    vector <int> p(n);
    vector <int> wh(n + 1);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) wh[p[i]] = i;
    vector <int> nxt(n);
    vector <int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
        if (st.empty()) nxt[i] = n - 1;
        else nxt[i] = st.back() - 1;
        st.push_back(i);
    }
    vector <int> prv(n);
    st.clear();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && p[st.back()] < p[i]) st.pop_back();
        if (st.empty()) prv[i] = 0;
        else prv[i] = st.back() + 1;
        st.push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = prv[i];
        int r = nxt[i];
        if (i - l < r - i) {
            for (int j = l; j < i; ++j) {
                if (p[j] < p[i] && i < wh[p[i] - p[j]] && wh[p[i] - p[j]] <= r) {
                    ++ans;
                } 
            }
        }
        else {
            for (int j = i + 1; j <= r; ++j) {
                if (p[j] < p[i] && l <= wh[p[i] - p[j]] && wh[p[i] - p[j]] < i) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
}