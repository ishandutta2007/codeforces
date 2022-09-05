//priority_queue
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
int n,m,mk[111111],pre[111111];
long long dis[111111];
vector<pair<int,int> >con[111111];
priority_queue<pair<long long,int> >all;
int print(int x)
{
    if(x!=0)print(pre[x]);
    printf("%d ",x+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        con[a].push_back(make_pair(b,c));
        con[b].push_back(make_pair(a,c));
    }
    mk[0]=1;
    all.push(make_pair(0,0));
    while(!all.empty())
    {
        
        int v=all.top().second,d=-(all.top().first);
        all.pop();
        mk[v]=2;
        for(int j=0;j<con[v].size();j++)
        {
            int u=con[v][j].first,cost=con[v][j].second;
            if(mk[u]==0||mk[u]==1&&dis[u]>d+cost)
            {
                mk[u]=1;
                pre[u]=v;
                dis[u]=d+cost;
                all.push(make_pair(-(dis[u]),u));
            }
        }
        if(mk[n-1]==2){print(n-1);return 0;}
    }
    printf("-1");
//  system("pause");
    return 0;
}