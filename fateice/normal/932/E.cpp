#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007;
int n,m,f[5010],p;
inline int power(int a,int b)
{
    if(b<=0)
      return 1;
    int c=power(a,b>>1);
    c=(L)c*c%q;
    if(b&1)
      c=(L)c*a%q;
    return c;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	f[0]=1;
	for(i=1;i<=m;i++)
	  {
	   for(j=i;j>0;j--)
	     f[j]=((L)f[j]*j+(L)f[j-1]*(n-j+1))%q;
	   f[0]=0;
      }
	for(i=1;i<=m;i++)
	  p=(p+(L)f[i]*power(2,n-i))%q;
	printf("%d\n",p);
	return 0;
}