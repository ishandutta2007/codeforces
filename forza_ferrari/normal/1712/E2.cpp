#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int lim=2e5;
int n,ans[200001],sum[200001],cnt,p[200001],minn[200001];
bool prime[200001];
vector<pair<int,int> > v[200001],tmp;
vector<int> w;
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=lim;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
inline void sieve()
{
    prime[1]=1;
    for(int i=2;i<=lim;++i)
    {
        if(!prime[i])
        {
            p[++cnt]=i;
            minn[i]=i;
        }
        for(int j=1;j<=cnt&&i*p[j]<=lim;++j)
        {
            prime[i*p[j]]=1;
            minn[i*p[j]]=min(minn[i],p[j]);
            if(i%p[j]==0)
                break;
        }
    }
}
inline void dfs(int k,int val)
{
    if(k>=(int)tmp.size())
    {
        w.emplace_back(val);
        return;
    }
    for(int i=0;i<=tmp[k].second;++i)
    {
        dfs(k+1,val);
        val*=tmp[k].first;
    }
}
signed main()
{
    sieve();
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int l,r;
        cin>>l>>r;
        ans[i]=1ll*(r-l+1)*(r-l)*(r-l-1)/6;
        v[r].emplace_back(l,i);
    }
    for(int i=3;i<=lim;++i)
    {
        tmp.clear();
        int p=i;
        while(p^1)
        {
            int val=minn[p],tot=0;
            while(p%val==0)
            {
                p/=val;
                ++tot;
            }
            tmp.emplace_back(val,tot);
        }
        w.clear();
        dfs(0,1);
        sort(w.begin(),w.end());
        for(int j=0;j<(int)w.size();++j)
            update(w[j],max(0ll,(int)w.size()-j-2));
        if(i%6==0)
            update(i>>1,1);
        if(i%15==0)
            update(i/5*2,1);
        for(auto j:v[i])
            ans[j.second]-=query(i)-query(j.first-1);
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<'\n';
    return 0;
}