#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int t,n,sum;
vector<int> v[101],node[101];
bool tag[101][101][101],vis[101];
inline void dfs(int k,int f,int deep)
{
    node[deep].emplace_back(k);
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs(i,k,deep+1);
    }
}
inline bool solve(int x)
{
    queue<pair<int,int> > q;
    int cnt=1;
    vis[1]=vis[x]=1;
    v[1].emplace_back(x);
    v[x].emplace_back(1);
    q.emplace(x,1);
    for(int i=2;i<=n;++i)
        if(i!=x&&tag[1][i][x])
        {
            v[1].emplace_back(i);
            v[i].emplace_back(1);
            q.emplace(i,1);
            vis[i]=1;
        }
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        ++cnt;
        for(int i=2;i<=n;++i)
            if(i!=k.second&&tag[k.first][k.second][i])
            {
                if(vis[i])
                    return 0;
                q.emplace(i,k.first);
                v[k.first].emplace_back(i);
                v[i].emplace_back(k.first);
                vis[i]=1;
            }
    }
    return cnt==n;
}
inline bool check()
{
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            node[j].clear();
        dfs(i,0,1);
        for(int j=2;j<=n;++j)
            for(int l=0;l<(int)node[j].size();++l)
                for(int r=l+1;r<(int)node[j].size();++r)
                    if(!tag[i][node[j][l]][node[j][r]])
                        return 0;
                    else
                        ++cnt;
    }
    return sum==cnt;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                for(int k=1;k<=n;++k)
                    tag[i][j][k]=0;
        for(int i=1;i<n;++i)
            for(int j=1;j<=n-i;++j)
            {
                string s;
                cin>>s;
                s=" "+s;
                for(int k=1;k<=n;++k)
                {
                    tag[k][i][i+j]=tag[k][i+j][i]=s[k]-'0';
                    if(s[k]-'0')
                        ++sum;
                }
            }
        bool flag=0;
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                vis[j]=0;
                v[j].clear();
            }
            if(solve(i)&&check())
            {
                cout<<"Yes\n";
                for(int j=1;j<=n;++j)
                    for(int k:v[j])
                        if(j<k)
                            cout<<j<<" "<<k<<'\n';
                flag=1;
                break;
            }
        }
        if(!flag)
            cout<<"No\n";
    }
    return 0;
}