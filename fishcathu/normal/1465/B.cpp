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
ll b[25],lca[25],sum[25];
int g(ll n,int k)
{
	return n/b[k-1]%10;
}
ll dfs(ll n,int k)
{
	if(k==1)return n;
	for(ll i=g(n,k-1);i<=9;++i)
	{
		if(i)lca[k-1]=lca[k]*i/__gcd(lca[k],i);
		else lca[k-1]=lca[k];
		sum[k-1]=sum[k]+i*b[k-2];
		ll l=((n-1)/lca[k-1]+1)*lca[k-1];
		if(l<sum[k-1]+b[k-2])
		{
			ll t=dfs(n,k-1);
			if(t)return t;
		}
		n-=n%b[k-2];
		n+=b[k-2];
	}
	return 0;
}
int main()
{
	b[0]=1;
	for(int i=1;i<25;++i)b[i]=b[i-1]*10;
	for(int x=read();x--;)
	{
		ll n;
		scanf("%lld",&n);
		int s=0;
		for(ll m=n;m;m/=10)++s;
		lca[s+1]=1;
		sum[s+1]=0;
		printf("%lld\n",dfs(n,s+1));
	}
}