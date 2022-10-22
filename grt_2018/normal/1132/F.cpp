#include <bits/stdc++.h>

using namespace std;

const int MAXN = 501;
int n;
int dp[MAXN][MAXN];
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) dp[i][i] = 1;
    for(int i=1; i<n;i++) {
        for(int j=0; j+i<n; j++) {
            dp[j][i+j] = 1 + dp[j+1][i+j];
            for(int p=j+1; p<=i+j; p++) {
                if(s[j]==s[p]) {
                    dp[j][i+j] = min(dp[j][i+j],dp[j+1][p-1]+dp[p][i+j]);
                }
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}