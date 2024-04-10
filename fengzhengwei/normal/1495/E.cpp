#include<bits/stdc++.h>
#define ll long long
#define dd double
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=5e6+5,mod=1e9+7;
int n,m,a[xx],b[xx],t[xx],k[xx],w[xx],p[xx];
ll seed,base;
ll rnd(){ll ret=seed;seed=(seed*base+233)%mod;return ret;}
ll ans[xx];
int stk[xx],top;
ll res[xx],c[xx];
void _solve()
{
	int now=0,nid=t[1];
	for(int i=1;i<=n;i++)c[i]=a[i];
	while(now<=1000000)
	{
		++now;
		int to=(now-1)%n+1;
		if(nid!=t[to])continue;
		if(!c[to])continue;
		c[to]--,res[to]++;
		nid^=1;
	}
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
	puts("");
}
signed main(){
	random_device R;
//	cerr<<R()<<"!!\n";
//	freopen("seed.in","r",stdin);
	mt19937 G(R());
//	n=G()%10+1;
	n=read();
	
	m=read();
	for(int i=1;i<=m;i++)
		p[i]=read(),k[i]=read(),b[i]=read(),w[i]=read();
	p[0]=0;
	for(int i=1;i<=m;i++)
	{
		seed=b[i],base=w[i];//+1 
		for(int j=p[i-1]+1;j<=p[i];j++)t[j]=(rnd()%2),a[j]=(rnd()%k[i])+1;
//		,cerr<<j<<" "<<a[j]<<"$%^&\n";
	}
//	for(int i=1;i<=n;i++)a[i]=G()%10+1,t[i]=G()&1;
//	for(int i=1;i<=n;i++)b[i]=a[i];
//	for(int i=1;i<=n;i++)a[i]=read(),t[i]=read();
	ll sum[3]={0,0,0};
	for(int i=1;i<=n;i++)
		sum[t[i]]+=a[i];
//	_solve();
	if(sum[t[1]]==sum[t[1]^1]+1||sum[t[1]]==sum[t[1]^1])// 
	{
//		for(int i=1;i<=n;i++)assert(ans[i]==res[i]);
		ll res=1;
		for(ll i=1;i<=n;i++)res*=((((ans[i]=a[i])^(i*i))+1)%mod),res%=mod;
		cout<<res<<"\n";
		return 0;
	}
	int id=0;
	if(sum[t[1]]<sum[t[1]^1])id=t[1];
	else id=t[1]^1,a[1]--,ans[1]++;
//	cout<<id<<"!@#$\n";
	//id 
	for(int i=1;i<=n;i++)if(t[i]==id)ans[i]=a[i];
	int ti=1;//ti 
	// 
	for(int i=n;i>=1;i--)// 
	{
		if(t[i]!=id)
		{
			// 
//			if(i>=ti)
			stk[++top]=i;
//			else cerr<<"@@@\n";
			continue;
		}
		else 
		{
			while(a[i]!=0)
			{
				if(!top)
				{
					while(t[ti]==id)ti++;
					assert(ti<i);
					stk[++top]=ti;
					++ti;
				}
				ll re=min(a[stk[top]],a[i]);
				ans[stk[top]]+=re;
				a[stk[top]]-=re,a[i]-=re;
				if(!a[stk[top]])top--;
			}
		}
	}
//	for(int i=1;i<=n;i++)if(ans[i]!=res[i])
//	{
//		for(int j=1;j<=n;j++)cout<<b[j]<<" "<<t[j]<<"\n";
//		puts("");
//		break;
//	}
//	for(int i=1;i<=n;i++)assert(ans[i]==res[i]);
	ll res=1;
//	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
//	puts("");
//	for(ll i=1;i<=n;i++)cerr<<i<<" "<<ans[i]<<" "<<t[i]<<" "<<a[i]<<"!!\n";
//	cerr<<id<<"!D\n";
	for(ll i=1;i<=n;i++)res*=((((ans[i])^(i*i))+1)%mod),res%=mod;
	cout<<res<<"\n";
	pc('1',1);
	return 0;
}