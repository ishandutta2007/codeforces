#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,m;
pair<int,int> edge[200005];
vector<pair<pair<int,int>,int> > G[200005];
int limit[200005]={};
bool used[200005]={};
bool ok[200005]={};
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge[i]=make_pair(a,b);
        G[a].push_back(make_pair(make_pair(b,c),i));
        G[b].push_back(make_pair(make_pair(a,c),i));
        limit[a]+=c;
        limit[b]+=c;
    }
    for(int i=2;i<n;i++)
    {
        limit[i]/=2;
    }
    int cur=1;
    queue<int>que;
    que.push(cur);
    while(!que.empty())
    {
        cur=que.front();
        que.pop();
        for(int i=0;i<G[cur].size();i++)
        {
            int q=G[cur][i].second;
            if(!used[q])
            {
                limit[G[cur][i].first.first]-=G[cur][i].first.second;
                if(!limit[G[cur][i].first.first]) que.push(G[cur][i].first.first);
                if(edge[q].first!=cur) ok[q]=true;
                used[q]=true;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        puts(ok[i]?"1":"0");
    }
}