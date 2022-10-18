#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int mod=1000000007;
struct element
{
    int opt,x,y;
}g[100001];
int n,m,p,a[100001],val[100001],id[100001],ans;
vector<pair<int,int> > add[100001];
vector<int> res;
vector<pair<double,int> > mul;
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
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
inline bool cmp(int a,int b)
{
    return g[a].opt<g[b].opt;
}
signed main()
{
    n=read(),m=read(),p=read();
    ans=1;
    for(int i=1;i<=n;++i)
        a[i]=read();
    for(int i=1;i<=m;++i)
    {
        int opt=read(),x=read(),y=read();
        g[i]={opt,x,y};
        if(opt==1)
            if(y>val[x])
            {
                val[x]=y;
                id[x]=i;
            }
        if(opt==2)
            add[x].push_back({y,i});
        if(opt==3)
            mul.push_back({y,i});
    }
    for(int i=1;i<=n;++i)
        if(val[i]>a[i])
            add[i].push_back({val[i]-a[i],id[i]});
    for(int i=1;i<=n;++i)
    {
        sort(add[i].begin(),add[i].end());
        reverse(add[i].begin(),add[i].end());
        int pre=a[i];
        for(auto j:add[i])
        {
            mul.push_back({(j.first+pre)*1.0/pre,j.second});
            pre+=j.first;
        }
    }
    sort(mul.begin(),mul.end());
    reverse(mul.begin(),mul.end());
    //for(auto i:mul)
        //cout<<i.first<<" "<<i.second<<endl;
    for(int i=0;i<min((int)mul.size(),p);++i)
        res.push_back(mul[i].second);
    sort(res.begin(),res.end(),cmp);
    cout<<res.size()<<endl;
    for(int i:res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
    for(int i:res)
    {
        if(g[i].opt==1)
            a[g[i].x]=g[i].y;
        if(g[i].opt==2)
            a[g[i].x]=(a[g[i].x]+g[i].y)%mod;
        if(g[i].opt==3)
            a[g[i].x]=a[g[i].x]*g[i].y%mod;
    }
    for(int i=1;i<=n;++i)
        ans=ans*a[i]%mod;
    printf("%lld\n",ans);
    return 0;
}