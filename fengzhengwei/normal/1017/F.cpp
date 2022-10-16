#include<bits/stdc++.h>
#define int long long
#define ll long long
#define dd double
#define u unsigned
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
char st;
int prim[17322],cnt;
bitset<17322>vis;
bitset<100000001>bit;
void pre(int n)
{
	
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>n)break;
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
}
u ans,a,b,c,d;
u g(u i){return a*i*i*i+b*i*i+c*i+d;}
const int inf=100000000;
char ed;
signed main(){
	pre(17320);
	int n=read();
	a=read(),b=read(),c=read(),d=read();
	for(int i=1;i<=cnt;i++)
	{
		ll x=prim[i];
		u res=0;
		while(x<=n)
		{
			res+=n/x;
			x*=prim[i];
		}
		ans+=res*g(prim[i]);
//		cout<<res<<" "<<g(prim[i])<<"\n";
	}
	bit.reset();
	bit[0]=1;
	for(int i=1;i<=cnt;i++)
		for(u j=(1/prim[i]+1)*prim[i];j<=inf;j+=prim[i])bit[j]=1;
	bit.flip();
	int x=bit._Find_first();
	while(x!=bit.size())
	{
		if(x>17320&&x<=n)ans+=n/x*g(x);
		x=bit._Find_next(x);
	}
	bit.reset();
	bit[0]=1;
	for(int i=1;i<=cnt;i++)
		for(u j=((inf)/prim[i]+1)*prim[i];j<=inf+inf;j+=prim[i])bit[j-inf]=1;
	bit.flip();
	x=bit._Find_first();
	while(x!=bit.size())
	{
		if(x+inf>17320&&x+inf<=n)ans+=n/(x+inf)*g(x+inf);
		x=bit._Find_next(x);
	}
	bit.reset();
	bit[0]=1;
	for(int i=1;i<=cnt;i++)
		for(u j=((inf+inf)/prim[i]+1)*prim[i];j<=inf+inf+inf;j+=prim[i])bit[j-inf-inf]=1;
	bit.flip();
	x=bit._Find_first();
	while(x!=bit.size())
	{
		if(x+inf+inf>17320&&x+inf+inf<=n)ans+=n/(x+inf+inf)*g(x+inf+inf);
		x=bit._Find_next(x);
	}
	cout<<ans<<"\n";
	return 0;
}