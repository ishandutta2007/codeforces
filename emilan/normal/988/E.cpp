#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int inf = 1 << 30;

void solve() {
    string s;
    cin >> s;
    int n = sz(s);

    if (n == 1) return void(cout << -1);
    if (s.substr(n - 2) == "00") return void(cout << 0);

    int ans = inf;
    if (count(all(s), '0')) {
        string t(s);

        int dist_0 = (int)distance(t.rbegin(), find(rall(t), '0'));
        t.erase(t.begin() + n - dist_0 - 1);

        auto it_0 = find(rall(t), '0');
        auto it_5 = find(rall(t), '5');
        if (it_0 != it_5) {
            ans = dist_0 + (int)min(
                distance(t.rbegin(), it_0),
                distance(t.rbegin(), it_5)
            );
        }
    }

    if (int z = (int)count(all(s), '0');
            count(all(s), '5') && (!z || z < n - 2)) {
        string t(s);

        auto count_zeroes = [&]() {
            int i = 1;
            for (; i < n && s[i] == '0'; i++);
            return i - 1;
        };

        int dist_5 = (int)distance(t.rbegin(), find(rall(t), '5'));
        if (dist_5 == n - 1 && t[1] == '0') {
            auto it_2 = find(rall(t), '2');
            auto it_7 = find(rall(t), '7');
            if (it_2 != it_7) {
                ans = min(ans, 
                    n - 1 + count_zeroes() + (int)min(
                        distance(t.rbegin(), it_2),
                        distance(t.rbegin(), it_7)
                ));
            }
        } else {
            t.erase(t.begin() + n - dist_5 - 1);

            auto it_2 = find(rall(t), '2');
            auto it_7 = find(rall(t), '7');
            if (it_2 != it_7) {
                int dist = (int)min(
                    distance(t.rbegin(), it_2),
                    distance(t.rbegin(), it_7)
                );
                if (dist == n - 1) dist += count_zeroes();
                ans = min(ans, dist_5 + dist);
            }
        }
    }

    if (ans == inf) cout << -1;
    else cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}