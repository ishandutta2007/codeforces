#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,a,b;
int main()
{
	scanf("%d",&n);	scanf("%d",&a);scanf("%d",&b);
	int x=0,y=0;
	for (int i=0;i<=n/a;i++)
	  if ((n-a*i)%b==0) {
	  	  x=i,y=(n-a*i)/b;
	  	  break;
	  }
	if (x!=0||y!=0) printf("YES\n"),printf("%d %d",x,y);
	    else printf("NO\n");
}