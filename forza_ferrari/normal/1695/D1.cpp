#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,d[200001],dp[200001];
vector<int> v[200001];
inline void dfs(int k,int f)
{
    int tmp=0;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs(i,k);
        dp[k]+=dp[i];
        tmp+=!dp[i];
    }
    dp[k]+=max(tmp-1,0);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            d[i]=dp[i]=0;
            v[i].clear();
        }
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            ++d[x];
            ++d[y];
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        bool flag=0;
        for(int i=1;i<=n;++i)
            if(d[i]>=3)
            {
                dfs(i,0);
                cout<<dp[i]<<'\n';
                flag=1;
                break;
            }
        if(!flag)
            cout<<"1\n";
    }
    return 0;
}