#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>

#define N 20005

using namespace std;
int i,j,m,n,p,k,s1,s2,f,x,y,z,k1,fox[N],Q[3000005],vis[N/2];
int L[N],R[N],X[N],Y[N],w[N];
long long dis[2][N];
struct Node{int ed,before,cost;}s[N];
const long long inf=(long long)1e10;
void add(int x,int y,int z)
{
	 s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=z;
}
void Return(string s)
{
	 cout<<s<<endl;
	 if (s=="LOSE") exit(0);
	 for (i=m+1;i<=m+k;++i) printf("%d ",w[i]);
	 exit(0);
}
void spfa(long long *a,int x)
{
	 Q[Q[0]=1]=x;  memset(vis,0,sizeof(vis));
	 vis[x]=1; 
	 int i,l,p;
	 for (i=1;i<=n;++i) a[i]=inf; a[x]=0;
	 for (l=1;l<=Q[0];++l)
	 {
	 	  p=Q[l];
	 	    for (i=fox[p];i;i=s[i].before)
	 	     if (a[p]+s[i].cost<a[s[i].ed])
             {
	 	       a[s[i].ed]=a[p]+s[i].cost; 
	 	       if (!vis[s[i].ed]) Q[++Q[0]]=s[i].ed,vis[Q[Q[0]]]=1;
	 	     }
	 	 vis[p]=0;
	 }
}
int main()
{
	 scanf("%d%d%d%d%d%d",&n,&m,&k,&s1,&s2,&f);
	 for (i=1;i<=m;++i)
	 { 
	   scanf("%d%d%d",&x,&y,&z);
	   add(x,y,z);
     }
     for (i=m+1;i<=m+k;++i)
     {
     	 scanf("%d%d%d%d",&X[i],&Y[i],&L[i],&R[i]);
     	 add(X[i],Y[i],R[i]); w[i]=R[i];
     }
     spfa(dis[0],s1);
     spfa(dis[1],s2);
     if (dis[0][f]<dis[1][f]) Return("WIN");
     for (;;)
     {
     	 int mask=0;
     	 for (j=m+1;j<=m+k;++j)
     	   if (dis[0][X[j]]<dis[1][X[j]]&&w[j]==R[j]&&L[j]!=R[j])
     	   {
     	   	    s[j].cost=L[j];
     	   	    w[j]=L[j];
     	   	    spfa(dis[0],s1);
     	   	    spfa(dis[1],s2);
     	   	    mask=1;
     	   	    if (dis[0][f]<dis[1][f]) Return("WIN");
     	   }
     	  for (j=m+1;j<=m+k;++j)
     	   if (dis[0][X[j]]>dis[1][X[j]]&&w[j]==L[j]&&L[j]!=R[j])
     	   {
     	   	    s[j].cost=R[j];
     	   	    w[j]=R[j];
     	   	    spfa(dis[0],s1);
     	   	    spfa(dis[1],s2);
     	   	    mask=1;
     	   	    if (dis[0][f]<dis[1][f]) Return("WIN");
     	   }
     	 if (!mask) break;
     }
     if (dis[0][f]==dis[1][f]) Return("DRAW"); else Return("LOSE");
}