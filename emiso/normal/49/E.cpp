#include <bits/stdc++.h>

using namespace std;

int n, x[2][55], dp[2][26][55][55], sz[2], ans[55][55];
vector<pair<int, int>> go[26];
string s[2];


int main() {
    cin >> s[0] >> s[1] >> n;

    for(int t = 0; t < 2; t++) {
        sz[t] = s[t].size();
        for(int i = 0; i < s[t].size(); i++)
            x[t][i] = s[t][i] - 'a';
    }

    for(int i = 0; i < n; i++) {
        char x, y, z;
        scanf(" %c->%c%c", &x, &y, &z);
        go[x-'a'].push_back({y-'a', z-'a'});
    }

    for(int t = 0; t < 2; t++) {
        for(int l = 0; l < sz[t]; l++)
            dp[t][x[t][l]][l][l] = 1;

        for(int d = 1; d < sz[t]; d++) {
            for(int l = 0; l + d < sz[t]; l++) {
                int r = l + d;
                for(int c = 0; c < 26; c++) {
                    for(pair<int, int> rule : go[c]) {
                        for(int k = l; k < r; k++) {
                            if(dp[t][rule.first][l][k] && dp[t][rule.second][k+1][r])
                                dp[t][c][l][r] = 1;
                        }
                    }
                }
            }
        }
    }

    memset(ans, 0x7f, sizeof ans);
    ans[sz[0]][sz[1]] = 0;
    for(int i = sz[0]-1; i >= 0; i--) {
        for(int j = sz[1]-1; j >= 0; j--) {
            for(int k = i; k < sz[0]; k++) {
                for(int l = j; l < sz[1]; l++) {
                    for(int c = 0; c < 26; c++) {
                        if(dp[0][c][i][k] && dp[1][c][j][l])
                            ans[i][j] = min(ans[i][j], 1 + ans[k+1][l+1]);
                    }
                }
            }
        }
    }

    printf("%d\n", (ans[0][0] < 50) ? ans[0][0] : -1);
    return 0;
}