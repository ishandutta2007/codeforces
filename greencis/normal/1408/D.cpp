#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pii> robbers(n), lights(m);
    for (int i = 0; i < n; ++i) {
        cin >> robbers[i].first >> robbers[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> lights[i].first >> lights[i].second;
    }
    for (int i = 0; i < n; ++i) {
        bool bad = false;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (robbers[j].first <= robbers[i].first && robbers[j].second <= robbers[i].second) {
                bad = true;
                break;
            }
        }
        if (bad) {
            robbers.erase(robbers.begin() + i);
            --i;
            --n;
        }
    }
    for (int i = 0; i < m; ++i) {
        bool bad = false;
        for (int j = 0; j < m; ++j) {
            if (i == j) continue;
            if (lights[j].first >= lights[i].first && lights[j].second >= lights[i].second) {
                bad = true;
                break;
            }
        }
        if (bad) {
            lights.erase(lights.begin() + i);
            --i;
            --m;
        }
    }
    sort(all(robbers));
    sort(all(lights));

    int ptr = 0;
    vector<int> closest(n);
    vector<int> when(n);
    vector<int> to_up(n);
    multiset<int> st;
    set<pii> times;
    for (int i = 0; i < n; ++i) {
        while (ptr < m && robbers[i].first > lights[ptr].first)
            ++ptr;
        closest[i] = ptr;
        when[i] = (closest[i] == m ? 1e9 : lights[closest[i]].first - robbers[i].first + 1);
        to_up[i] = (closest[i] == m ? 0 : max(0, lights[closest[i]].second - robbers[i].second + 1));
        st.insert(to_up[i]);
        times.emplace(when[i], i);
    }
    int ans = *st.rbegin();
    while (times.begin()->first != (int)1e9) {
        int curtm = times.begin()->first;
        int i = times.begin()->second;
        times.erase(times.begin());
        st.erase(st.find(to_up[i]));
        ++closest[i];
        when[i] = (closest[i] == m ? 1e9 : lights[closest[i]].first - robbers[i].first + 1);
        to_up[i] = (closest[i] == m ? 0 : max(0, lights[closest[i]].second - robbers[i].second + 1));
        st.insert(to_up[i]);
        times.emplace(when[i], i);
        ans = min(ans, curtm + *st.rbegin());
    }
    cout << ans << endl;
}