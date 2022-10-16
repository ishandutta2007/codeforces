#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
const int xx=2e6+5;
int k,a[xx],sum[xx],N[xx];
int lb(int x){return x&-x;}
void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
const int mod=998244353;
int jiec[xx],ni[xx];
int C(int n,int m){return 1ll*jiec[n]*ni[m]%mod*ni[n-m]%mod;}
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
int ct[xx];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=1ll*ni[i+1]*(i+1)%mod;
	k=read();
	for(int i=1;i<=k;i++)a[i]=read();
	sort(a+1,a+k+1);
	// nsqrt  On  k>sqrt T <sqrt k<sqrt T On() ? 
	// nsqrt log  nsqrt 
	// n + max a 
	 
	ll ans=0;
	// -k -k  
	// dlt  
	int lim=*max_element(a+1,a+k+1),re=0; 
	for(int T=0;T<=lim;T++)
	{
		ct[T]=k;int num=0;
		for(int j=1;j<=k;j++)
			if(a[j]-T<0)
				num+=(abs(a[j]-T)+(k-1))/k,--ct[T];
		N[T]=num;
		if(num>T)lim=T;
		if(num>T)break;
		int cr=1;
		for(int i=1;i<=k;i++)
			if(a[i]-T<=0&&abs(a[i]-T)%k==0)
			{
				if(ask(T+1)>=T+1)cr=0;
				else add(T+1,1);
			}
		if(!cr)lim=T;
		if(!cr)break;
	}
	for(int T=0;T<=lim;T++)
	{
		int rem=T-N[T];
		ll v=C(rem+k-1,k-1),iv=(ct[T]<=rem?C(rem-ct[T] +k-1,k-1):0);
//		ans%=mod,ans+=mod,ans%=mod;
//		cerr<<lim<<" "<<v<<" "<<iv<<" "<<ans<<" "<<N[T]<<" "<<ct[T]<<"#$#\n";
		if(v-iv!=0)ans+=v-iv;
		else break;
	}
	cerr<<lim<<"##\n";
	ans%=mod,ans+=mod,ans%=mod;
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}