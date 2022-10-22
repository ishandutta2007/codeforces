#include<bits/stdc++.h>
using namespace std;
const int N = 501;
const int C = 1 << 10;
int n, m;
int a[N][N];
bool dp[N][C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);                                        
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int t = 0; t < C; ++t) {
                if (dp[i][t]) {
                    dp[i + 1][t ^ a[i][j]] = 1;
                }   
            }   
        }   
    }   
    int nd = -1;
    for (int i = 1; i < C; ++i) {
        if (dp[n][i]) {
            nd = i;
            break;
        }   
    }   
    if (nd == -1) {
        cout << "NIE\n";
        exit(0);
    }   
    else {
        cout << "TAK\n";
        int w = nd;
        vector <int> ans;
        for (int i = n - 1; i >= 0; --i) {
            int add = -1;
            for (int j = 0; j < m; ++j) {
                if (dp[i][w ^ a[i][j]]) {
                    add = j;
                    break;
                }   
            }   
            w ^= a[i][add];
            ans.push_back(add);
        }   
        reverse(ans.begin(), ans.end());
        for (int e : ans) cout << e + 1 << ' ';
        cout << '\n';
    }   
}