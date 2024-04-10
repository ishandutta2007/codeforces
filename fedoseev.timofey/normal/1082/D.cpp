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
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pair <int, int>> ed;
    vector <int> who;
    vector <int> bad;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 2) {
            who.push_back(i);
        }
        else {
            bad.push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i + 1 < who.size(); ++i) {
        ed.push_back({who[i], who[i + 1]});
        --a[who[i]];
        --a[who[i + 1]];
    }
    ans = max(0, (int)who.size() - 1);
    if (!bad.empty() && !who.empty()) {
        ed.push_back({bad.back(), who.front()});
        --a[who.front()];
        --a[bad.back()];
        bad.pop_back();
        ++ans;
    }
    if (!bad.empty() && !who.empty()) {
        ed.push_back({bad.back(), who.back()});
        --a[who.back()];
        --a[bad.back()];
        bad.pop_back();
        ++ans;
    }
    for (auto x : bad) {
        bool fl = false;
        for (auto y : who) {
            if (a[y] >= 1) {
                fl = true;
                --a[y];
                ed.push_back({x, y});
                break;
            }
        }
        if (!fl) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES " << ans << '\n';
    cout << ed.size() << '\n';
    for (auto p : ed) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
}