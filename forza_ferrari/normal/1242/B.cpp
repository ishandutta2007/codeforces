#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[1000001<<1];
int tot,n,m,h[1000001],bin[1000001],s[1000001],ans;
vector<int> v;
map<int,int> decrease;
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x!=y)
    {
        bin[y]=x;
        s[x]+=s[y];
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        if(x<y)
            x^=y^=x^=y;
        add(x,y);
    }
    for(register int i=1;i<=n;++i)
        s[i]=1;
    v.push_back(1);
    for(register int k=2;k<=n;++k)
    {
        decrease.clear();
        for(register int i=h[k];i;i=e[i].nxt)
            ++decrease[anc(e[i].to)];
        for(register int i=0;i<(int)(v.size());++i)
            if(decrease[anc(v[i])]<s[anc(v[i])])
                link(v[i],k);
        if(anc(k)==k)
            v.push_back(k);
    }
    for(register int i=1;i<=n;++i)
        ans+=(anc(i)==i);
    printf("%lld\n",ans-1);
    return 0;
}