#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=1000000007;
int n,x,b[105],s[105],c[105],dp[105][10005],sum,ans,tot,q;
void add(int &x,int y){x+=y;if (x>=M)x-=M;}
void sub(int &x,int y){x-=y;if (x<0) x+=M;}
int main(){
    scanf("%d",&n); tot=1;
    for (int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
        tot=1ll*tot*(c[i]+1)%M;
    }
    for (int i=1;i<n;i++) scanf("%d",&b[i]);
    scanf("%d%d",&q,&x);
    for (int i=1;i<n;i++) b[i]+=b[i-1],s[i]=s[i-1]+b[i];
    dp[0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=sum;j++)
            for (int k=0;k<=c[i];k++)
                add(dp[i][j+k],dp[i-1][j]);
        sum+=c[i];
        for (int j=0;j<=sum;j++){
            if (j<x*i+s[i-1]) dp[i][j]=0;
        }
    }
    ans=0;
    for (int i=0;i<=sum;i++) add(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}