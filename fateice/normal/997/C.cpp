#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=998244353;
int n,a[1000010],b[1000010],p;
inline int power(int a,L b)
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
    return (L)a[n]*b[m]%q*b[n-m]%q;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	a[0]=b[0]=1;
	for(i=1;i<=n;i++)
	  {
	   a[i]=(L)a[i-1]*i%q;
	   b[i]=power(a[i],q-2);
      }
	for(i=1,j=1;i<=n;i++,j=-j)
	  p=(p+(L)j*C(n,i)*power(3,(L)(n-i)*n+i))%q;
	for(i=1,j=1;i<=n;i++,j=-j)
	  p=(p+(L)j*C(n,i)*3*power(power(3,n-i)-1,n)+(L)j*C(n,i)*(power(3,i)-3)%q*power(3,(L)(n-i)*n))%q;
	p=(p+q)%q;
	printf("%d\n",p);
	return 0;
}