#include<bits/stdc++.h>
#define MN 75
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
int f[MN+5][1<<19],n,a[MN+5][MN+5],lst[MN+5],ans;
inline void R(int&x,int y){(x+=y)>=mod?x-=mod:0;}
int main()
{
    n=read();scanf("%s",s+1);
    for(int i=1;i<=n;++i) lst[i]=s[i]>'0'?i:lst[i-1];
    for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) 
        a[i][j]=min(100,a[i][j-1]*2+s[j]-'0');
    for(int i=1;i<=n;++i)
    {
        R(f[i-1][0],1);int j;
        for(j=lst[i];j>=i-5&&j;j=lst[j-1])
            for(int k=0;k<1<<19;++k)
                if(a[j][i]<=19) R(f[i][k|(1<<a[j][i]-1)],(f[j-1][k]-(lst[j-1]>0?f[lst[j-1]-1][k]:0)+mod)%mod);
        for(int k=0;k<1<<19;++k)R(f[i][k],f[i-1][k]);
    }
    for(int j=1;j<=19;++j) R(ans,f[n][(1<<j)-1]);
    cout<<ans;
    return 0;
}