#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
const int L = 256;
const int INF = 1e9 + 7;
const int C = 26;
int dp[L][L][L];
string a[3];
int mn[3];
int to[N][C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            for (int k = 0; k < L; ++k) {
                dp[i][j][k] = INF;
            }   
        }   
    }   
    dp[0][0][0] = 0;

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < C; ++i) {
        to[n][i] = INF;
    }   
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < C; ++j) {
            to[i][j] = to[i + 1][j];
        }   
        to[i][s[i] - 'a'] = i;
    }   

    while (q--) {
        char t;
        cin >> t;
        if (t == '+') {
            int i;
            char c;
            cin >> i >> c;
            --i;
            a[i] += c;
            for (int t = 0; t < 3; ++t) {
                mn[t] = 0;
            }
            mn[i] = a[i].size();
            for (int p0 = mn[0]; p0 <= a[0].size(); ++p0) {
                for (int p1 = mn[1]; p1 <= a[1].size(); ++p1) {
                    for (int p2 = mn[2]; p2 <= a[2].size(); ++p2) {
                        if (p0 && dp[p0 - 1][p1][p2] != INF) {
                            int pos = to[dp[p0 - 1][p1][p2]][a[0][p0 - 1] - 'a'];
                            if (pos != INF) {
                                dp[p0][p1][p2] = min(dp[p0][p1][p2], pos + 1);
                            }   
                        }   
                        if (p1 && dp[p0][p1 - 1][p2] != INF) {
                            int pos = to[dp[p0][p1 - 1][p2]][a[1][p1 - 1] - 'a'];
                            if (pos != INF) {
                                dp[p0][p1][p2] = min(dp[p0][p1][p2], pos + 1);
                            }   
                        }   
                        if (p2 && dp[p0][p1][p2 - 1] != INF) {
                            int pos = to[dp[p0][p1][p2 - 1]][a[2][p2 - 1] - 'a'];
                            if (pos != INF) {
                                dp[p0][p1][p2] = min(dp[p0][p1][p2], pos + 1);
                            }   
                        }   
                    }   
                }   
            }   

        }   
        else {
            int i;
            cin >> i;
            --i;
            for (int t = 0; t < 3; ++t) {
                mn[t] = 0;
            }
            mn[i] = a[i].size();
            for (int p0 = mn[0]; p0 <= a[0].size(); ++p0) {
                for (int p1 = mn[1]; p1 <= a[1].size(); ++p1) {
                    for (int p2 = mn[2]; p2 <= a[2].size(); ++p2) {
                        dp[p0][p1][p2] = INF;
                    }   
                }   
            }   
            a[i].pop_back();
        }   
        if (dp[a[0].size()][a[1].size()][a[2].size()] == INF) {
            cout << "NO\n";
        }   
        else {
            cout << "YES\n";
        }   
    }   
}