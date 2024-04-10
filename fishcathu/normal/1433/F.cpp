#include<cstdio>
#include<cstring>
const int N=72;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
int a[N],dp[N>>1][N],ans[N],b[N];
int main()
{
    int n=read(),m=read(),h=m>>1,p=read();
    memset(ans,-1,sizeof ans),ans[0]=0;
    while(n--)
    {
        for(int i=m;i--;)a[i]=read();
        memset(dp,-1,sizeof dp),dp[0][0]=0;
        for(int i=m;i--;)for(int j=h;j--;)for(int k=p;k--;)if(~dp[j][k]&&dp[j][k]+a[i]>dp[j+1][(k+a[i])%p])dp[j+1][(k+a[i])%p]=dp[j][k]+a[i];
        memset(a,0,sizeof a),memcpy(b,ans,sizeof ans);
        for(int i=p;i--;)for(int j=h;j;--j)if(dp[j][i]>a[i])a[i]=dp[j][i];
        for(int i=p;i--;)for(int j=p;j--;)if(a[i]&&~b[j]&&a[i]+b[j]>ans[(i+j)%p])ans[(i+j)%p]=a[i]+b[j];
    }
    printf("%d",ans[0]);
    return 0;
}