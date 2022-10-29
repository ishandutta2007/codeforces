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

#define N 155
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,tot,End,id[N][N];
bitset<N*N>A,L,R,U,D,B,C;
char c[N][N],s[M];
int main()
{
	   scanf("%d%d%d",&n,&m,&k);
	   for (i=0;i<n;++i) for (j=0;j<m;++j) id[i][j]=tot++;
	   for (i=0;i<n;++i)
	   {
	   	     scanf("%s",c[i]);
	   	     for (j=0;j<m;++j)  if (c[i][j]=='E') End=id[i][j];
	   }
	   for (i=0;i<n;++i)
	     for (j=0;j<m;++j)
		   if (c[i][j]!='#')
		   {
		     	 A[id[i][j]]=1;
		     	 if (c[i-1][j]=='#') U[id[i][j]]=1;
		     	 if (c[i+1][j]=='#') D[id[i][j]]=1;
		     	 if (c[i][j-1]=='#') L[id[i][j]]=1;
		     	 if (c[i][j+1]=='#') R[id[i][j]]=1;
		   }
	   scanf("%s",s);
	   for (i=0;i<n*m;++i) B[i]=1;
	   for (i=0;i<=k;++i)
	   {
	   	   C=A&B; 
	   	   if (C.count()==1&&A[End]) break;
	   	   if (s[i]=='L') A=(A&L)|((A^(A&L))>>1);
	   	   if (s[i]=='R') A=(A&R)|((A^(A&R))<<1);
	   	   if (s[i]=='U') A=(A&U)|((A^(A&U))>>m);
	   	   if (s[i]=='D') A=(A&D)|((A^(A&D))<<m);
	   }
	   if (i>k) printf("-1\n"); else printf("%d\n",i);
}