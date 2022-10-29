#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 7105
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,tot,S,T,L,k1=1,fox[N],Q[N],st,ed,dis[N],n1,n2,deg[N],ans[N];
struct Bian{int x,y;}B[N];
struct Node{int ed,before;int flow;}s[M];
void add(int x,int y,int flow)
{
	s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].flow=flow;
	s[++k1].ed=x; s[k1].before=fox[y]; fox[y]=k1; s[k1].flow=0;
}
int bfs()
{
   Q[Q[0]=1]=st; memset(dis,-1,sizeof(dis));
   dis[st]=0;
   int l=1,i;
   for (;l<=Q[0]&&dis[ed]==-1;++l)
  {
        int p=Q[l];
        for (i=fox[p];i;i=s[i].before)
          if (s[i].flow&&dis[s[i].ed]==-1)
            {
            	dis[s[i].ed]=dis[p]+1;
            	Q[++Q[0]]=s[i].ed;
			}
  }
  return dis[ed]!=-1;
}
int dfs(int x,int flow)
{
	if (x==ed) return flow;
	int i; int nowans=0,a;
	for (i=fox[x];i&&flow;i=s[i].before)
	  if (dis[s[i].ed]==dis[x]+1&&s[i].flow)
	  {
	  		   a=dfs(s[i].ed,min(flow,s[i].flow));
	  		   if (a) 
	  		   	{
	  		   		nowans+=a;
	  		   		flow-=a;
	  		   		s[i].flow-=a;
	  		   		s[i^1].flow+=a;
				}
	  }
	 if (!nowans) dis[x]=(int)1e9;
	 return nowans;
}
int maxflow()
{
   int ans=0,j;
   while (bfs()) ans+=dfs(st,(int)1e9); 
   return ans;
}
int main()
{
	 	scanf("%d%d%d",&n1,&n2,&m);
	 	for (i=1;i<=m;++i) scanf("%d%d",&B[i].x,&B[i].y),deg[B[i].x]++,deg[B[i].y+n1]++;
	 	for (i=1;i<=n1+n2;++i) deg[1]=min(deg[1],deg[i]);
	 	if (n1>n2) 
		{
		 	swap(n1,n2);
			 for  (i=1;i<=m;++i) swap(B[i].x,B[i].y);
		}
	 	puts("0");
		for (int Te=1;Te<=deg[1];++Te)
		{
				memset(fox,0,sizeof(fox));
				k1=1;
				S=n1+n2+1; T=S+1; st=T+1; ed=st+1;
				for (i=1;i<=m;++i) add(B[i].x,B[i].y+n1,1);
				add(S,ed,Te*n1);
				add(st,T,Te*n2); 
				for (i=1;i<=n1;++i) add(st,i,Te);
				for (i=1;i<=n2;++i) add(i+n1,ed,Te);
				for (i=1;i<=n1;++i) add(S,i,inf);
				for (i=1;i<=n2;++i) add(i,T,inf);
				maxflow();
				add(T,S,inf);
				maxflow(); 
				ans[0]=0;
				for (i=1;i<=n1;++i)
					for (j=fox[i];j;j=s[j].before)
						if (s[j].ed<=n1+n2&&s[j].flow==0) ans[++ans[0]]=(j+1)>>1;
				for (i=0;i<=ans[0];++i) printf("%d ",ans[i]);
				puts("");
		}
}