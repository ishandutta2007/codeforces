#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,m,a[501],tot,ans;
priority_queue<pair<int,int> > q;
vector<pair<int,int> > v;
int main()
{
    cin>>n>>m;
    if((n&1)&&(m&1^1))
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        a[i]=1;
        ++tot;
    }
    while(tot%m)
        for(int i=1;i<=n;++i)
        {
            if(tot%m==0&&a[1]<=tot/m)
                break;
            a[i]+=2;
            tot+=2;
        }
    for(int i=1;i<=n;++i)
        q.emplace(a[i],i);
    while(!q.empty())
    {
        cout<<"? ";
        v.clear();
        for(int i=1;i<=m;++i)
        {
            pair<int,int> k=q.top();
            q.pop();
            cout<<k.second<<" ";
            if(--k.first)
                v.emplace_back(k);
        }
        cout<<endl;
        int x;
        cin>>x;
        ans^=x;
        for(auto i:v)
            q.emplace(i);
    }
    cout<<"! "<<ans<<endl;
    return 0;
}