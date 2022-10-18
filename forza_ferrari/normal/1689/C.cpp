#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,s[300001],dp[300001];
vector<int> v[300001];
inline void dfs(int k,int f)
{
    s[k]=1;
    vector<int> tmp;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        tmp.emplace_back(i);
        dfs(i,k);
        s[k]+=s[i];
    }
    if(tmp.size()==0)
        return;
    if(tmp.size()==1)
    {
        dp[k]=s[tmp[0]]-1;
        return;
    }
    dp[k]=max(s[tmp[0]]-1+dp[tmp[1]],s[tmp[1]]-1+dp[tmp[0]]);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            s[i]=dp[i]=0;
            v[i].clear();
        }
        for(int i=1;i<n;++i)
        {
            int x,y;
            cin>>x>>y;
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }
        dfs(1,0);
        cout<<dp[1]<<'\n';
    }
    return 0;
}