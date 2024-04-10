#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 10000000;

int dp[105][105][15];
char dir[105][105][15];
int a[105][105];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, m, k;
    cin>>n>>m>>k;

    char ch;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>ch;
            a[i][j] = ch - '0';
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= k; j++){
            dp[n][i][j] = -inf;
        }
        dp[n][i][a[n][i]%(k+1)] = a[n][i];
    }
    for(int i = n-1; i >= 1; i--){
        for(int j = 2; j < m; j++){
            for(int l = 0; l <= k; l++){
                if(dp[i+1][j+1][l] > dp[i+1][j-1][l]){
                    dp[i][j][(l+a[i][j])%(k+1)] = dp[i+1][j+1][l] + a[i][j];
                    dir[i][j][(l+a[i][j])%(k+1)] = 'L';
                }else{
                    dp[i][j][(l+a[i][j])%(k+1)] = dp[i+1][j-1][l] + a[i][j];
                    dir[i][j][(l+a[i][j])%(k+1)] = 'R';
                }
            }
        }
        for(int l = 0; l <= k; l++){
            dp[i][1][(l+a[i][1])%(k+1)] = dp[i+1][2][l] + a[i][1];
            dir[i][1][(l+a[i][1])%(k+1)] = 'L';
            dp[i][m][(l+a[i][m])%(k+1)] = dp[i+1][m-1][l] + a[i][m];
            dir[i][m][(l+a[i][m])%(k+1)] = 'R';
        }
    }
    int ind = -1;
    for(int i = 1; i <= m; i++){
        if(dp[1][i][0] < 0)continue;
        if(ind == -1 || dp[1][i][0] > dp[1][ind][0])ind = i;
    }
    if(ind == -1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dp[1][ind][0]<<endl;
    int i = 1, j = ind, l = 0;
    string ans = "";
    while(i < n){
        ans = ans + dir[i][j][l];
        if(dir[i][j][l] == 'L'){
            l = (l - a[i][j])%(k+1);
            l = (l + k + 1)%(k + 1);
            i = i + 1;
            j = j + 1;
        }else{
            l = (l - a[i][j])%(k+1);
            l = (l + k + 1)%(k + 1);
            i = i + 1;
            j = j - 1;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<j<<endl;
    cout<<ans<<endl;
}