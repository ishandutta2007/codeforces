#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500010
#define inf 1e17
#define ll long long
#define il inline
using namespace std;
il char gc()
{
    static char now[1<<20],*S,*T;
    if (T==S)
    {
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
il ll read()
{
    ll res=0,sign=1;
    char c;
    while ((c=gc())<'0'||c>'9') if (c=='-') sign=-1;
    res=(c^48);
    while ((c=gc())>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48);
    return res*sign;
}
ll f[N],g[N],h[N],w[N],s[N],p[N],pos[N];
int a[N],b[N];
int main()
{
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) p[i]=read();
    int m=read();
    for(int i=1;i<=m;i++) b[i]=read();
    ++n,++m;a[n]=b[m]=n;
    for(int i=1;i<=m;i++) pos[b[i]]=i;
    for(int i=1,r=0;i<=n;g[i++]=r) if(i>b[r]) ++r;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+min(0ll,p[i]);
    memset(f,60,sizeof(f));memset(h,60,sizeof(h));h[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(pos[a[i]] && h[pos[a[i]]-1]<inf) f[i]=h[pos[a[i]]-1]+w[pos[a[i]]]+s[i-1],h[pos[a[i]]]=min(h[pos[a[i]]],f[i]-s[i]);
        if(p[i]>0) w[g[a[i]]]+=p[i];
    }
    if(f[n]>inf) puts("NO");
    else printf("YES\n%lld\n",f[n]);
    return 0;
}