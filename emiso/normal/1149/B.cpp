#include <bits/stdc++.h>

#define MN 100100

using namespace std;
char s[MN], op, y; string str, r[3];

int n, q, x, nxt[MN][26], dp[251][251][251];

void calc(int i, int j, int k) {
    dp[i][j][k] = n+1;
    if(i == 0 && j == 0 && k == 0) dp[0][0][0] = 0;
    if(i && dp[i-1][j][k] <= n) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][r[0][i-1]-'a']+1);
    if(j && dp[i][j-1][k] <= n) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][r[1][j-1]-'a']+1);
    if(k && dp[i][j][k-1] <= n) dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][r[2][k-1]-'a']+1);
}

int main() {
    scanf("%d %d %s", &n, &q, s); str = s;

    fill_n(**dp, 251*251*251, n+1);
    dp[0][0][0] = 0;
    fill(nxt[n], nxt[n] + 26, n);

    for(int i = n-1; i >= 0; i--) {
        for(int c = 0; c < 26; c++)
            nxt[i][c] = nxt[i+1][c];
        nxt[i][str[i]-'a'] = i;
    }

    for(int i = 0; i < q; i++) {
        scanf(" %c %d", &op, &x); x--;

        if(op == '-') {
            r[x].pop_back();
        } else if(op == '+') {
            scanf(" %c", &y);
            r[x] += y;

            for(int i = r[0].size() * (x == 0); i <= r[0].size(); i++)
                for(int j = r[1].size() * (x == 1); j <= r[1].size(); j++)
                    for(int k = r[2].size() * (x == 2); k <= r[2].size(); k++)
                        calc(i, j, k);
        }

        puts(dp[r[0].size()][r[1].size()][r[2].size()] <= n ? "YES" : "NO");
    }
    return 0;
}