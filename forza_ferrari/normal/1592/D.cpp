#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[1001<<1];
int n,tot,h[1001],dfn[1001],fa[1001],cnt,maxn,ans;
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f)
{
    dfn[++cnt]=k;
    fa[k]=f;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
    }
}
int main()
{
    cin>>n;
    for(register int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    cout<<"? "<<n;
    for(register int i=1;i<=n;++i)
        cout<<" "<<i;
    cout<<endl;
    cin>>maxn;
    ans=dfn[n];
    dfs(1,0);
    int l=2,r=n,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        cout<<"? "<<mid;
        for(register int i=1;i<=mid;++i)
            cout<<" "<<dfn[i];
        cout<<endl;
        int x;
        cin>>x;
        if(x==maxn)
        {
            r=mid-1;
            ans=dfn[mid];
        }
        else
            l=mid+1;
    }
    cout<<"! "<<fa[ans]<<" "<<ans<<endl;
    return 0;
}