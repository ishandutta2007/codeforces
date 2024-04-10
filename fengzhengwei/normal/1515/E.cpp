#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define u unsigned
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,mod;
const int xx=405;
ll f[xx][xx];
void add(ll &x,ll y){x+=y,x%=mod;}
int main(){
	n=read(),mod=read();
	f[1][1]=1;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!f[i][j])continue;
			add(f[i+1][j],f[i][j]*j*2);
			add(f[i+2][j+1],f[i][j]*(j+1));
			if(i==n)add(ans,f[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}