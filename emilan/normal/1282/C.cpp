#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, T;
        ll a, b;
        cin >> n >> T >> a >> b;

        int ez = 0, hr = 0;
        vector<array<int, 2>> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i][1];
            if (!p[i][1]) ez++;
            else hr++;
        }
        for (int i = 0; i < n; i++) {
            cin >> p[i][0];
        }
        sort(p.begin(), p.end());
        p.push_back({T + 1, -1});

        int m_ez = 0, m_hr = 0, ans = 0;
        for (int i = 0; i <= n; i++) {
            if (m_ez * a + m_hr * b < p[i][0]) {
                int t = p[i][0] - 1 - m_ez * a - m_hr * b;
                int cur = m_ez + m_hr;

                if (ez * a >= t) {
                    cur += t / a;
                } else {
                    t -= ez * a;
                    cur += ez;

                    if (hr * b >= t) {
                        cur += t / b;
                    } else {
                        cur += hr;
                    }
                }

                ans = max(cur, ans);
            }

            if (!p[i][1]) m_ez++, ez--;
            else m_hr++, hr--;
        }

        cout << ans << '\n';
    }
}