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
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	ll jiec[xx],ni[xx];
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
	ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
	void pre()
	{
		jiec[0]=1;
		for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
		ni[xx-1]=ksm(jiec[xx-1],mod-2);
		for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	}
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
}
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
int prim[xx],mn[xx];
void pre(int n)
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}
int n,m,k,q,a[xx];
char s[xx];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
struct nod{int next,to,a,b;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int a,int b){cnt++;e[cnt]={h[x],y,a,b},h[x]=cnt;}
// 
//max 
//map 
// 
map<int,ll>mp[xx],lin;
ll val[xx];
//AB 
//
ll num[xx]; 
void merge(map<int,ll>&A,map<int,ll>&B,ll numa,ll &numb)
{
	if(A.size()>B.size())
	{
		numb=numa;
		swap(A,B);
//		swap(numa,numb);
	}
	for(auto it:A)
	{
		if(B[it.first]<it.second)
		{
			numb*=ksm(it.first,it.second-B[it.first]),numb%=mod;
			B[it.first]=it.second;
		}
	}
}
ll up[xx];
void dfs(int x,int y)
{
//	cout<<x<<" QQQ "<<y<<"\n";
	mp[x].clear();
	//sum 
	//lcm 
	val[x]=0;num[x]=1;
	//val
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		lin.clear();
		swap(lin,mp[e[i].to]);
		ll &tsum=val[e[i].to],&tnum=num[e[i].to];
		// 
		int X=e[i].b;
		while(X!=1)
		{
			int t=mn[X],N=0;
			while(X%t==0)N++,X/=t;
			if(lin[t]<N)
			{
				tnum*=ksm(t,N-lin[t]);
				tsum*=ksm(t,N-lin[t]);
				tsum%=mod;
				tnum%=mod,lin[t]=N;
			}
		}
		X=e[i].b;
		ll _num=tnum;
		while(X!=1)
		{
			int t=mn[X],N=0;
			while(X%t==0)N++,X/=t;
			// 
			lin[t]-=N;
			_num*=ksm(ksm(t,mod-2),N);
			_num%=mod;
		}
		X=e[i].a;
		while(X!=1)
		{
			int t=mn[X],N=0;
			while(X%t==0)N++,X/=t;
			lin[t]+=N;
			_num*=ksm(t,N);
			_num%=mod;
		}
		up[e[i].to]=_num;
		//lcm 
		merge(lin,mp[x],_num,num[x]);//num[x]lcm. 
	}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		val[x]+=val[e[i].to]*num[x]%mod*ksm(up[e[i].to],mod-2)%mod,val[x]%=mod;
	}
//	for(int i=h[x];i;i=e[i].next)
//	{
//		if(e[i].to==y)continue;
//		dfs(e[i].to,x);
//		lin.clear();
//		swap(lin,mp[e[i].to]);
//		int X=e[i].b;
//		ll tsum=val[e[i].to],tnum=num[e[i].to];
////		val[x]+=tsum,val[x]%=mod;
////		val[x]-=tnum;
//		// 
//		while(X!=1)
//		{
//			int t=mn[X],N=0;
//			while(X%t==0)N++,X/=t;
//			if(lin[t]<N)
//			{
//				tnum*=ksm(t,N-lin[t]);
//				tsum*=ksm(t,N-lin[t]);
//				tsum%=mod;
//				tnum%=mod,lin[t]=N;
//			}
//		}
//		cout<<x<<" "<<e[i].to<<" qwewqe "<<tsum<<"!!\n";
//		val[x]+=tsum,val[x]%=mod;
////		val[x]+=tnum,val[x]+=mod,val[x]%=mod;// 
//		X=e[i].b;
//		while(X!=1)
//		{
//			int t=mn[X],N=0;
//			while(X%t==0)N++,X/=t;
//			// 
//			lin[t]-=N;
//			tnum*=ksm(ksm(t,mod-2),N);
//			tnum%=mod;
//		}
//		X=e[i].a;
//		while(X!=1)
//		{
//			int t=mn[X],N=0;
//			while(X%t==0)N++,X/=t;
//			// 
//			lin[t]+=N;
//			tnum*=ksm(t,N);
//			tnum%=mod;
//		}
//		merge(lin,mp[x],tnum,num[x]);
//	}
	val[x]+=num[x],val[x]%=mod;
//	cout<<x<<" ss "<<num[x]<<"!!\n";
}
int main(){
	pre(xx-1);
	int T=read();
	while(T--)
	{
		n=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read(),c=read(),d=read();
			int D=gcd(c,d);
			c/=D,d/=D;
//			cerr<<c<<" "<<d<<"ASDAFDG\n";
			add(a,b,c,d),add(b,a,d,c);
		}
		dfs(1,0);
		cout<<val[1]<<"\n";
	}
	pc('1',1);
	return 0;
}