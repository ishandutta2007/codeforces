#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[4001][4001],G[4001][4001],a[4001];
int i,j,m,n,p,k,A[4001],B[4001],tot,Ans;
void Do(int x)
{ 
     int i,j;
     for (i=1;i<=tot;i++)
     G[A[x]][i]=max(G[A[x]][i],f[x][i]);
}
int main()
{ 
     scanf("%d",&n);
     for (i=1;i<=n;i++) G[i][j]=-(int)1e9;
     for (i=1;i<=n;i++)  scanf("%d",&a[i]),B[++tot]=a[i];
     sort(B+1,B+tot+1);
     tot=unique(B+1,B+tot+1)-(B+1);
     for (i=1;i<=n;i++) A[i]=lower_bound(B+1,B+tot+1,a[i])-B;
     for (i=1;i<=n;i++)
       for (j=1;j<=n;j++) f[i][j]=-(int)1e9;
	 for (i=1;i<=n;i++)
	   for (j=1;j<=i-1;j++)
	      f[i][A[j]]=2;
	Do(1);
	 for (i=2;i<=n;i++)
	{      
		  for (j=1;j<=tot;j++)
		     f[i][j]=max(f[i][j],G[j][A[i]]+1);
		Do(i);
    }
    Ans=1;
    for (i=1;i<=tot;i++) 
      for (j=1;j<=tot;j++)
        Ans=max(Ans,G[i][j]);
    printf("%d\n",Ans);
}