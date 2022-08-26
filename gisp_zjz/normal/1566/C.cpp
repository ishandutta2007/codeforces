#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int mex[4]={0,1,0,2};
int _,n,k,dp[maxn],a[maxn];
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) a[i]=0;
        scanf("%s",s+1);
        for (int i=1;i<=n;i++) a[i]|=1<<(s[i]-'0');
        scanf("%s",s+1);
        for (int i=1;i<=n;i++) a[i]|=1<<(s[i]-'0');
        dp[1]=mex[a[1]];
        for (int i=2;i<=n;i++)
            dp[i]=max(dp[i-1]+mex[a[i]],dp[i-2]+mex[a[i]|a[i-1]]);
        printf("%d\n",dp[n]);
    }
    return 0;
}