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
#define fi first
#define se second
#define mk make_pair

#define N 55
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
const int inf=(int)1e9;
int i,j,m,n,p,k,fox[N],k1,st,ed,dis[N],Q[N];
struct Node{int ed,before,flow;}s[M];
struct Bian{int x,y,z;}B[M];
void add(int x,int y,int z)
{
	 s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].flow=z;
	 s[++k1].ed=x; s[k1].before=fox[y]; fox[y]=k1; s[k1].flow=0;
}
bool bfs()
{
     int i,j,l;
     memset(dis,-1,sizeof(dis));
     Q[Q[0]=1]=st; dis[st]=0;
     for (l=1;l<=Q[0];++l)
     {
          int p=Q[l];
          for(i=fox[p];i;i=s[i].before)
             if (s[i].flow&&dis[s[i].ed]==-1)
             {
                  dis[s[i].ed]=dis[p]+1;
                  Q[++Q[0]]=s[i].ed;
             }
     }
     return dis[ed]!=-1;    
}
int zyb(int x,int flow)
{
    int a,nowans=0,i;
    if (x==ed) return flow;
    for (i=fox[x];i&&flow;i=s[i].before)
       if (s[i].flow&&dis[x]+1==dis[s[i].ed])
         if (a=zyb(s[i].ed,min(flow,s[i].flow)))
         {
              nowans+=a;
              s[i].flow-=a;
              s[i^1].flow+=a;
              flow-=a;
         }
    if (!nowans) dis[x]=inf;
    return nowans;
}
int maxflow()
{
      int ans=0,j;
      while (bfs())
      {
             j=zyb(st,inf); 
             while (j) 
             ans+=j,j=zyb(st,inf);
      }
      return ans;
}
bool check(double x)
{
	  memset(fox,0,sizeof(fox)); k1=1;
	  for (i=1;i<=m;++i) add(B[i].x,B[i].y,(int)min(1.*k,1.*B[i].z/x));
	  if (maxflow()>=k) return 1;
	  return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	st=1; ed=n;
	for (i=1;i<=m;++i) scanf("%d%d%d",&B[i].x,&B[i].y,&B[i].z);
	double l=1./k,r=1000000,mid=0;	
	for(;r-l>1e-8;)
	{
	  mid=(l+r)/2.;
	  if(check(mid)) l=mid; else r=mid;
    }
    printf("%.10lf\n",l*k);
}