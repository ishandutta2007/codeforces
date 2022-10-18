#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int n,ans;
bool vis[100001];
pair<int,int> city[100001];
priority_queue<pair<int,int> > q;
signed main()
{
    scanf("%lld",&n);
    for(register int i=0;i<n;++i)
    {
        scanf("%lld%lld",&city[i].first,&city[i].second);
        ans+=city[i].second;
    }
    sort(city,city+n);
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        pair<int,int> k=q.top();
        q.pop();
        if(vis[k.second])
            continue;
        vis[k.second]=1;
        //printf("%lld %lld\n",k.first,k.second);
        if(k.second==n-1)
        {
            ans-=k.first;
            break;
        }
        if(k.second>0)
            q.push(make_pair(k.first,k.second-1));
        int p=lower_bound(city,city+n,make_pair(city[k.second].first+city[k.second].second,LLONG_MAX))-city-1;
        q.push(make_pair(k.first,p));
        if(p+1<n)
            q.push(make_pair(k.first-city[p+1].first+city[k.second].first+city[k.second].second,p+1));
    }
    printf("%lld\n",ans);
    return 0;
}