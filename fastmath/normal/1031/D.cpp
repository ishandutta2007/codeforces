#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2007;

char a[MAXN][MAXN];

int n, k;
void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }
}

const int INF = 1e9 + 7;

int dp[MAXN][MAXN];

int get(int i, int j) {
    if (i < 0 || j < 0) return INF;
    else return dp[i][j];
}

char getcc(int i, int j) {
    if (i == n || j == n) return 'z' + 1;
    else return a[i][j];
}

void solve() {
    dp[0][0] = (a[0][0] != 'a');    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j == 0) continue;
            dp[i][j] = min(get(i - 1, j), get(i, j - 1)) + (a[i][j] != 'a');
        }
    }
    if (dp[n - 1][n - 1] <= k) {
        for (int i = 0; i < n + n - 1; ++i) cout << 'a';
        cout << '\n';
        exit(0);
    }   
    else {
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] <= k) mx = max(mx, i + j);
            }
        }   
        set <pair <int, int> > v;
        if (mx == -1) {
            v.insert({0, 0});
            cout << a[0][0];
        }
        else {
            for (int i = 0; i <= mx; ++i) cout << 'a';
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] <= k && i + j == mx) v.insert({i, j});
                }
            }
        }
        for (int i = 0; i < (n + n - 1) - max(1, (mx + 1)); ++i) {
            char c = 'z';
            for (auto e : v) {
                c = min(c, getcc(e.first + 1, e.second));
                c = min(c, getcc(e.first, e.second + 1));
            }   
            set <pair <int, int> > nv;
            for (auto e : v) {
                if (getcc(e.first + 1, e.second) == c) nv.insert({e.first + 1, e.second});
                if (getcc(e.first, e.second + 1) == c) nv.insert({e.first, e.second + 1});
            }
            cout << c;
            v = nv;
        }
        cout << '\n';
    }   
}

void print() {
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}