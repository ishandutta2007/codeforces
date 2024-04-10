#include<iostream>
#include<cstdio>
using namespace std;
int n,p[101],ans,tot[2],q[2][101];
inline int check()
{
    int cnt=0,res=0;
    for(register int i=1;i<=n+1;++i)
        if(p[i])
        {
            if(p[i]==p[cnt])
                ++q[p[i]-2][i-cnt-1];
            else
                ++res;
            cnt=i;
        }
    for(register int i=0;i<=1;++i)
    {
        int maxn=tot[i];
        for(register int j=0;j<=maxn;++j)
            while(q[i][j]&&j<=maxn)
            {
                maxn-=j;
                --q[i][j];
            }
    }
    for(register int i=0;i<=n;++i)
    {
        res+=(q[0][i]+q[1][i])<<1;
        q[0][i]=q[1][i]=0;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        puts("0");
        return 0;
    }
    tot[0]=n>>1;
    tot[1]=(n+1)>>1;
    for(register int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        if(x)
        {
            p[i]=2+(x&1);
            --tot[p[i]-2];
        }
    }
    ans=1<<30;
    for(register int i=2;i<=3;++i)
        for(register int j=2;j<=3;++j)
        {
            p[0]=i;
            p[n+1]=j;
            ans=min(ans,check());
        }
    printf("%d\n",ans);
    return 0;
}