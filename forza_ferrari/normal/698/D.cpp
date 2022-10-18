#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
struct element
{
    int x,y;
}a[11],q[1001];
map<pair<int,int>,vector<int> > mp[11];
int n,m,p[11],ans,cnt,vis[1001];
bool tag[1001];
pair<int,int> pos[11][1001];
vector<int> node;
inline int gcd(int x,int y)
{
    if(!x||!y)
        return x|y;
    return x%y? gcd(y,x%y):y;
}
inline bool dfs(int k)
{
    node.emplace_back(k);
    vis[k]=++cnt;
    if(cnt>m)
        return 0;
    int tmp=cnt;
    vector<int> res;
    for(int i:mp[p[tmp]][pos[p[tmp]][k]])
    {
        if(i==k)
            break;
        res.emplace_back(i);
        if(res.size()>m-cnt)
            return 0;
    }
    reverse(res.begin(),res.end());
    for(int i:res)
    {
        //if(vis[i]&&vis[i]<=vis[k])
            //return 0;
        if(!vis[i])
            if(!dfs(i))
                return 0;
    }
    return 1;
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;++i)
    {
        p[i]=i;
        cin>>a[i].x>>a[i].y;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>q[i].x>>q[i].y;
        for(int j=1;j<=m;++j)
        {
            int x=q[i].x-a[j].x,y=q[i].y-a[j].y,g=gcd(abs(x),abs(y));
            x/=g;
            y/=g;
            mp[j][pos[j][i]={x,y}].emplace_back(i);
        }
    }
    for(int i=1;i<=m;++i)
        for(auto &j:mp[i])
            sort(j.second.begin(),j.second.end(),[&](int x,int y){return 1ll*(q[x].x-a[i].x)*(q[x].x-a[i].x)+1ll*(q[x].y-a[i].y)*(q[x].y-a[i].y)<1ll*(q[y].x-a[i].x)*(q[y].x-a[i].x)+1ll*(q[y].y-a[i].y)*(q[y].y-a[i].y);});
    do
    {
        
        for(int i=1;i<=n;++i)
            if(!tag[i])
            {
                tag[i]|=dfs(i);
                cnt=0;
                for(int i:node)
                    vis[i]=0;
                node.clear();
            }
    }while(next_permutation(p+1,p+m+1));
    for(int i=1;i<=n;++i)
        ans+=tag[i];
    cout<<ans<<'\n';
    return 0;
}