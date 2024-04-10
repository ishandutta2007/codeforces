#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>
#define mod 1000000007
#define MN 300
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,f[MN+5],a[MN+5],g[MN+5],s[MN+5],p[MN+5],C[MN+5][MN+5],num=0;map<int,int> mp;
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
    n=read();p[0]=1;
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        for(int j=2;j*j<=a[i];++j)
            while(a[i]%(j*j)==0) a[i]/=j*j;
        ++mp[a[i]];
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it) s[++num]=it->second;
    f[s[1]-1]=1;int t=s[1];
    /*
        f[j][i]ji
        
        iccc j k
        C[i][k],j-kcc+1-iC[cc+1-i][j-k]
        c-jjnmC(n+m-1,m-1)C[c-1][j-1]
        
    */
    for(int i=0;i<=MN;++i) C[i][0]=1;
    for(int i=1;i<=MN;p[i]=1LL*p[i-1]*i%mod,++i)
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    for(int l=2;l<=num;++l)
    {
        int c=s[l];memset(g,0,sizeof(int)*(t+c+2));
        for(int i=0;i<t;++i)
            for(int j=1;j<=c;++j)
                for(int k=0;k<=j&&k<=i;++k)
                    R(g[i-k+c-j],1LL*f[i]*C[i][k]%mod*C[t+1-i][j-k]%mod*C[c-1][j-1]%mod);
        t+=c;for(int i=0;i<t;++i) f[i]=g[i];
    }
    int ans=f[0];
    for(int i=1;i<=num;++i)ans=1LL*ans*p[s[i]]%mod;
    printf("%d\n",ans);
    return 0;
}