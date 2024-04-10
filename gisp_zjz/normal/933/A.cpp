#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
int dp[5],n,k;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        scanf("%d",&k);
        dp[k]++; dp[k+2]++;
        for (int j=2;j<=4;j++) dp[j]=max(dp[j],dp[j-1]);
    }
    cout << max(dp[3],dp[4]) << endl;
    return 0;
}