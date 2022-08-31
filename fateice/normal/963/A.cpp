#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000009;
int n,a,b,m,p;
char s[100010];
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
inline int calc(int a,int b,int n)
{
    if(n==0)
      return a;
    if(n&1)
      return (L)calc(a,b,n/2)*(power(b,n/2+1)+1)%q;
    else
      return (a+(L)b*calc(a,b,n-1))%q;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d%d%d%d%s",&n,&a,&b,&m,&s);
	for(i=0;i<m && i<=n;i++)
	  p=(p+(s[i]=='+'?1:-1)*calc((L)power(a,n-i)*power(b,i)%q,power((L)b*power(a,q-2)%q,m),(n-i)/m))%q;
	p=(p+q)%q;
	printf("%d\n",p);
	return 0;
}