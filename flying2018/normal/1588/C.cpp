#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#define N 300010
#define ll long long
using namespace std;
int a[N];ll s[N];
namespace t1{
    ll t[N<<2];// t_i - x <=0
    void build(int u,int l,int r)
    {
        t[u]=-1e18;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(u<<1,l,mid);build(u<<1|1,mid+1,r);
    }
    void insert(int u,int l,int r,int p,ll v)
    {
        if(l==r){t[u]=v;return;}
        int mid=(l+r)>>1;
        if(p<=mid) insert(u<<1,l,mid,p,v);
        else insert(u<<1|1,mid+1,r,p,v);
        t[u]=max(t[u<<1],t[u<<1|1]);
    }
    int qry(int u,int l,int r,ll v)
    {
        if(l==r) return l;
        int mid=(l+r)>>1;
        if(t[u<<1]>v) return qry(u<<1,l,mid,v);
        else return qry(u<<1|1,mid+1,r,v);
    }
}
namespace t2{
    ll t[N<<2];// t_i - x >=0
    void build(int u,int l,int r)
    {
        t[u]=1e18;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(u<<1,l,mid);build(u<<1|1,mid+1,r);
    }
    void insert(int u,int l,int r,int p,ll v)
    {
        if(l==r){t[u]=v;return;}
        int mid=(l+r)>>1;
        if(p<=mid) insert(u<<1,l,mid,p,v);
        else insert(u<<1|1,mid+1,r,p,v);
        t[u]=min(t[u<<1],t[u<<1|1]);
    }
    int qry(int u,int l,int r,ll v)
    {
        if(l==r) return l;
        int mid=(l+r)>>1;
        if(t[u<<1]<v) return qry(u<<1,l,mid,v);
        else return qry(u<<1|1,mid+1,r,v);
    }
}
map<ll,vector<int>>st;
int rf[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        st.clear();
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=2;i<=n;i+=2) a[i]=-a[i];
        for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        t1::build(1,1,n);t2::build(1,1,n);
        // for(int i=0;i<=n;i++) printf("%lld ",s[i]);puts("");
        for(int i=n;i>=0;i--)
        {
            // printf("%d: %d %d\n",i,t1::qry(1,1,n,s[i]),t2::qry(1,1,n,s[i]));
            if(i&1) rf[i]=min(t1::qry(1,1,n,s[i]),t2::qry(1,1,n,s[i])),t2::insert(1,1,n,i,s[i]);
            else rf[i]=min(t1::qry(1,1,n,s[i]),t2::qry(1,1,n,s[i])),t1::insert(1,1,n,i,s[i]);
        }
        // for(int i=0;i<=n;i++) printf("%d ",rf[i]);puts("");
        ll ans=0;
        for(int i=n;i>=0;i--)
        {
            auto &w=st[s[i]];
            int p=w.end()-lower_bound(w.begin(),w.end(),rf[i],greater<ll>());
            ans+=p;
            // for(int v:w) if(v<=rf[i]) printf("%d %d\n",i+1,v);
            w.push_back(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}