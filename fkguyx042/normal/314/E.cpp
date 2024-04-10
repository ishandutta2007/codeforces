#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
unsigned int f[100001];
int i,j,m,n,p,k,len;
char c[100001];
int main()
{scanf("%d",&n); getchar(); 
  f[0]=1; 
 for (i=1;i<=n;i++) c[len++]=getchar();
 for (i=0;i<len;i++)  
  if (c[i]!='?') ++k;
  int mid=n/2;
if (n&1||k>mid) printf("0\n");
else {
	 for (i=0;i<len;i++)
	   if (c[i]=='?')
	  for (j=i+1>>1;j>i-mid&&j;j--) f[j]+=f[j-1];
	for (i=1;i<=mid-k;i++) f[mid]*=25;
	printf("%u\n",f[mid]);
}
}