#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[600001],lst[300001],sum[600001],ans[300001][2];
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int val)
{
    for(;x<=n+m;x+=lowbit(x))
        sum[x]+=val;
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        a[i]=n-i+1;
        ans[i][0]=ans[i][1]=i;
    }
    for(int i=n+1;i<=n+m;++i)
    {
        cin>>a[i];
        ans[a[i]][0]=1;
    }
    for(int i=1;i<=n+m;++i)
    {
        if(lst[a[i]])
        {
            ans[a[i]][1]=max(ans[a[i]][1],query(i-1)-query(lst[a[i]])+1);
            update(lst[a[i]],-1);
        }
        update(lst[a[i]]=i,1);
    }
    for(int i=1;i<=n;++i)
        ans[i][1]=max(ans[i][1],query(n+m)-query(lst[i])+1);
    for(int i=1;i<=n;++i)
        cout<<ans[i][0]<<" "<<ans[i][1]<<'\n';
    return 0;
}