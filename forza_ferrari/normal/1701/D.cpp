#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int t,n,ans[500001];
vector<pair<int,int> > v[500001];
set<pair<int,int> > s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        s.clear();
        for(int i=1;i<=n;++i)
            v[i].clear();
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            int l=i/(x+1)+1,r=x? i/x:n;
            v[l].emplace_back(r,i);
        }
        for(int i=1;i<=n;++i)
        {
            for(auto j:v[i])
                s.emplace(j);
            ans[s.begin()->second]=i;
            s.erase(s.begin());
        }
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}