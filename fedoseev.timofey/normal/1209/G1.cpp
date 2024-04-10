#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

int fir[N], lst[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < N; ++i) {
        fir[i] = lst[i] = -1;
    }
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        fir[a[i]] = i;
    }
    vector <pair <int, int>> ev;
    for (int i = 0; i < N; ++i) {
        if (fir[i] != -1) {
            ev.push_back({fir[i], -1});
            ev.push_back({lst[i], 1});
        }
    }
    sort(ev.begin(), ev.end());
    int lst = 0;
    int bal = 0;
    vector <pair <int, int>> seg;
    for (auto p : ev) {
        if (p.second == -1) {
            ++bal;
            if (bal == 1) lst = p.first;
        } else {
            --bal;
            if (bal == 0) {
                seg.push_back({lst, p.first});
            }
        }
    }
    int ans = 0;
    for (auto p : seg) {
        map <int, int> cnt;
        for (int i = p.first; i <= p.second; ++i) ++cnt[a[i]];
        int cur = 1e9;
        for (auto pr : cnt) {
            cur = min(cur, p.second - p.first + 1 - pr.second);
        }
        ans += cur;
    }
    cout << ans << '\n';
}