#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>

#define N 100005

#define mk make_pair
#define fi first
#define se second

using namespace std;
int Max=314000000;
struct Node{
	vector<int>v;int before;
}s[N];
set<pair<int,int> >st;
vector<int>v,b[N],B[N];
int i,j,m,n,p,k,k1,fox[N],Min[N],x,deg[N],vis[N],dis[N],cnt,V[N],f[N];
int S[N],Ansx[N],Ansy[N];
void add(int x)
{
	 s[++k1].v=v; s[k1].before=fox[x]; fox[x]=k1;
}
void work()
{
	memset(dis,60,sizeof(dis));
	for (i=1;i<=n;++i) if (vis[i]) 
	st.insert(mk(Min[i],i)),dis[i]=Min[i];
	memset(vis,0,sizeof(vis));
	for (;;)
	{
		 pair<int,int>x;
		while (st.size())
		{
			 if (vis[st.begin()->se]) st.erase(st.begin());
			 else break;
		}
		if (!st.size()) break;
		x=*st.begin(); st.erase(st.begin());
		vis[x.se]=1; int id=x.se;
		for (i=0;i<(int)b[id].size();++i)
		{
			 int p=b[id][i];
			 deg[p]--;
             if (!deg[p])
             {
             	  int sum=0;
             	  for (j=0;j<(int)B[p].size();++j)
             	     if (B[p][j]==-1)
             	      sum=min(Max,sum+1);
             	      else sum=min(Max,sum+dis[B[p][j]]);
             	  dis[S[p]]=min(dis[S[p]],sum);
             	  st.insert(mk(dis[S[p]],S[p]));
             }
        }
	}
}
int dfs(int x)
{
	 if (vis[x]) return f[x];
	 if (V[x]==1) return -2;
	 V[x]=1;
	 int i,j;
	 for (i=fox[x];i;i=s[i].before)
	 {
	 	  int sum=0,flag=0;
	 	  for (j=0;j<(int)s[i].v.size();++j) if (dis[s[i].v[j]]>Max) break;
	 	  if (j!=(int)s[i].v.size()) continue;
	 	  for (j=0;j<(int)s[i].v.size();++j)
	 	    if (s[i].v[j]==-1) sum=min(Max,sum+1);
	 	    else 
	 	    {
	 	    	  int r=dfs(s[i].v[j]);
	 	    	  if (r==-2) { V[x]=0; vis[x]=1; return f[x]=-2; }
	 	    	  sum=min(Max,sum+r);
	 	    }
	 	  if (!flag)
	 	  f[x]=max(f[x],sum);
	}
	vis[x]=1;
	V[x]=0;
	return f[x];
}
int main()
{
	  scanf("%d%d",&m,&n);
	  memset(Min,60,sizeof(Min));
	  memset(f,-1,sizeof(f));
	  for (i=1;i<=m;++i)
	  {
	  	scanf("%d",&x); S[i]=x;
	  	scanf("%d",&k);
	  	v.clear();
	  	int flag=0;
	  	for (;k--;)
	  	{
	  	   scanf("%d",&p);
	  	   v.push_back(p);
	  	   if (p!=-1)
	  	   {
	  	   	 flag=1;
	  	   	 deg[i]++;
	  	   	 b[p].push_back(i);
	  	   }
	    }
	    add(x);
	    if (!flag) vis[x]=1,Min[x]=min(Min[x],(int)v.size());
	    B[i]=v;
	 }
	 work(); memset(vis,0,sizeof(vis));
	 for (i=1;i<=n;++i) if (dis[i]<=Max)
	 {   
	      ++cnt;
	 	  printf("%d %d\n",dis[i],dfs(i));
	 }
	 else printf("-1 -1\n");
}