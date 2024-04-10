#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define int long long
const double eps=1e-12;
int n,p[200001],t[200001],id[200001],cnt,pos[200001],sum[200001],T;
vector<int> v[200001];
inline bool check(double x)
{
    double maxn=-1e18;
    for(int i=1,j;i<=n;i=j)
    {
        j=i;
        while(j<=n&&p[id[i]]==p[id[j]])
            ++j;
        for(int k=i;k<j;++k)
            if(maxn>p[id[k]]*(1-x*sum[pos[id[k]]]/T))
                return 0;
        for(int k=i;k<j;++k)
            maxn=max(maxn,p[id[k]]*(1-x*(sum[pos[id[k]]-1]+t[id[k]])/T));
    }
    return 1;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i];
        id[i]=i;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>t[i];
        T+=t[i];
    }
    sort(id+1,id+n+1,[&](int x,int y){return p[x]*t[y]!=p[y]*t[x]? p[x]*t[y]>p[y]*t[x]:x<y;});
    v[pos[id[1]]=cnt=1].emplace_back(id[1]);
    sum[1]=t[id[1]];
    for(int i=2;i<=n;++i)
    {
        if(p[id[i]]*t[id[i-1]]!=p[id[i-1]]*t[id[i]])
        {
            ++cnt;
            sum[cnt]=sum[cnt-1];
        }
        v[pos[id[i]]=cnt].emplace_back(id[i]);
        sum[cnt]+=t[id[i]];
    }
    sort(id+1,id+n+1,[&](int x,int y){return p[x]<p[y];});
    double l=0.000000,r=1.000000,mid,ans=0.000000;
    for(int i=1;i<=60;++i)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid;
        }
        else
            r=mid;
    }
    printf("%.10lf\n",ans);
    return 0;
}