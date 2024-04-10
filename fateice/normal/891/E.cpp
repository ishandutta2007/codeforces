#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007;
int n,m,a[5010],f[5010][5010],x[5010],p;
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
inline int C(int n,int m)
{
	int i,k;
	for(i=n,k=1;i>n-m;i--)
	  k=(L)k*i%q;
	return k;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	f[0][0]=1;
	for(i=1;i<=n;i++)
	  {
	   f[i][0]=1;
	   for(j=1;j<=i;j++)
	     f[i][j]=(f[i-1][j]+(L)f[i-1][j-1]*a[i])%q;
	  }
	x[0]=1;
	for(i=1,k=power(n,q-2);i<=n && i<=m;i++,k=(L)k*power(n,q-2)%q)
	  x[i]=(L)C(m,i)*k%q;
	for(i=1,k=1;i<=n;i++,k=-k)
	  p=(p+(L)k*x[i]*f[n][n-i])%q;
	p=(p+q)%q;
	cout<<p;
	return 0;
}