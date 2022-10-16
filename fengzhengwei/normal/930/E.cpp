#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int k,n,m,tt;
const int xx=2e5+5;
struct node{int l,r,op;bool operator<(const node&w)const{return r<w.r;};}a[xx],b[xx],e[xx];
bool cmp(node a,node b){return a.l<b.l;}
ll f[xx];
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
int vis[xx],stk[xx],top;
ll ni;
struct bit
{
	ll s1[xx],s2[xx];//s1fs2f*(ni^e[j].r)
	int lb(int x){return x&-x;}
	void ad1(int x,ll y){x++;for(;x<=tt+1;x+=lb(x))s1[x]+=y,s1[x]%=mod;}
	void ad2(int x,ll y){x++;for(;x<=tt+1;x+=lb(x))s2[x]+=y,s2[x]%=mod;}
	ll ask1(int x){x++;ll ans=0;for(;x;x-=lb(x))ans+=s1[x];return ans%mod;} 
	ll ask2(int x){x++;ll ans=0;for(;x;x-=lb(x))ans+=s2[x];return ans%mod;} 
}s[2];
signed main(){
	ni=ksm(2,mod-2);
	k=read(),n=read(),m=read();
	for(int i=1;i<=n;i++)a[i].l=read(),a[i].r=read(),a[i].op=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)b[i].l=read(),b[i].r=read(),b[i].op=1;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		while(top&&a[stk[top]].r>=a[i].r)vis[stk[top]]=1,top--;
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++)if(!vis[i])e[++tt]=a[i];
	memset(vis,0,sizeof(vis));
	top=0;
	for(int i=1;i<=m;i++)
	{
		while(top&&b[stk[top]].r>=b[i].r)vis[stk[top]]=1,top--;
		stk[++top]=i;
	}
	for(int i=1;i<=m;i++)if(!vis[i])e[++tt]=b[i];
	sort(e+1,e+tt+1);
	f[0]=ksm(2,k);//fi2^ki 
	s[0].ad1(0,f[0]);
	s[0].ad2(0,f[0]);
	for(int i=1;i<=tt;i++)
	{
		int l=0,r=i-1,ans=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(e[i].l>e[mid].r)ans=mid,l=mid+1;
			else r=mid-1;
		}
		f[i]+=(s[(!e[i].op)].ask1(ans)+s[e[i].op].ask1(ans))*(mod-1)%mod*ksm(ni,e[i].r-e[i].l+1)%mod;
		f[i]+=(s[e[i].op].ask2(tt)-s[e[i].op].ask2(ans)+mod)*(mod-1)%mod*ksm(ni,e[i].r)%mod;
//		for(int j=0;j<i;j++)
//		{
//			if(e[i].op!=e[j].op&&e[i].l<=e[j].r)continue;
//			if(e[i].l>e[j].r)//r-l+1 
//			{
//				f[i]+=(mod-1)*f[j]%mod*ksm(ni,e[i].r-e[i].l+1)%mod;
//				continue;
//			}// 
//			f[i]+=(mod-1)*f[j]%mod*ksm(ni,e[i].r-e[j].r)%mod;
//		}
		f[i]%=mod;
		s[e[i].op].ad1(i,f[i]);
		s[e[i].op].ad2(i,f[i]*ksm(2,e[i].r)%mod);
	}
	ll ans=0;
	for(int i=0;i<=tt;i++)ans+=f[i],ans%=mod;
	cout<<ans<<"\n";
	return 0;
}