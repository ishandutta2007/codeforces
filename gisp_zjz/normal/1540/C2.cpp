#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=1000000007;
int n,x,b[105],s[105],c[105],dp[105][10005],S[10005],sum,tot,q,ans[105],best,sumc[105];
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
int _round(int x,int y){while (x%y) x--;return x/y;}
int main(){
    scanf("%d",&n); tot=1;
    for (int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
        tot=1ll*tot*(c[i]+1)%M;
        sumc[i]=sumc[i-1]+c[i];
    }
    for (int i=1;i<n;i++) scanf("%d",&b[i]);
    for (int i=1;i<n;i++) b[i]+=b[i-1],s[i]=s[i-1]+b[i];
    best=c[1]; for (int i=2;i<=n;i++) best=min(best,_round(sumc[i]-s[i-1],i));
    for (int p=0;p<=101;p++){
        memset(dp,0,sizeof(dp));
        sum=0; dp[0][0]=1; x=best-p;
        for (int i=1;i<=n;i++){
            sum+=c[i]; S[0]=dp[i-1][0];
            for (int j=1;j<=sum;j++) S[j]=(S[j-1]+dp[i-1][j])%M;
            for (int j=0;j<=sum;j++){
                if (j<x*i+s[i-1]) dp[i][j]=0;
                else {
                    dp[i][j]=S[j];
                    if (j>c[i]) sub(dp[i][j],S[j-c[i]-1]);
                }
            }
        }
        ans[p]=0; for (int i=0;i<=sum;i++) add(ans[p],dp[n][i]);
    }
    scanf("%d",&q);
    while (q--){
        int x; scanf("%d",&x);
        if (x>best) puts("0"); else printf("%d\n",ans[min(101,best-x)]);
    }
    return 0;
}