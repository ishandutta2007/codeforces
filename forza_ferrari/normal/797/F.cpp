#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
int n,m,x[5001],ans,tot;
pair<int,int> y[5001];
priority_queue<pair<int,int> > q1;
priority_queue<int> q2;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    sort(x+1,x+n+1);
    for(int i=1;i<=m;++i)
    {
        cin>>y[i].first>>y[i].second;
        tot+=y[i].second;
    }
    if(tot<n)
    {
        cout<<"-1\n";
        return 0;
    }
    sort(y+1,y+m+1);
    for(int i=1,j=1;i<=n||j<=m;)
        if(j>m||(i<=n&&x[i]<y[j].first))
        {
            int val=1e12;
            if(!q1.empty())
            {
                val=x[i]-q1.top().first;
                pair<int,int> k=q1.top();
                q1.pop();
                if(--k.second)
                    q1.emplace(k);
            }
            ans+=val;
            q2.emplace(x[i]+val);
            ++i;
        }
        else
        {
            while(!q2.empty()&&y[j].second&&y[j].first-q2.top()<0)
            {
                ans+=y[j].first-q2.top();
                q1.emplace(2*y[j].first-q2.top(),1);
                q2.pop();
                
                --y[j].second;
            }
            if(y[j].second)
                q1.emplace(y[j]);
            ++j;
        }
    cout<<ans<<'\n';
    return 0;
}