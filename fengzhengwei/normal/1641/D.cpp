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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
//namespace zhs
//{
//	const int xx=5e5+5,mod=998244353;
//	ll jiec[xx],ni[xx];
//	ll ksm(ll a,ll b)
//	{
//		ll ans=1;
//		while(b)
//		{
//			if(b&1)ans*=a,ans%=mod;
//			a*=a,a%=mod,b>>=1;
//		}
//		return ans;
//	}
//	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
//	void pre()
//	{
//		jiec[0]=1;
//		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
//		ni[xx-1]=ksm(jiec[xx-1],mod-2);
//		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//	}
//}
//namespace pr
//{
//	const int xx=5e5+5,mod=998244353;
//	int prim[xx],mn[xx],cnt;
//	void pre(int n)
//	{
//		for(int i=2;i<=n;i++)
//		{
//			if(!mn[i])mn[i]=i,prim[++cnt]=i;
//			for(int j=1;j<=cnt;j++)
//			{
//				if(prim[j]*i>n)break;
//				mn[i*prim[j]]=prim[j];
//				if(i%prim[j]==0)break;
//			}
//		}
//	}
//}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
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
int n,m,k,q,a[xx];
char s[xx];
//bitset<1005>bit;
//cout 
int lsh[xx],tt;
struct nod
{
	int a[5],v;
	bool operator<(const nod&w)const{return v<w.v;}
}e[xx];
vector<int>v[xx];
map<int,int>mp;
bitset<100005>bit[25005];//298MB
int main(){
//	cout<<sizeof(bit)/1024/1024<<"\n";
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			e[i].a[j]=read();
			lsh[++tt]=e[i].a[j];
		}
		e[i].v=read();
	}
	sort(e+1,e+n+1);
	sort(lsh+1,lsh+tt+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			e[i].a[j]=lower_bound(lsh+1,lsh+tt+1,e[i].a[j])-lsh;
			// 
			v[e[i].a[j]].push_back(i);
		}
	}
	//>20bitset 
	//5e5/20
	int tt1=0;
	for(int i=1;i<=tt;i++)
		if(v[i].size()>20)mp[i]=++tt1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			if(mp.find(e[i].a[j])!=mp.end())bit[mp[e[i].a[j]]][i]=1;
	}
	for(int i=1;i<=tt1;i++)bit[i].flip();
	//100005
	bitset<100005>lin;
	int ans=2147483647;
	for(int i=1;i<=n;i++)
	{
		lin.set();
		for(int j=0;j<m;j++)
		{
			if(mp.find(e[i].a[j])!=mp.end())
			lin&=bit[mp[e[i].a[j]]];
			else 
				for(auto it:v[e[i].a[j]])lin[it]=0;
		}
		lin[0]=0;
		int a=lin._Find_first();
//		cout<<i<<" "<<a<<"!!\n";
		if(a<=n)ans=min(ans,e[i].v+e[a].v);
	}
	if(ans==2147483647)puts("-1");
	else cout<<ans<<"\n";
	pc('1',1);
	return 0;
}