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
int a[N];
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read();
 		for(int i=1;i<=n;++i)a[i]=read();
 		ll ans=0,mx=0;
 		a[0]=a[2],a[n+1]=a[n-1];
 		for(int i=2;i<=n;++i)
 		{
 			int t=abs(a[i]-a[i-1]);
			 ans+=t;	
		}
		for(int i=1;i<=n;++i)
		{
			ll l=0,r=0;
			if(i!=1)l+=abs(a[i]-a[i-1]);
			if(i!=n)l+=abs(a[i+1]-a[i]);
			r+=abs(a[i+1]-a[i-1]);
			mx=max(mx,l-r);
		}
		printf("%lld\n",ans-mx);
	}
}