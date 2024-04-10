#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
//const int yy=2e7+5;/
const int yy=5000000+5;
int t[yy],num[yy];
ll f[yy];
signed main(){
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read(),t[a[i]]++;
	for(int i=1;i<=5000000;i++)
		for(int j=i;j<=5000000;j+=i)
			num[i]+=t[j];
	f[1]=n;
	for(int i=1;i<=5000000;i++)
	{
		if(!num[i])continue;
		for(int j=i;j<=5000000;j+=i)
		{
			f[j]=max(f[j],f[i]+1ll*(num[j])*(j-i));
//			if(num[j])cout<<j<<" "<<f[j]<<" "<<num[j]<<"\n";
		}
	}
	ll ans=0;
	for(int i=1;i<=5000000;i++)ans=max(ans,f[i]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}