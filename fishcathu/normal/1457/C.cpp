#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
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
char a[N];ll ans[N];
int main()
{
	for(int xxx=read();xxx--;)
	{
		int n=read(),m=read(),k=read();
		ll ss=1ll<<60;
		scanf("%s",a+1);
		int x=read(),y=read();
		for(int i=n;i>=m;--i)
		{
			ans[i]=(a[i]==48?x:0);
			if(i+k<=n)ans[i]+=ans[i+k];
			
		}
		for(int i=m;i<=n;++i)
		{
			ans[i]+=(i-m)*1ll*y;
			if(ans[i]<ss)ss=ans[i];
		}
		printf("%lld\n",ss);
	}
}