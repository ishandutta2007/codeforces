#include<bits/stdc++.h>
using namespace std;
const int T=6000;
int n,k,w[90][90],dp[15][90],f[90],ans,p,q,a[90],b[90];
mt19937_64 gen(time(0));
const int inf=1e9+2;
void Min(int &x,int y){
    if (y<x) x=y;
}
int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin >> w[i][j];
    ans=inf;
    for (int _=0;_<T;_++){
        for (int i=2;i<=n;i++) f[i]=gen()%2;
        for (int i=0;i<=k;i++)
            for (int j=1;j<=n;j++)
                dp[i][j]=inf;
        dp[0][1]=0; p=0; q=0;
        for (int i=1;i<=n;i++){
            if (f[i]==0) a[++p]=i; else b[++q]=i;
        }
        for (int i=0;i<k;i++){
            if (i%2==0){
                for (int j=1;j<=p;j++)
                    for (int k=1;k<=q;k++)
                        Min(dp[i+1][b[k]],dp[i][a[j]]+w[a[j]][b[k]]);
            } else {
                for (int j=1;j<=q;j++)
                    for (int k=1;k<=p;k++)
                        Min(dp[i+1][a[k]],dp[i][b[j]]+w[b[j]][a[k]]);
            }
        }
        Min(ans,dp[k][1]);
    }
    cout << ans << endl;
}