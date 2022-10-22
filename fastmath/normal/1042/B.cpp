#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1007;
const int INF = 1e9 + 7;

int a[MAXN];
string s[MAXN];

int cost[MAXN][3];

vector <char> v = {'A', 'B', 'C'};

bool check(char c, string s) {
    for (char nc : s) if (nc == c) return 1;
    return 0;    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> s[i];

    for (int i = 0; i < n; ++i) {
        sort(s[i].begin(), s[i].end());
    }

    set <char> ms;
    for (int i = 0; i < n; ++i) {
        for (char c : s[i]) ms.insert(c);
    }   

    if (ms.size() < 3) {
        cout << "-1\n";
        exit(0);
    }

    cost[n][0] = cost[n][1] = cost[n][2] = INF;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 3; ++j) cost[i][j] = cost[i + 1][j];
        for (int j = 0; j < 3; ++j) {
            if (check(v[j], s[i])) {
                cost[i][j] = min(cost[i][j], a[i]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (s[i].size() == 3) ans = min(ans, a[i]);
    }   

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string t = s[i] + s[j];
            if (check(v[0], t) && check(v[1], t) && check(v[2], t)) {
                ans = min(ans, a[i] + a[j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string t = s[i] + s[j];
            if (check(v[0], t) && check(v[1], t)) {
                ans = min(ans, a[i] + a[j] + cost[i + 1][2]);
            }
            if (check(v[0], t) && check(v[2], t)) {
                ans = min(ans, a[i] + a[j] + cost[i + 1][1]);
            }
            if (check(v[1], t) && check(v[2], t)) {
                ans = min(ans, a[i] + a[j] + cost[i + 1][0]);
            }            
        }
    }

    cout << ans << '\n';
    return 0;
}