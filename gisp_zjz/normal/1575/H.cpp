#include<bits/stdc++.h>
using namespace std;
const int inf=1000;
int dp[505][505],tmp[505][505],n,m,nxt[505][2];
char s[505],t[505],z[505];
void Min(int &x,int y){
    if (x>y) x=y;
}
int F(int x){
    for (int i=x;i;i--) if (!strncmp(t+1,z+(x-i+1),i)) return i;
    return 0;
}
int main(){
    cin >> n >> m;
    cin >> s+1 >> t+1;
    for (int i=0;i<=m;i++){
        for (int j=1;j<=i;j++) z[j]=t[j];
        z[i+1]='0';
        nxt[i][0]=F(i+1);
        z[i+1]='1';
        nxt[i][1]=F(i+1);
    }
    for (int i=0;i<=n-m+1;i++)
        for (int j=0;j<=m;j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for (int i=1;i<=n;i++){
        int o=s[i]-'0';
        memcpy(tmp,dp,sizeof(dp));
        for (int j=0;j<=n-m+1;j++)
            for (int k=0;k<=m;k++)
                dp[j][k]=inf;
        for (int j=0;j<=n-m+1;j++)
        for (int k=0;k<=m;k++){
            if (tmp[j][k]==inf) continue;
            int l;
            l=nxt[k][o];
            Min(dp[j+(l==m)][l],tmp[j][k]);
            l=nxt[k][o^1];
            Min(dp[j+(l==m)][l],tmp[j][k]+1);
        }
    }
    for (int i=0;i<=n-m+1;i++){
        int ans=inf;
        for (int j=0;j<=m;j++) Min(ans,dp[i][j]);
        if (ans==inf) printf("-1 "); else printf("%d ",ans);
    }
    puts("");
    return 0;
}