//lol can't opt any more
//should probably do better things than hash maps

#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
using namespace std;
#define mp make_pair
#define lol long long
const int inf=1e9+7;
vector <int> h[501],g[501],w[501];
bool mark[501],can[501];
int dis[501],n,m,v,u,W;

void dij(int x)
{
  set<pair<int,int> > s;
  dis[x]=0;
  s.insert(mp(dis[x],x));
  while(s.size())
    {
      v=s.begin()->second;
      s.erase(s.begin());
      for(int i=0;i<g[v].size();i++)
	{
	  u=g[v][i];
	  W=w[v][i];
	  if(dis[v]+W==dis[u])
	    {
	      h[u].push_back(v);
	      //  cerr<<u<<"->"<<v<<endl;
	    }
	  else if(dis[v]+W<dis[u])
	    {
	      h[u].clear();
	      h[u].push_back(v);
	      s.erase(mp(dis[u],u));
	      dis[u]=dis[v]+W;
	      s.insert(mp(dis[u],u));
	      //	      cerr<<u<<"->"<<v<<endl;
	    }
	}
    }
}

int dfs(int x)
{
  mark[x]=true;
  int ret=0;
  for(int i=0;i<h[x].size();i++)
    if(!mark[h[x][i]])
      ret+=dfs(h[x][i]);
  return ret+h[x].size();
}

void fit()
{
  for(int i=1;i<=n;i++)
    mark[i]=false;
}

int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++)
    {
      //cin>>v>>u>>t;
      scanf("%d%d%d",&v,&u,&W);
      g[v].push_back(u);
      g[u].push_back(v);
      w[v].push_back(W);
      w[u].push_back(W);
    }
  for(int i=1;i<=n;i++)
    {
      //cerr<<i<<":"<<endl;
      for(int j=1;j<=n;j++)
	h[j].clear(),dis[j]=inf;
      dij(i);
      for(int j=i+1;j<=n;j++)
	{
	  fit();
	  //cout<<dfs(j)<<" ";
	  printf("%d ",dfs(j));
	}
    }
  return 0;
}