#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<iomanip>


#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int Pc=0,i,j,m,n,p,k,fox[N],k1,a[N],x,y,z,vis[N],Q[N],Rt[N],deep[N],Belong[20][N],fa[N],size[N],ansx,dis[N];
int Dis[N],Vis[N];
double A;
double ans=(double)1e30,Ans[N];
struct Node{int ed,before,cost;}s[N*2];
void add(int x,int y,int z)
{
	 s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=z;
}
void bfs(int x)
{
   Q[Q[0]=1]=x; Rt[x]=1;
   for (int i=1;i<=Q[0];i++)
   { 
      int p=Q[i];
      for (int j=fox[p];j;j=s[j].before)
        if (!(vis[s[j].ed]||Rt[s[j].ed]))
        {   
              int A=s[j].ed;
              deep[A]=deep[x]+1;
              Q[++Q[0]]=A;
              Rt[A]=1;
        }
   }
      for (int i=1;i<=Q[0];i++) Rt[Q[i]]=0;
      for (int i=1;i<=Q[0];++i) Belong[deep[x]][Q[i]]=x;
}
int getroot(int x)
{ 
   Q[Q[0]=1]=x; Rt[x]=1; fa[x]=0; 
   for (int i=1;i<=Q[0];i++)
  {
       int p=Q[i];
       for (int j=fox[p];j;j=s[j].before)
       { 
            int A=s[j].ed;
             if (vis[A]||Rt[A]) continue;
            Q[++Q[0]]=A;
            fa[A]=p;
            Rt[A]=1;
       }
  }
  int A1=0,A2=1000000;
  for (int i=Q[0];i;i--)
{ 
    int p=Q[i]; size[p]=1; int Max=-1;
    for (int j=fox[p];j;j=s[j].before)
   { 
        int A=s[j].ed;
        if (vis[A]||fa[p]==A) continue;
        Max=max(Max,size[A]);
        size[p]+=size[A];
   }
   Max=max(Max,Q[0]-size[p]);
   if (Max<A2)
   { 
     A1=p; A2=Max; 
   }
}
for (int i=1;i<=Q[0];i++) Rt[Q[i]]=0;
return A1;
}
void Fen(int x)
{
	  int i;
	  int root=getroot(x); 
	  bfs(root);
	  vis[root]=1;
	  for (i=fox[root];i;i=s[i].before)
	     if (!vis[s[i].ed]) Fen(s[i].ed);
}
double P(double x)
{
	  return x*sqrt(x);
}
void getans(int x)
{
  int i,l;
   for (i=1;i<=n;++i) Vis[i]=0;
   dis[x]=0; Vis[x]=1;
   Q[Q[0]=1]=x;
   for (l=1;l<=Q[0];++l)
   {
   	  p=Q[l];
   	  for (i=fox[p];i;i=s[i].before)
   	     if (!Vis[s[i].ed])
   	     {
   	     	 Vis[s[i].ed]=1;
   	     	 dis[s[i].ed]=dis[p]+s[i].cost;
   	     	 Q[++Q[0]]=s[i].ed;
   	     }
   }
   double sum=0;
   for (i=1;i<=n;++i) sum+=(double)a[i]*P(dis[i]);
   if (sum<ans) ans=sum,ansx=x;
}
double Bfs(int x,int y,int z)
{
	  Pc++;
	  vis[x]=vis[y]=Pc; 
	  Q[Q[0]=1]=x; Dis[x]=0;
	  int i,l;
	  for (l=1;l<=Q[0];++l)
	  {
	  	  int p=Q[l];
	  	  for (i=fox[p];i;i=s[i].before)
	  	     if (vis[s[i].ed]!=Pc)
	  	     {
	  	     	  vis[s[i].ed]=Pc;
	  	     	  Dis[s[i].ed]=Dis[p]+s[i].cost;
	  	     	  Q[++Q[0]]=s[i].ed;
	  	     }
	  }
	  double S=0;
	  for (i=1;i<=Q[0];++i) S+=(double)a[Q[i]]*sqrt(Dis[Q[i]]+z);
	  return S;
}
void Get(int x)
{
     getans(x);
  //   if (n==1000)
    // printf("%d\n",x);
     int id=0; double sum=-(double)1e30,R;
	 for (i=fox[x];i;i=s[i].before)
	 	   
	     if (deep[s[i].ed]>deep[x])
	    {
	    	R=Bfs(s[i].ed,x,s[i].cost);
		  if (!id||sum<R) id=s[i].ed,sum=R;
	    }
	  if (!id) return;
	  Get(Belong[deep[x]+1][id]);
}
int read()
{
	  int x=0; char c;
	  while (c=getchar(),c<'0'||c>'9');
	  x=c-'0';
	  while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	  return x;
}
int main()
{
//	 freopen("gather.in","r",stdin);
//	 freopen("gather.out","w",stdout);
	scanf("%d",&n);// scanf("%lf",&A);
	for (i=1;i<=n;++i) //scanf("%d",&a[i]);
	  a[i]=read();
	for (i=1;i<n;++i) //scanf("%d%d%d",&x,&y,&z),
	x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	Fen(1);
	memset(vis,0,sizeof(vis));
	for (i=1;i<=n;++i) if (Belong[0][i]==i) break;
	Get(i);
	  printf("%d ",ansx);
	  cout<<fixed<<setprecision(10)<<ans<<endl;
}