#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007;
int f[1010][1010],n,a,b;
inline int power(int a,int b)
{
	if(!b)
	  return 1;
	int c=power(a,b>>1);
	c=(L)c*c%q;
	if(b&1)
	  c=(L)c*a%q;
	return c;
}
inline int calc(int i,int j)
{
	if(j>=n)
	  return j;
	else
	  return f[i][j];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&a,&b);
	i=power(a+b,q-2);
	a=(L)a*i%q;
	b=(L)b*i%q;
	for(i=0;i<n;i++)
	  f[n][i]=(n+i+power(b,q-2)-1)%q;
	for(i=n-1;i>=0;i--)
	  for(j=n-1;j>=0;j--)
	    f[i][j]=((L)a*f[i+1][j]+(L)b*calc(i,i+j))%q;
	printf("%d\n",f[1][0]);
	return 0;
}