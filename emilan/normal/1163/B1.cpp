#include <bits/stdc++.h>

using namespace std;

int f[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> m;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if (f[x] == 0) {
            m[1]++;
        } else {
            m[f[x]]--;
            if (m[f[x]] == 0) m.erase(f[x]);
            m[f[x] + 1]++;
        }

        f[x]++;

        if (m.size() == 1) {
            if (m.count(1) || m.begin()->second == 1) ans = i;
        } else if (m.size() == 2) {
            if ((m.count(1) && m[1] == 1)
                    || (m.begin()->first + 1 == m.rbegin()->first
                        && m.rbegin()->second == 1)) {
                ans = i;
            }
        }
    }

    cout << ans;
}