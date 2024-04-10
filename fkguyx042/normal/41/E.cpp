#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005

using namespace std;
int i,j,m,n,p,k,A[N],a,b,ans;
int main()
{
     scanf("%d",&n);
     int ax=n/2,ay=n-ax;
	 printf("%d\n",ax*ay);
	 for (i=1;i<=ax;++i) 
	     for (j=1;j<=ay;++j) printf("%d %d\n",i,j+ax); 
}