#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E6+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
ll a[N],b[N];
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	ll k=a[2]-a[1];
	for(int i=3;i<=n;++i)k=__gcd(k,a[i]-a[i-1]);
	for(int i=1;i<=m;++i)
	{
		ll t;
		scanf("%lld",&t);
		printf("%lld ",n==1?a[1]+t:__gcd(a[1]+t,k));
	}
}