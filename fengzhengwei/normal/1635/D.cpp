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
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=5e5+5,mod=1e9+7;
int a[xx],vis[xx];
map<int,int>mp;
ll f[xx],sum[xx];
int get(int x)
{
	int num=0;
	while(x)x/=2,num++;
	return num;
}
int main(){
	int n=read(),p=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]){vis[i]=1;continue;}
		int x=a[i];
		while(x)
		{
			if(x&1)x/=2;
			else if(x%4==0)x/=4;
			else break;
			if(mp.find(x)!=mp.end())
			{
				vis[i]=1;
				break;
			}
		}
		if(!vis[i])mp[a[i]]=1;
	}
	f[0]=1;
	for(int i=1;i<=p;i++)
	{
		if(i!=1)f[i]+=f[i-2];
		f[i]+=f[i-1];
		f[i]%=mod;
	}
	sum[0]=1;
	for(int i=1;i<=p;i++)sum[i]=sum[i-1]+f[i],sum[i]%=mod;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(p-get(a[i])>=0)
			ans+=sum[p-get(a[i])];
		}
	}
	cout<<ans%mod<<"\n";
	pc('1',1);
	return 0;
}