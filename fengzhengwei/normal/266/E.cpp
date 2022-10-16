#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=1e5+5;
ll sum[xx<<2][6],cvt[xx<<2],s[xx<<2][6],a[xx];
const int mod=1e9+7;
ll ksm(ll a,ll b)
{
	a+=mod,a%=mod;
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
void update(int k)
{
	for(int i=0;i<=5;i++)sum[k][i]=(sum[k<<1][i]+sum[k<<1|1][i])%mod;
	for(int i=0;i<=5;i++)s[k][i]=(s[k<<1][i]+s[k<<1|1][i])%mod;
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<=5;i++)s[k][i]=ksm(l,i);
		for(int i=0;i<=5;i++)sum[k][i]=a[l]*s[k][i]%mod;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k);
}
void cv(int k,int x)
{
	cvt[k]=x;
	for(int i=0;i<=5;i++)sum[k][i]=s[k][i]*x%mod;
}
void pd(int k)
{
	if(cvt[k]==-1)return;
	cv(k<<1,cvt[k]);
	cv(k<<1|1,cvt[k]);
	cvt[k]=-1;
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return cv(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	update(k);
}
ll ask(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return sum[k][z];
	pd(k);
	int mid=l+r>>1;
	ll ans=0;
	if(x<=mid)ans+=ask(k<<1,l,mid,x,y,z);
	if(mid<y)ans+=ask(k<<1|1,mid+1,r,x,y,z);
	return ans%mod;
}
int C[7][7];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	memset(cvt,-1,sizeof(cvt));
	for(int i=0;i<=6;i++)C[i][i]=C[i][0]=1;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
	build(1,1,n);
	while(m--)
	{
		char c;
		while((c=getchar())!='='&&c!='?');
		int l=read(),r=read(),v=read();
		if(c=='=')cg(1,1,n,l,r,v);
		else 
		{
			ll ans=0;
			for(int k=0;k<=v;k++)ans+=C[v][k]*ask(1,1,n,l,r,k)%mod*ksm(-(l-1),v-k)%mod;
			cout<<ans%mod<<"\n";
		}
	}
	return 0;
}