#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
int n,m,a[500001],b[500001],ans,sum,cnt;
inline bool check(int x)
{
    sum=cnt=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(register int i=1;i<=n;++i)
    {
        q.push(make_pair(a[i],0));
        if(q.top().first+b[i]+x<=0)
        {
            sum+=q.top().first+b[i]+x;
            cnt+=q.top().second^1;
            q.pop();
            q.push(make_pair(-b[i]-x,1));
        }
    }
    if(cnt>=m)
        ans=sum;
    return cnt>=m;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&b[i]);
    int l=-1e18,r=1e18,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            ans=sum-m*mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%lld\n",ans);
    return 0;
}