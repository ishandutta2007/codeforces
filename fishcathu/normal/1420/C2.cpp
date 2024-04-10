#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=3E5+10;
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
int f(int u,int v)
{
	int s=0;
	if(a[u]>a[u-1])s+=a[u]-a[u-1];
	if(a[u+1]>a[u])s+=a[u+1]-a[u];
	if(v!=u+1&&a[v]>a[v-1])s+=a[v]-a[v-1];
	if(a[v+1]>a[v])s+=a[v+1]-a[v];
	return s;
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),m=read();
		ll ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i)if(a[i]>a[i-1])ans+=a[i]-a[i-1];
		printf("%lld\n",ans);
		a[n+1]=0;
		while(m--)
		{
			int u=read(),v=read(),l=f(u,v);
			swap(a[u],a[v]);
			ans+=f(u,v)-l;
			printf("%lld\n",ans);
		}
	}
}