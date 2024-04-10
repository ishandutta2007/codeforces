#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,sum[5001][5001],cnt;
char mp[5001][5001];
pair<int,int> ans;
vector<pair<int,int> > v[2];
inline bool cmp1(pair<int,int> x,pair<int,int> y)
{
    return x.first+x.second<y.first+y.second;
}
inline bool cmp2(pair<int,int> x,pair<int,int> y)
{
    return x.first-x.second<y.first-y.second;
}
inline int calc(pair<int,int> x,pair<int,int> y)
{
    return abs(x.first-y.first)+abs(x.second-y.second);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        v[0].clear();
        v[1].clear();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                cin>>mp[i][j];
                if(mp[i][j]=='B')
                {
                    v[0].emplace_back(i,j);
                    v[1].emplace_back(i,j);
                }
            }
        sort(v[0].begin(),v[0].end(),cmp1);
        sort(v[1].begin(),v[1].end(),cmp2);
        if(v[0].empty())
        {
            cout<<"1 1\n";
            continue;
        }
        ans={0,0};
        int minn=1e9;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
            {
                int val=max(max(calc({i,j},v[0].front()),calc({i,j},v[0].back())),max(calc({i,j},v[1].front()),calc({i,j},v[1].back())));
                if(val<minn)
                {
                    minn=val;
                    ans={i,j};
                }
            }
        cout<<ans.first<<" "<<ans.second<<'\n';
    }
    return 0;
}