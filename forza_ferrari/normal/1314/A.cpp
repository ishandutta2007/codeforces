#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
struct element
{
    int num,val;
    bool operator <(const element &other) const
    {
        return num<other.num;
    }
}a[200005];
int n,ans,sum;
priority_queue<int> q;
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&a[i].num);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&a[i].val);
    sort(a+1,a+n+1);
    a[n+1].num=1ll<<31-1;
    for(register int i=1;i<=n;++i)
    {
        q.push(a[i].val);
        sum+=a[i].val;
        int cnt=a[i].num;
        while(!q.empty()&&cnt<a[i+1].num)
        {
            sum-=q.top();
            q.pop();
            ans+=sum;
            ++cnt;
        }
    }
    printf("%lld\n",ans);
    return 0;
}