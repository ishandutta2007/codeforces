#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
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
const int xx=2e5+5;
int adt[xx<<2],sum[xx<<2];
void build(int k,int l,int r)
{
	sum[k]=adt[k]=(1<<30)-1;
	if(l==r)return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void cv(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return adt[k]&=z,void();
	int mid=l+r>>1;
	if(x<=mid)cv(k<<1,l,mid,x,y,z);
	if(mid<y)cv(k<<1|1,mid+1,r,x,y,z);
}
int a[xx];
void dd(int k,int l,int r)
{
	sum[k]&=adt[k];
	if(l==r)return a[l]=sum[k],void();
	adt[k<<1]&=adt[k];
	adt[k<<1|1]&=adt[k];
	int mid=l+r>>1;
	dd(k<<1,l,mid);
	dd(k<<1|1,mid+1,r);
}
const int mod=1e9+7;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
ll jiec[xx],ni[xx];
ll C(ll n,ll m)
{
	return jiec[n]*ni[m]%mod*ni[n-m]%mod;
}
signed main(){
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		build(1,1,n);
		while(m--)
		{
			int l=read(),r=read(),v=read();
			cv(1,1,n,l,r,v);
		}
		dd(1,1,n);
		ll ans=0;
//			for(int i=1;i<=n;i++)cout<<a[i]<<" \n";
//			puts("");/
		for(int j=0;j<=30;j++)
		{
			int num=0;
			for(int i=1;i<=n;i++)num+=(a[i]>>j&1);
			for(int i=1;i<=num;i+=2)
			{
				ans+=1ll*C(num,i)*ksm(2,n-num)%mod*(1<<j)%mod;
				ans%=mod;
			}
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}