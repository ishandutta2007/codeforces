#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[500001],ans;
priority_queue<int> q;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=m+1;++i)
        q.emplace(0);
    for(int i=1;i<=n;++i)
    {
        int k=q.top();
        q.pop();
        ans+=k;
        k+=a[i];
        q.emplace(k);
    }
    cout<<ans<<'\n';
    return 0;
}