#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,x,sum;
int main()
{
	n=read();x=read();
	if(n==1)	{puts("YES");printf("%d",x);return 0;}
	if(n==2)	{if(x==0)	puts("NO");else	{puts("YES");printf("0 %d",x);}return 0;}
	puts("YES");
	For(i,0,n-4)	printf("%d ",i),sum^=i;
	int t1=(1<<18),t2=(1<<19);
	cout<<t1<<' '<<t2<<' '<<(t1^t2^sum^x)<<endl;
}