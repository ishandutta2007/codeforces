#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
const int mod=1004535809;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
const int base=19260817,inv=pw(base,mod-2);
int n,m,a[300001],p[300001],invp[300001],dep[300001],fa[300001],s[300001],son[300001],top[300001],dfn[300001],cnt,w[300001][2];
vector<int> v[300001];
vector<pair<int,int> > va,vb;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int Mod(int x)
{
    return x>=mod? x-mod:x;
}
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k]=f;
    s[k]=1;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs1(i,k,deep+1);
        s[k]+=s[i];
        if(s[i]>s[son[k]])
            son[k]=i;
    }
}
inline void dfs2(int k,int t)
{
    top[k]=t;
    dfn[k]=++cnt;
    w[cnt][0]=Mod(w[cnt-1][0]+1ll*a[k]*p[cnt]%mod);
    w[cnt][1]=Mod(w[cnt-1][1]+1ll*a[k]*p[n-cnt+1]%mod);
    if(!son[k])
        return;
    dfs2(son[k],t);
    for(int i:v[k])
    {
        if(i==fa[k]||i==son[k])
            continue;
        dfs2(i,i);
    }
}
inline int LCA(int x,int y)
{
    while(top[x]^top[y])
    {
        if(dep[top[x]]<dep[top[y]])
            x^=y^=x^=y;
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])
        x^=y^=x^=y;
    return x;
}
inline int calc(int x,int y)
{
    return x<=y? 1ll*Mod(w[y][0]-w[x-1][0]+mod)*invp[x]%mod:1ll*Mod(w[x][1]-w[y-1][1]+mod)*invp[n-x+1]%mod;
}
inline vector<pair<int,int> > query(int x,int y)
{
    vector<pair<int,int> > res,tmp;
    int lca=LCA(x,y);
    while(top[x]^top[lca])
    {
        res.emplace_back(dfn[x],dfn[top[x]]);
        x=fa[top[x]];
    }
    while(top[y]^top[lca])
    {
        tmp.emplace_back(dfn[top[y]],dfn[y]);
        y=fa[top[y]];
    }
    res.emplace_back(dfn[x],dfn[y]);
    while(!tmp.empty())
    {
        res.emplace_back(tmp.back());
        tmp.pop_back();
    }
    return res;
}
int main()
{
    n=read();
    p[0]=invp[0]=1;
    for(int i=1;i<=n;++i)
    {
        p[i]=1ll*p[i-1]*base%mod;
        invp[i]=1ll*invp[i-1]*inv%mod;
        char c=getchar();
        while(c<'a'||c>'z')
            c=getchar();
        a[i]=c-'a'+1;
    }
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    dfs1(1,0,1);
    dfs2(1,1);
    m=read();
    while(m--)
    {
        int x=read(),y=read();
        va=query(x,y);
        x=read(),y=read();
        vb=query(x,y);
        int pa=0,pb=0,ans=0;
        while(pa<(int)va.size()&&pb<(int)vb.size())
        {
            int len=min(abs(va[pa].first-va[pa].second)+1,abs(vb[pb].first-vb[pb].second)+1);
            if(calc(va[pa].first,va[pa].first+(va[pa].first<=va[pa].second? 1:-1)*(len-1))==calc(vb[pb].first,vb[pb].first+(vb[pb].first<=vb[pb].second? 1:-1)*(len-1)))
            {
                ans+=len;
                if(len==abs(va[pa].first-va[pa].second)+1)
                    ++pa;
                else
                    va[pa].first+=(va[pa].first<=va[pa].second? 1:-1)*len;
                if(len==abs(vb[pb].first-vb[pb].second)+1)
                    ++pb;
                else
                    vb[pb].first+=(vb[pb].first<=vb[pb].second? 1:-1)*len;
            }
            else
            {
                int l=1,r=len,mid,res=0;
                while(l<=r)
                {
                    mid=(l+r)>>1;
                    if(calc(va[pa].first,va[pa].first+(va[pa].first<=va[pa].second? 1:-1)*(mid-1))==calc(vb[pb].first,vb[pb].first+(vb[pb].first<=vb[pb].second? 1:-1)*(mid-1)))
                    {
                        res=mid;
                        l=mid+1;
                    }
                    else
                        r=mid-1;
                }
                ans+=res;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}