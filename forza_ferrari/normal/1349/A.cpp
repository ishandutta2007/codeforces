#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int n,a[100001],p[200001],cnt,minn[200001],ans;
bool prime[200001];
vector<int> v[200001];
inline void sieve()
{
    prime[1]=1;
    for(int i=2;i<=200000;++i)
    {
        if(!prime[i])
        {
            p[++cnt]=i;
            minn[i]=i;
        }
        for(int j=1;i*p[j]<=200000;++j)
        {
            prime[i*p[j]]=1;
            minn[i*p[j]]=min(minn[i],p[j]);
            if(i%p[j]==0)
                break;
        }
    }
}
signed main()
{
    sieve();
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        int p=a[i];
        while(p^1)
        {
            int w=minn[p],tot=0;
            while(p%w==0)
            {
                p/=w;
                ++tot;
            }
            v[w].emplace_back(tot);
        }
    }
    ans=1;
    for(int i=2;i<=200000;++i)
    {
        sort(v[i].begin(),v[i].end());
        if(v[i].size()<n-1)
            continue;
        if(v[i].size()==n-1)
            for(int j=1;j<=(int)v[i][0];++j)
                ans*=i;
        else
            for(int j=1;j<=(int)v[i][1];++j)
                ans*=i;
    }
    cout<<ans<<'\n';
    return 0;
}