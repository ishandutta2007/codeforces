#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
const int Mo=777777777;
using namespace std;
int Tree[500001][4][4];
int f[4][4],ans,x,i,j,m,n,p,k,t,w;
int a[100001];
void up(int t)
{ int i,j,k,l;
  memset(Tree[t],0,sizeof(Tree[t]));
   for (i=1;i<=3;i++)
     for (j=1;j<=3;j++)if (Tree[ls][i][j])
      for (k=1;k<=3;k++)if (f[j][k])
        for (l=1;l<=3;l++)
         if (Tree[rs][k][l])
         (Tree[t][i][l]+=1ll*Tree[ls][i][j]*Tree[rs][k][l]%Mo)%=Mo;
}
int ask()
{ int sum=0,i,j;
  for (i=1;i<=3;i++)
    for (j=1;j<=3;j++) 
      (sum+=Tree[1][i][j])%=Mo;
    return sum;
}
void build_tree(int l,int r,int t)
{ if (l==r)
 {  int i; for (i=1;i<=3;i++) Tree[t][i][i]=1; }
 else {build_tree(l,mid,ls),build_tree(mid+1,r,rs);
   up(t);}
}
void update(int ll,int l,int r,int t)
{ if (l==r)
  {   int i,j; for (i=1;i<=3;i++) for (j=1;j<=3;j++) Tree[t][i][j]=0;  
       if (a[ll]) Tree[t][a[ll]][a[ll]]=1;
       else for (i=1;i<=3;i++) for (j=1;j<=3;j++) Tree[t][i][i]=1;
  }
  else { if (ll<=mid) update(ll,l,mid,ls);
         else update(ll,mid+1,r,rs);
        up(t);
}
} 
int main()
{ 
    scanf("%d%d",&n,&m);
   for (i=1;i<=3;i++)
    for(j=1;j<=3;j++) scanf("%d",&f[i][j]);
    build_tree(1,n,1);
   for (i=1;i<=m;i++)
   { scanf("%d%d",&t,&w);
    a[t]=w;
    update(t,1,n,1);
    printf("%d\n",ask());
   }
}