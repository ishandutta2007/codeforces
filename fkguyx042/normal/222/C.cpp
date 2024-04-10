#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,k1,l=0,r;
struct Node{int ed,before;}s[3000001];
int Prime[2][10000001],A[1000001],B[1000001],vis[10000001],fox[10000001],Vis[100001],prime[100001];
void add(int x,int y) {s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1;}
void Go(int x,int y)
{  int i; 
   if (!vis[x]) { vis[x]=1; int X=x;
   for (i=1;prime[i]*prime[i]<=x;i++)
     if (x%prime[i]==0)
     {  while (x%prime[i]==0) x/=prime[i],Prime[y][prime[i]]++,add(X,prime[i]); }
    if (x>1) Prime[y][x]++,add(X,x); }
     else {
     	     for (i=fox[x];i;i=s[i].before) Prime[y][s[i].ed]++; }
}
void Got_Prime()
{ int i,j;
   for (i=2;i<=10000;i++)
    if (!Vis[i])
    {  prime[++prime[0]]=i;
       for (j=i;j<=10000;j+=i) Vis[j]=1;
}
}
int main()
{  scanf("%d%d",&n,&m); Got_Prime();
   for (i=1;i<=n;i++)
    scanf("%d",&A[i]),Go(A[i],1);
   for (i=1;i<=m;i++) scanf("%d",&B[i]),Go(B[i],0);
   for (i=1;i<=n;i++) 
     { k=A[i];
       for (j=fox[k];j;j=s[j].before) if (Prime[0][s[j].ed]) A[i]/=s[j].ed,Prime[0][s[j].ed]--;
    }
    for (i=1;i<=m;i++) 
     { k=B[i];
       for (j=fox[k];j;j=s[j].before) if (Prime[1][s[j].ed]) B[i]/=s[j].ed,Prime[1][s[j].ed]--;
    }
printf("%d %d\n",n,m);
for (i=1;i<=n;i++) printf("%d ",A[i]); printf("\n");
for (i=1;i<=m;i++) printf("%d ",B[i]);
}