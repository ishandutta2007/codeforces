#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long Tmp[100005],ans[100001],sky[100005],size[100005];
struct Node{int ed,before;}s[100005];
int vis[335][100001],i,j,m,n,p,k,q,a[100001],Q[100001],fox[100005],x,tot,k1,y;
char c[2];
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1;}
int main()
{scanf("%d%d%d",&n,&m,&q);
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
 for (i=1;i<=m;i++)
 { scanf("%d",&size[i]);
   for (j=1;j<=size[i];j++)
    { scanf("%d",&x);add(i,x); ans[i]+=a[x]; }
    if (size[i]>=300) Q[++tot]=i;
}
 for (i=1;i<=tot;i++)
 {    memset(sky,0,sizeof(sky));
      for (j=fox[Q[i]];j;j=s[j].before) sky[s[j].ed]++;
      for (j=1;j<=m;j++)
       for (k=fox[j];k;k=s[k].before) if (sky[s[k].ed]) vis[i][j]++;
 }
 memset(sky,0,sizeof(sky));
 for (;q--;)
{ scanf("%s",&c);
  if (c[0]=='+')
  { scanf("%d%d",&x,&y);
    if (size[x]<300)
   {    for (j=fox[x];j;j=s[j].before) sky[s[j].ed]+=y;
        for (j=1;j<=tot;j++) ans[Q[j]]+=1ll*vis[j][x]*y;
   }
   else Tmp[x]+=y; 
  }
  else {
  	    scanf("%d",&x);
  	    long long Ans=ans[x];
  	    if (size[x]<300)
  	{   for  (j=fox[x];j;j=s[j].before) Ans+=sky[s[j].ed]; }
  	    for  (j=1;j<=tot;j++) Ans+=1ll*vis[j][x]*Tmp[Q[j]];
  	    printf("%I64d\n",Ans);
    }
}
}