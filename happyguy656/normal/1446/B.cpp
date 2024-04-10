#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,m,p1[5003][666],p2[5003][666];char s1[5003],s2[5003];
int dp[5003][5003];
int main(){
    cin>>n>>m>>s1+1>>s2+1;
    for(int i=n;i;--i)memcpy(p1[i],p1[i+1],sizeof(p1[i+1])),p1[i][s1[i]]=i;
    for(int i=m;i;--i)memcpy(p2[i],p2[i+1],sizeof(p2[i+1])),p2[i][s2[i]]=i;
    int ans=0;
    for(int i=n;i;--i)for(int j=m;j;--j){
        if(s1[i]!=s2[j]){
            dp[i][j]=max(dp[i+1][j+1]-2,0);
            int k=p1[i][s2[j]];if(k)dp[i][j]=max(dp[i][j],dp[k][j]-(k-i));
            k=p2[j][s1[i]];if(k)dp[i][j]=max(dp[i][j],dp[i][k]-(k-j));
        }
        else dp[i][j]=dp[i+1][j+1]+2;
        ans=max(ans,dp[i][j]);
    }
    printf("%d\n",ans);
    return 0;
}