#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

vector<pair<int, int>> a, b;
vector<int> c;
int n, m, s;

vector<int> check(int mid) {
    int it = 0;
    vector<int> ans(m);
    long long ans_val = 0;
    map<pair<int, int>, int> t;
    for (int i = 0; i < m;) {
        while (it < n && b[it].first >= a[i].first) {
            t[{c[b[it].second], b[it].second}] = 0;
            ++it;
        }
        if (!t.size())
            return {};
        auto z = *t.begin();
        ans_val += z.first.first;
        for (int j = 0; j < mid && i < m; ++j, ++i) {
            ans[a[i].second] = z.first.second;
        }
        t.erase(z.first);
    }
    if (ans_val > s)
        return {};
    return ans;
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        a.emplace_back(tmp, i);
    }
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        b.emplace_back(tmp, i);
    }
    sort(rall(a));
    sort(rall(b));
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        c.emplace_back(tmp);
    }
    int left = 0, right = m + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (check(mid).size())
            right = mid;
        else
            left = mid;
    }
    if (right == m + 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        auto z = check(right);
        for (int i : z)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}