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

#define LIM 200000
#define N 10
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p[N],k,a[5][5],limA,limB,limC,A[N][N],ans[LIM+5];
int guass()
{
	  int i,j,k;
	  for (i=1;i<=7;++i)
	 { 
	      for (j=i;j<=7;++j) if (A[j][i]) break;
	      for (k=1;k<=8;++k) swap(A[i][k],A[j][k]);
	      for (j=i+1;j<=7;++j)
		  { 
		    if (A[j][i]%A[i][i]!=0) return 0;
	      	   int lim=A[j][i]/A[i][i];
	      	   for (k=1;k<=8;++k)
	      	          A[j][k]=A[j][k]-A[i][k]*lim;
	      }
	}
	 for (i=7;i;--i)
	{
		   for (j=i+1;j<=7;++j) A[i][8]-=p[j]*A[i][j];
		   if (A[i][8]%A[i][i]!=0) return 0;
		   p[i]=A[i][8]/A[i][i];
	}
	return 1;
}
void print(int x)
{
	  int i;
	  printf("%d\n",x);
	  for (i=1;i<8;++i)
	    for (j=1;j<=p[i];++j) ans[++ans[0]]=i;
	  for (i=1;i<=ans[0];++i) printf("a"); puts("");
	  for (i=1;i<=ans[0];++i)
	      if (ans[i]<=4) printf("b"); else printf("a"); puts("");
	  for (i=1;i<=ans[0];++i)
	      if (ans[i]<=2||ans[i]>=7) printf("a"); else printf("b"); puts("");
	  for (i=1;i<=ans[0];++i)
	      if (ans[i]==1||ans[i]==3||ans[i]==5) printf("a"); else printf("b"); puts("");
}
bool check(int x)
{
	   int i;
	   memset(A,0,sizeof(A));
	   memset(p,0,sizeof(p));
	   A[1][1]=1;A[1][2]=1;A[1][8]=limA;
	   A[2][3]=1;A[2][4]=1;A[2][8]=limB;
	   A[3][5]=1;A[3][6]=1;A[3][8]=limC;
	   A[4][7]=1;A[4][8]=x-limA-limB-limC;
	   A[5][2]=1;A[5][4]=1;A[5][6]=1;A[5][7]=1;A[5][8]=a[1][4];
	   A[6][1]=1;A[6][3]=1;A[6][6]=1;A[6][7]=1;A[6][8]=a[2][4];
	   A[7][2]=1;A[7][3]=1;A[7][5]=1;A[7][7]=1;A[7][8]=a[3][4];
	   if (!guass()) return 0;
	   for (i=1;i<8;++i) if (p[i]<0) return 0;
	   print(x);
	   return 1;
}
int main()
{
	   for (i=1;i<4;++i)
	     for (j=i+1;j<=4;++j) scanf("%d",&a[i][j]);
	   for (i=0;i<=a[1][2];++i)
	        if (a[1][3]-i>=0&&a[2][3]-(a[1][2]-i)>=0&&a[1][3]-i==a[2][3]-(a[1][2]-i)) break;
	   if (i>a[1][2]) { printf("-1\n"); return 0; }
	   limA=a[1][2]-i,limB=i,limC=a[1][3]-i;
	   for (i=limA+limB+limC;i<=LIM;++i) if (check(i)) return 0;
	   printf("-1\n");
}