#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc/
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=1e5+5;
int a[xx];
const int yy=2e7+5;
//const int yy=5000000+5;
int t[yy],num[yy];
ll f[yy];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
//	cout<<sizeof(f)/1024/1024<<"\n";
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int o=read();
		for(int j=1;j<=800;j++)
		{
			if(o%j==0)num[j]++;
		}
		if(o>800)t[o]++;
	}
	for(int i=20000000;i>=801;i--)
	{
		if(i+i<=20000000)
		num[i]=num[i+i];
		for(int j=i;j<=20000000;j+=i+i)
			num[i]+=t[j];
	}
//	return 0;
	f[1]=n;
	ll ans=0;
	for(int i=1;i<=20000000;i++)
	{
		if(!num[i])continue;
		ans=max(ans,f[i]);
		for(int j=i;j<=20000000;j+=i)
		{
			if(num[j])
			f[j]=max(f[j],f[i]+1ll*(num[j])*(j-i));
//			if(t[j])cout<<j<<" "<<f[j]<<" "<<t[j]<<"\n";
		}
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}