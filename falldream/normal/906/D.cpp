#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,a[MN+5],Q,p[MN+5],num=0,R[MN+5],q[MN+5],top=0;
int GetPhi(int x)
{
    int res=x;
    for(int i=2;i<=100000;++i)if(x%i==0)
    {
        res=res/i*(i-1);
        while(x%i==0) x/=i;
    }
    if(x>1) res=res/x*(x-1);
    return res;
}
int pow(int x,int k,int mod)
{
    int res=1%mod;
    for(;k;k>>=1,x=1LL*x*x%mod)
        if(k&1) res=1LL*res*x%mod;
    return res;
}
long long Mnpow(long long x,int k)
{
    if(x==1) return 1;
    long long res=1;
    for(int j=1;j<=k&&res<1e9;++j) res=min((long long)1e9,res*x);
    return res;
}
int Solve(int l,int r,int m)
{
    if(p[m]==1) return 0;
    if(l==r) return a[l]%p[m];
    q[top=1]=a[l+1];
    for(int x=l+2;top<15&&x<=r&&q[top]!=1;++x)q[++top]=a[x];
    long long x=q[top];
    for(--top;top&&x<p[m+1];--top) x=Mnpow(q[top],x);
    if(x<p[m+1]) return pow(a[l],x,p[m]);
    else return pow(a[l],Solve(l+1,r,m+1)+p[m+1],p[m]);
}
int main()
{
    n=read();p[num=1]=read();
    for(;p[num]!=1;) ++num,p[num]=GetPhi(p[num-1]);
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=n,lst=n+1;i;--i) R[i]=lst,lst=(a[i]==1)?lst:i;
    Q=read();
    for(int i=1;i<=Q;++i)
    {
        int l=read(),r=read();
        printf("%d\n",Solve(l,r,1));
    }
    return 0;
}