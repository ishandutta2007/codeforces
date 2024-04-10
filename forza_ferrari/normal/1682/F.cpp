#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int mod=1000000007;
int n,m,a[200001],b[200001],sum[2][200005],cnt,node[200005],ans[200001];
struct element
{
    int val,tag,id;
    element(int val_,int tag_,int id_):
        val(val_),tag(tag_),id(id_){}
};
vector<element> v[200001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val,int tag)
{
    for(;x<=cnt;x+=lowbit(x))
        sum[tag][x]=(sum[tag][x]+val)%mod;
}
inline int query(int x,int tag)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res=(res+sum[tag][x])%mod;
    return res;
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    node[cnt=1]=0;
    for(int i=1;i<=n;++i)
        node[++cnt]=b[i]=(read()+b[i-1]);
    sort(node+1,node+cnt+1);
    cnt=unique(node+1,node+cnt+1)-node-1;
    for(int i=0;i<=n;++i)
        b[i]=lower_bound(node+1,node+cnt+1,b[i])-node;
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        v[l-1].emplace_back(b[l-1],-1,i);
        v[r-1].emplace_back(b[l-1],1,i);
    }
    for(int i=1;i<n;++i)
    {
        update(b[i],a[i+1]-a[i],0);
        update(b[i],(node[b[i]]*(a[i+1]-a[i])%mod+mod)%mod,1);
        for(auto j:v[i])
        {
            int x=((node[j.val]+mod)%mod*query(j.val,0)%mod-query(j.val,1)+mod)%mod,y=((((query(cnt,1)-query(j.val,1)+mod)%mod-(node[j.val]+mod)%mod*(query(cnt,0)-query(j.val,0))%mod)+mod)%mod+mod)%mod;
            if(j.tag==1)
                ans[j.id]=(ans[j.id]+(x+y)%mod)%mod;
            else
                ans[j.id]=(ans[j.id]+(mod-(x+y)%mod)%mod)%mod;
        }
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]%mod<<'\n';
    return 0;
}