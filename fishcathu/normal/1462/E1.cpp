#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+1;
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
int a[N];
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		ll ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+1+n);
		for(int i=1,l=1;i<=n;++i)
		{
			while(a[i]-a[l]>2)++l;
			if(i-l>=2)ans=ans+(i-l)*1ll*(i-l-1)/2;
		}
		printf("%lld\n",ans);
	}
}