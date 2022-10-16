#include<bits/stdc++.h>
#define ll long long
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
const int xx=1e5+5;
signed main(){
	int T=read();
	while(T--)
	{
		unsigned ll l=read(),r=read();
		for(int i=0;i<62;i++)
		{
			if(l>>i&1)continue;
			if(l+(1ull<<i)<=r)l+=(1ull<<i);
		}
		cout<<l<<"\n";
	}
	return 0;
}