#include<bits/stdc++.h>
#define MN 300000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s[MN+5];
int n,a[MN+5],b[MN+5],g[MN+5],*f[MN+5],mx[MN+5];
struct Big
{
    int s[1255],len;
    //Big(){len=0;memset(s,0,sizeof(s));}
    int operator / (int y)
    {
        long long x=0;
        for(int j=len;j--;) 
            x=int(1e8)*x+s[j],s[j]=x/y,x%=y;
        for(;len&&s[len-1]==0;--len);
        return x;
    }
}S;
int main()
{
    n=read();
    for(int i=1;i<n;++i) a[i]=read();
    for(int i=1;i<=n;++i) b[i]=read();
    scanf("%s",s+1);int m=strlen(s+1);
    for(int i=m;i>0;i-=8)
    {
        for(int j=max(1,i-7);j<=i;++j)
            S.s[S.len]=S.s[S.len]*10+s[j]-'0';
        ++S.len;
    }
    while(S.len&&S.s[S.len-1]==0) --S.len;
    if(!S.len) return 0*puts("1");
    f[0]=new int[2];f[0][0]=1;
    for(int i=1,j;i<=n;i=j+1)
    {
        int sum=mx[i-1]+b[i];
        for(j=i;j<n&&a[j]==1;)sum+=b[++j];
        for(int k=0;k<=sum;++k) g[k]=(k<=mx[i-1]?f[i-1][k]:0)%mod;
        for(int l=i;l<=j;++l)
        {
            for(int k=1;k<=sum;++k) g[k]=(g[k]+g[k-1])%mod;
            for(int k=sum;~k;--k) g[k]=(g[k]-(k-b[l]>0?g[k-b[l]-1]:0)+mod)%mod;
       //     for(int k=0;k<=sum;++k) printf("g[%d]=%d\n",k,g[k]);
        }
        if(j==n)
        {
            if(S.len>1) return 0*puts("0");
            int x=S.len?S.s[0]:0;
            printf("%d\n",x>sum?0:g[x]);
        }
        else
        {
            int left=S/a[j];if(sum<left) return 0*puts("0");
            mx[j]=(sum-left)/a[j];f[j]=new int[mx[j]+2];
            for(int k=0;k<=mx[j];++k) f[j][k]=g[k*a[j]+left];
        }
    }
    return 0;
}