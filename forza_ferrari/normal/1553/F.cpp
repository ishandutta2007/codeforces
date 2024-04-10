#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,a[300001],sum[300001][2],s,ans,maxn;
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val,int tag)
{
    for(;x<=maxn;x+=lowbit(x))
        sum[x][tag]+=val;
}
inline int query(int x,int tag)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x][tag];
    return res;
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        ans+=s+(i-1)*a[i]-query(a[i],1);
        s+=a[i];
        for(int j=a[i];j<=maxn;j+=a[i])
        {
            int l=j,r=min(j+a[i]-1,maxn);
            ans-=(query(r,0)-query(l-1,0))*j;
            update(j,a[i],1);
        }
        update(a[i],1,0);
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}