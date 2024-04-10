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

#define N 305
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N][N],x;
int main()
{
	 scanf("%d%d",&n,&x);
	 if (n==5) printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
	 else if (n==3) printf(">vv\n^<.\n^.<\n1 3\n");
	 else 
	 {
	 	  for (i=1;i<=n/2;++i)
	 	  {
	 	  	   int A=(n-2)/3,B=(n-2)/3+(n-2)%3;
	 	  	   for (j=1;j<=B;++j) printf(">");
	 	  	   for (j=1;j<=A;++j) printf(".>");
	 	  	   printf(".v\n");
	 	  	   printf("^.");
	 	  	   for (j=1;j<=A;++j) printf("<.");
	 	  	   for (j=1;j<=B;++j) printf("<");
	 	  	   puts("");
	 	  }
	 	  printf("1 %d\n",n);
	 }
}