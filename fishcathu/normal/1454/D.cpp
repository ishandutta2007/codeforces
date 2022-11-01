#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1E6+5;
int read()
{
	int a=0;char b=1,c;
	do if((c=getchar())==45)b=-1;while(!(c&16));
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
	return a*b;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	char a[10],s=0;
	do a[s++]=x%10|48;while(x/=10);
	do putchar(a[--s]);while(s);
}
int main()
{
	for(int x=read();x--;)
	{
		ll n;
		scanf("%lld",&n);
		ll m=n;
		int mx=0,k;
		for(int i=2;i*1ll*i<=n;++i)if(!(n%i))
		{
			int s=0;
			do n/=i,++s;while(!(n%i));
			if(s>mx)mx=s,k=i;
		}
		if(mx)
		{
			printf("%d\n",mx);
			while(--mx)printf("%d ",k),m/=k;
			printf("%lld\n",m);
		}
		else printf("1\n%lld\n",m);
	}
	return 0;
}