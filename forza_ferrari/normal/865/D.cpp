#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
int n,p[300001],ans;
priority_queue<int> q;
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
        scanf("%lld",&p[i]);
    for(register int i=1;i<=n;++i)
    {
        if(!q.empty()&&q.top()+p[i]>=0)
        {
            ans+=q.top()+p[i];
            q.pop();
            q.push(-p[i]);
        }
        q.push(-p[i]);
    }
    printf("%lld\n",ans);
    return 0;
}