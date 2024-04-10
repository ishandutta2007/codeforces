#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
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
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}

void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void ad(int &a,ll b){(a=(a+b)%mod);}
int red(int x){return x>=mod?x-=mod:x;}

random_device R;
mt19937 G(218);
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}

}

int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 

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

#define Pr pair<int,int>
#define fi first
#define se second
int n,m,k,q,a[xx],b[xx];
map<int,int>mp;
int re=0,ans[xx];
int ghs(int x){return !mp[x]?(mp[x]=(++re)):mp[x];}
struct nod
{
	int op,x,y,k;
}e[xx];
mt19937 G(218);
struct szsz
{
	int lb(int x){return x&-x;}
	ll sum[(int)3e5+5];
	void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
	ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
}s[52];
bitset<xx>t[52];
int main(){
	#define ct t
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)
	{ 
		e[i].op=read(),e[i].x=read(),e[i].y=read();
		if(e[i].op==2)e[i].k=read();
	}
	for(int i=1;i<=n;i++)a[i]=ghs(a[i]);
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=m;i++)
		if(e[i].op==1)e[i].y=ghs(e[i].y),e[i].k=b[e[i].x],b[e[i].x]=e[i].y;
	int lim=51;
	for(int j=1;j<=lim;j++)
		for(int i=1;i<=mp.size();i++)t[j][i]=G()&1;
	for(int j=1;j<=lim;j++)
		for(int i=1;i<=n;i++)
		{
			if(t[j][a[i]])s[j].add(i,1);
		}
//	exit(0);
	for(int i=1;i<=m;i++)
	{
		if(e[i].op==1)
		{
			int I=e[i].x;
			for(int j=1;j<=lim;j++)
				if(t[j][a[I]])s[j].add(I,-1);
			
			a[I]=e[i].y;
			for(int j=1;j<=lim;j++)
				if(t[j][a[I]])s[j].add(I,1);
			
		}
		else 
		{
			int cr=1;
			for(int j=1;j<=lim;j++)
				if((s[j].ask(e[i].y)-s[j].ask(e[i].x-1))%e[i].k!=0)cr=0;
//		cerr<<i<<" "<<cr<<"##\n";
			ans[i]=cr;
		}
	}
	for(int i=1;i<=m;i++)
	if(e[i].op==2)
	{
		if(ans[i])puts("YES");
		else puts("NO");
	}
	pc('1',1);
	return 0;
}