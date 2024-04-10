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

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
vector<int>v[N];
int i,j,m,n,p,k,fa[N],a[N],x,y,l;
long long f[N][3][2];
void add(int x,int y)
{
	 v[x].push_back(y);
}
void dfs(int x)
{
	int i;
	for (i=0;i<(int)v[x].size();++i)
	{  
	      int p=v[x][i];
	      if (fa[x]==p) continue;
	      fa[p]=x;
	      dfs(p);
	}
	f[x][0][0]=0; long long Max=0,CMax=0;
	for (i=0;i<(int)v[x].size();++i)
	{
		  int p=v[x][i];
		  if (fa[x]==p) continue;
		  f[x][1][0]=max(f[x][1][0],f[p][1][0]);
		  f[x][1][1]=max(f[x][1][1],f[p][1][1]);
		  f[x][2][1]=max(f[x][2][1],f[p][2][1]);
		  f[x][2][0]=max(f[x][2][0],f[p][2][0]);
		  if (f[p][1][1]>Max) swap(Max,CMax),Max=f[p][1][1];
		  else if (f[p][1][1]>CMax) CMax=f[p][1][1];
    }
    f[x][1][0]=max(f[x][1][0],Max+CMax+a[x]);
	f[x][1][1]+=a[x];
	long long M2[3]={0},M1[3]={0},id1[3]={0},id2[3]={0},M3[3]={0},id3[3]={0};
	for (i=0;i<(int)v[x].size();++i)
	{
		   int p=v[x][i];
		   if (fa[x]==p) continue;
		   for (j=0;j<=2;++j) if (f[p][1][1]>M1[j]) break;
		   if (j<=2)
		   {
		   	  for (k=1;k>=j;--k) swap(M1[k],M1[k+1]),swap(id1[k],id1[k+1]);
		   	  M1[j]=f[p][1][1]; id1[j]=p;
		   }
		   for (j=0;j<=2;++j) if (f[p][1][0]>M2[j]) break;
		   if (j<=2)
		   {
		   	  for (k=1;k>=j;--k) swap(M2[k],M2[k+1]),swap(id2[k],id2[k+1]);
		   	  M2[j]=f[p][1][0]; id2[j]=p;
		   }
		   for (j=0;j<=2;++j) if (f[p][2][1]>M3[j]) break;
		   if (j<=2)
		   {
		   	  for (k=1;k>=j;--k) swap(M3[k],M3[k+1]),swap(id3[k],id3[k+1]);
		   	  M3[j]=f[p][2][1]; id3[j]=p;
		   }
	}
	if (id1[0]!=id2[0]) f[x][2][1]=max(f[x][2][1],M1[0]+M2[0]);
	else f[x][2][1]=max(f[x][2][1],M1[0]+M2[1]);
	if (id1[1]!=id2[0]) f[x][2][1]=max(f[x][2][1],M1[1]+M2[0]);
	else f[x][2][1]=max(f[x][2][1],M1[1]+M2[1]);
	f[x][2][1]+=a[x];
	f[x][2][0]=max(f[x][2][0],M2[0]+M2[1]);
//2 f[p][1][1] && 1 f[p][1][0]
   for (j=0;j<=2;++j)
      for (k=0;k<=2;++k)
         if (j!=k)
         for (l=0;l<=2;++l)
             if (id1[j]!=id2[l]&&id1[k]!=id2[l])
                f[x][2][0]=max(f[x][2][0],M1[j]+M1[k]+M2[l]+a[x]);
//1 f[p][1][1] && 1 f[p][2][1]
   for (j=0;j<=2;++j)
     for (k=0;k<=2;++k)
	     if (id1[j]!=id3[k])
		    f[x][2][0]=max(f[x][2][0],M1[j]+M3[k]+a[x]); 
	f[x][2][0]=max(f[x][2][0],f[x][2][1]);
	f[x][1][0]=max(f[x][1][0],f[x][1][1]);
}
int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]);
 	 for (i=1;i<n;++i)
	 {
	 	  scanf("%d%d",&x,&y);
	 	  add(x,y); add(y,x);
	 }
	 dfs(1);
	 printf("%I64d\n",f[1][2][0]);
}