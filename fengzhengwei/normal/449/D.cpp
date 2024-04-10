#include<bits/stdc++.h>
#define ll long long 
//#define int long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)assert(0);
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=2e6+5,mod=1e9+7;
int n,a[xx];
int pw[xx];
signed main(){
	n=read();
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=(pw[i-1]<<1)%mod;
	for(int i=1;i<=n;i++)a[read()]++;
	for(int j=0;j<20;j++)
		for(int i=0;i<(1<<20);i++)
			if(i>>j&1)a[i-(1<<j)]+=a[i];
	ll ans=0;
	for(int i=0;i<(1<<20);i++)
		ans+=1ll*(__builtin_popcount(i)&1?mod-1:1)*pw[a[i]],ans%=mod;
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}