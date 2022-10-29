#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[3001],v,i,j,m,n,p,k,ans,Las[401][401],Ans[401][401],sm;
struct Node{int l,r,fi,id;}Q[3001];
int f[401][401],as[401][401];
inline bool cmp(Node a,Node b) {return a.fi<b.fi;}
int main()
{ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&v);
  for (i=0;i<n;i++) scanf("%d",&a[i]);
  memset(f,-1,sizeof(f));
  f[0][0]=0; scanf("%d",&m);
  for (i=1;i<=m;i++) scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].fi),Q[i].id=i;
  sort(Q+1,Q+m+1,cmp);
  for (i=0;i<n;i++)
   for (j=0;j<=400;j++)
     if (f[i][j]!=-1)
  {  int Last=j+a[i]-v;
     if(f[i+1][min(a[i],Last)]<f[i][j])
     {
     f[i+1][min(a[i],Last)]=max(f[i+1][min(a[i],Last)],f[i][j]);
     Las[i+1][min(a[i],Last)]=j;
     Ans[i+1][min(a[i],Last)]=0;
     }
     int Now=0,sum=0;
     for (k=1;k<=m;k++)
      if (Q[k].l<=i+1&&Q[k].r>=i+1)
      { Now+=Q[k].fi,sum++;
        if (Last>=Now)
        {
        if (f[i+1][min(a[i],Last-Now)]<f[i][j]+sum)
        {
        f[i+1][min(a[i],Last-Now)]=max(f[i+1][min(a[i],Last-Now)],f[i][j]+sum);
		Las[i+1][min(a[i],Last-Now)]=j;
		Ans[i+1][min(a[i],Last-Now)]=sum;
		}
		}else break;
    }
}
ans=-1;
for (i=0;i<=400;i++)
if (ans<f[n][i])
 ans=max(f[n][i],ans),j=i;
 printf("%d\n",ans);
 for (i=n;i;i--)
 {  //printf("%d ",Ans[i][j]);
     as[i][0]=Ans[i][j];
     for (k=1,sm=0;sm!=Ans[i][j];k++)
     if (Q[k].l<=i&&Q[k].r>=i) as[i][++sm]=Q[k].id;//printf("%d ",Q[k].id),sm++;
     j=Las[i][j];
}
for (i=1;i<=n;i++)
{ printf("%d ",as[i][0]);
  for (j=1;j<=as[i][0];j++) printf("%d ",as[i][j]);
  printf("\n");
}
}