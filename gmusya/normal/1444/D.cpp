#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

bool cmp(pair<int,int> a, pair<int, int> b) {
  return a.first * 1ll * b.second > b.first * 1ll * a.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vector <int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        cin >> m;
        vector <int> l(m);
        for (int i = 0; i < m; i++)
            cin >> l[i];
        if (n != m) {
            cout << "No\n";
            continue;
        }
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(l.begin(), l.end(), rng);
        shuffle(h.begin(), h.end(), rng);
        {
            vector<vector<short>> dp(n + 1, vector<short>(n * 500 + 1, -1));
            dp[0][n * 250] = 0;
            for (int i = 1; i <= n; i++) {
                int x = h[i - 1];
                for (int j = 0; j <= n * 500; j++) {
                    if (dp[i - 1][j] == -1)
                        continue;
                    if (j + x <= n * 500)
                        dp[i][x + j] = 1;
                    if (j - x >= 0)
                        dp[i][j - x] = 0;
                }
            }
            if (dp[n][n * 250] == -1) {
                cout << "No\n";
                continue;
            }
            int pos = n * 250;
            int x = n;
            while (x--) {
                if (dp[x + 1][pos] == 0)
                    h[x] = -h[x];
                pos -= h[x];
            }
        }
        {
            vector<vector<short>> dp(n + 1, vector<short>(n * 500 + 1, -1));
            dp[0][n * 250] = 0;
            for (int i = 1; i <= n; i++) {
                int x = l[i - 1];
                for (int j = 0; j <= n * 500; j++) {
                    if (dp[i - 1][j] == -1)
                        continue;
                    if (j + x <= n * 500)
                        dp[i][x + j] = 1;
                    if (j - x >= 0)
                        dp[i][j - x] = 0;
                }
            }
            if (dp[n][n * 250] == -1) {
                cout << "No\n";
                continue;
            }
            int x = n;
            int pos = n * 250;
            while (x--) {
                if (dp[x + 1][pos] == 0)
                    l[x] = -l[x];
                pos -= l[x];
            }
        }
        vector<int>left, right, up, down;
        for (int i = 0; i < n; i++) {
            if (h[i] < 0)
                left.push_back(-h[i]);
            else
                right.push_back(h[i]);
            if (l[i] < 0)
                up.push_back(-l[i]);
            else
                down.push_back(l[i]);
        }
        if (right.size() > left.size())
            swap(left, right);
        if (down.size() > up.size())
            swap(down, up);
        vector<pair<int,int>> a, b, c;
        while (!right.empty()) {
            a.push_back({right.back(), up.back()});
            right.pop_back(), up.pop_back();
        }
        while (!down.empty()) {
            c.push_back({left.back(), down.back()});
            left.pop_back(), down.pop_back();
        }
        while (!left.empty()) {
            b.push_back({left.back(), up.back()});
            left.pop_back(), up.pop_back();
        }
        sort(a.begin(), a.end(), cmp);
        sort(c.begin(), c.end(), cmp);
        int x = 0, y = 0;
        cout << "Yes\n";
        for (int i = 0; i < (int)c.size(); i++) {
          x -= c[i].first;
          cout << x << ' ' << y << '\n';
          y -= c[i].second;
          cout << x << ' ' << y << '\n';
        }
        for (int i = 0; i < (int)a.size(); i++) {
          x += a[i].first;
          cout << x << ' ' << y << '\n';
          y += a[i].second;
          cout << x << ' ' << y << '\n';
        }
        for (int i = 0; i < (int)b.size(); i++) {
          x -= b[i].first;
          cout << x << ' ' << y << '\n';
          y += b[i].second;
          cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}