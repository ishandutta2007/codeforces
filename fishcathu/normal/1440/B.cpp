#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=1E6+10;
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
int a[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),k=read();
		ll ans=0;
		for(int i=1;i<=k*n;++i)a[i]=read();
		for(int i=n*k-n/2,j=1;j<=k;i-=n/2+1,++j)ans+=a[i];
		printf("%lld\n",ans);
	} 
}