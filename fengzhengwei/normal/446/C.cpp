#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=3e5+5;
const int mod=1e9+9;
ll a[xx];
ll sum[xx];
ll pre[xx];
ll f[xx];
vector<pair<int,int> >v;
ll b[xx];
void pres()
{
	v.clear();
	for(int i=1;i<=n;i++)b[i]=(b[i-1]+b[i-2]+b[i])%mod;
	for(int i=1;i<=n;i++)a[i]=(a[i]+b[i])%mod,b[i]=0;
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+a[i])%mod;
}
signed main(){
	n=read();
	m=read();
	f[1]=f[2]=1;
	for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)pre[i]=(pre[i-1]+f[i])%mod;
	for(int i=1;i<=n;i++)a[i]=read();
	pres();
	int s=1001;
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)
		{
			int l,r;
			l=read();
			r=read();
			b[l]++;
			b[r+1]-=f[r-l+2];
			b[r+1]=(b[r+1]+mod)%mod;
			b[r+2]-=f[r-l+1];
			b[r+2]=(b[r+2]+mod)%mod;
			v.push_back(make_pair(l,r));
			if(v.size()==s)pres();
		}
		else 
		{
			int l,r;
			l=read();
			r=read();
			int ans=(sum[r]-sum[l-1]+mod)%mod;
			for(int j=0;j<v.size();j++)
			{
				if(v[j].second<l||r<v[j].first)continue;
//				cout<<v[j].first<<" "<<v[j].second<<"\n";
				if(l<=v[j].first&&v[j].second<=r)ans=(ans+pre[v[j].second-v[j].first+1]+mod)%mod;
				else if(v[j].first<=l&&r<=v[j].second)ans=(ans+pre[r-v[j].first+1]-pre[l-v[j].first]+mod)%mod;
				else if(v[j].first<l)ans=(ans+pre[v[j].second-v[j].first+1]-pre[l-v[j].first]+mod)%mod;
				else if(v[j].second>r)ans=(ans+pre[r-v[j].first+1]+mod)%mod;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}