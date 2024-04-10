#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>

#define N 205
#define M 1005

const int INF=(int)1e9;

using namespace std;

bitset<N>bit[N],Bit,Bi,bite[N],Ch,del[N],C,D;

int i,j,m,n,p,k,dis[N],vis[N],fox[N],que[N],K1=1,Tree[N],B[N][N],Sum[N][N],st,ed,k1,Source[N],Q[N],ans;
int x,y,c,tot,Ans[N];

struct Node{int ed,before,flow;}S[M*10],s[M*10];
struct syc{int x,y,z;}Bian[N];

inline bool cmp(syc a,syc b)
{
	   return a.z<b.z;
}
void Add(int x,int y,int z)
{
	 S[++K1].ed=y; S[K1].before=fox[x]; fox[x]=K1; S[K1].flow=z;
}
void pre()
{
	 int i;
    for (i=1;i<=K1;++i) s[i]=S[i];	  
    k1=K1;  
}
inline int bfs()
 { int i,p,l,r;
   memset(dis,-1,sizeof(dis));
    l=r=1;
    dis[st]=0;
   que[1]=st;
   while (l<=r)
    { p=que[l];
      for (i=fox[p];i;i=s[i].before)
        if (s[i].flow>0)
        if (dis[s[i].ed]==-1)
         { 
           que[++r]=s[i].ed;
           dis[s[i].ed]=dis[p]+1;
           }
    l++;
}
 if (dis[ed]==-1) return 0;
 return 1;
}
int dfs(int num,int flow)
 {  int i;
    int a,nowans=0;
   if (num==ed) return flow;
     for (i=fox[num];i&&flow;i=s[i].before)
       if (s[i].flow>0&&dis[s[i].ed]==dis[num]+1)
        if(a=dfs(s[i].ed,min(s[i].flow,flow)))
         { s[i].flow-=a;
           s[i^1].flow+=a;
           flow-=a;nowans+=a;
           }if (!nowans) dis[num]=(int)1e9;
   return nowans;
}
void count()
{
	  Q[Q[0]=1]=st;
	  int i,p,l;
	  for (i=1;i<=n;++i) Source[i]=0;
	  Source[st]=st; memset(vis,0,sizeof(vis)); vis[st]=1;
	  for (l=1;l<=Q[0];++l)
	{ 
	   p=Q[l];
	   for (i=fox[p];i;i=s[i].before)
	     if (s[i].flow&&!vis[s[i].ed])
	     {
	     	  vis[s[i].ed]=1;
	     	  Q[++Q[0]]=s[i].ed;
	     	  Source[s[i].ed]=st;
	     }
	}
}
int maxflow()
{ int j;
  int ans=0;
    while (bfs())
    { j=dfs(st,(int)1e9);  while (j) ans+=j,j=dfs(st,(int)1e9); }
    count();
  return ans;
}
void Find_tree()
{
	  for (i=2;i<=n;++i) Sum[1][i]=Sum[i][1]=1;
	  for (i=1;i<=n;++i)
	    for (j=i+1;j<=n;++j)
	        if (Sum[i][j]!=0)
	        {
	        	    st=j; ed=i; pre();
	        	    Sum[i][j]=Sum[j][i]=maxflow();
	        	    for (k=j+1;k<=n;++k)
	        	      if (Sum[k][i]!=0&&Source[k]==j)
	        	    {
	        	    	 Sum[k][i]=Sum[i][k]=0;
	        	    	 Sum[j][k]=Sum[k][j]=1;
	        	    }
	        }
}
void add(int x,int y,int z)
{
   s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].flow=z;
   s[++k1].ed=x; s[k1].before=fox[y]; fox[y]=k1; s[k1].flow=z;
}
void Bfs(int x,int Need)
{
	 Q[Q[0]=1]=x; memset(vis,0,sizeof(vis));
	 bit[Need][x]=1;
	 int l=1,i,p;
	 for (l=1;l<=Q[0];++l)
	 {
	 	  p=Q[l];
	 	  for (i=fox[p];i;i=s[i].before)
	 	    if (!vis[s[i].ed]&&s[i].flow!=Need)
	 	    {
	 	    	  int k=s[i].ed;
	 	    	  bit[Need][k]=1;
	 	    	  bite[Need][s[i].flow]=1;
	 	    	  Q[++Q[0]]=k;
	 	    	  vis[k]=1;
	 	    }
	 }
}
void Dfs(bitset<N> a,bitset<N> b)
{
	   int sum=0;
	   for (i=1;i<=n;++i) if (a[i]) ++sum;
	   if (sum==1) 
	   {
	   	   int i;
	   	   for (i=1;i<=n;++i) if (a[i]) break;
	   	   Ans[++Ans[0]]=i;
	   	   return;
       }
       else 
       { 
           int i;
           for (i=1;i<=n;++i) if (b[i]) break;
           C=a&bit[i]; D=b&bite[i];
           for (j=1;j<=n;++j) if (C[j]||C[j]) break;
           if (C[j])
           {
           Dfs(a&bit[i],b&bite[i]); 
           Dfs(a&(bit[i]^Ch),(b&(bite[i]^Ch))^del[i]);
           }
           else 
           {
           	Dfs(a&(bit[i]^Ch),(b&(bite[i]^Ch))^del[i]);
           	Dfs(a&bit[i],b&bite[i]);
		   }
       }
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (;m--;)
	 {
	 	  scanf("%d%d%d",&x,&y,&c);
	 	  Add(x,y,c); Add(y,x,c);
	 }
	 Find_tree();
     for (i=1;i<=n;++i)
       for (j=i+1;j<=n;++j) ans+=Sum[i][j];
       printf("%d\n",ans);
     for (i=1;i<=n;++i)
       for (j=i+1;j<=n;++j)
	     if (Sum[i][j]) Bian[++tot].x=i,Bian[tot].y=j,Bian[tot].z=Sum[i][j];
	 sort(Bian+1,Bian+tot+1,cmp);
	 memset(fox,0,sizeof(fox)); k1=0;
	 for (i=1;i<=tot;++i) add(Bian[i].x,Bian[i].y,i);
	 for (i=1;i<=tot;++i) Bfs(Bian[i].x,i);
	 for (i=1;i<=n;++i)  Bit[i]=Bi[i]=1;
	 for (i=1;i<=n;++i) Ch[i]=1;
	 for (i=1;i<=n;++i) del[i][i]=1;
	 Dfs(Bit,Bi);
	 for (i=1;i<=n;++i) printf("%d ",Ans[i]);
}