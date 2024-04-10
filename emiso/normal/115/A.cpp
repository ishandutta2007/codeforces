#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> adj[2010]; 
bool visit[2010];
int dist[2010],maior=-1;

void dfs(int node)
{
     if(dist[node]>maior) maior=dist[node];
     if (visit[node]==true) return;
     visit[node]=true;
     for(int i=0;i<adj[node].size();i++)
     {
              dist[adj[node][i]] = dist[node]+1;
              dfs(adj[node][i]);
     }
}

int main()
{
    memset(dist,0,sizeof(dist));
    memset(visit,false,sizeof(visit));
    int n,e;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
              scanf("%d",&e);
              if(e == -1) adj[0].push_back(i);
              else adj[e].push_back(i);
    }
    visit[0]=false;
    dist[0]=0;
    dfs(0);
    printf("%d\n",maior);
    return 0;
}