#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005
#define M 20

using namespace std;
const int inf=(int)1e9;

int f[M+1][1<<M],bit[N],i,j,m,n,p,k,all,len;

char c[M];

int check(int x,int y)
{
     int i;
     for (i=len;i>=0;--i) 
       if ((x&((1<<i)-1))==(y>>(len-i))) return i;
}
int main()
{
     memset(f,60,sizeof(f));
     scanf("%d",&n);
     for (i=1;i<=n;++i)
     {
     	  scanf("%s",c);
     	  len=strlen(c);
     	  for (j=0;j<len;++j) bit[i]=bit[i]*2+c[j]-'0';
	 }
	 f[0][0]=len;
	 for (i=2;i<=n;++i)
	 {
	 		int x=len-check(bit[i-1],bit[i]),now=inf;
	 		for (j=len;j>=0;--j)
	 		     now=min(now,f[j][bit[i]>>(len-j)]+len-j+all);
	 		all+=x;
	 		for (j=len;j>=0;--j)
	 		    f[j][bit[i-1]&((1<<j)-1)]=min(f[j][bit[i-1]&((1<<j)-1)],now-all);
	 }
	 printf("%d\n",f[0][0]+all);
}