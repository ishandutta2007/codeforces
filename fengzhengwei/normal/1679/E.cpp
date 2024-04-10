#include<bits/stdc++.h>
#define ll long long
#define LL __int128
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


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
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
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
//ppcount2^17*17*17+n^2 17  
//ppct 
int ct(int x){return __builtin_popcount(x);}
int sum[xx],pw[xx],ans[xx];
int main(){
	n=read();
	scanf("%s",s+1);
	for(int I=1;I<=17;I++)
	//ASDAS1 
	{
		memset(sum,0,sizeof(sum));
		pw[0]=1;
		for(int i=1;i<=n;i++)pw[i]=1ll*pw[i-1]*I%mod;
		int tt=0;
		for(int i=1;i<=n;i++)
			tt+=(s[i]=='?');
//		for(int i=1;i<=n;i++)cout<<i<<" "<<pw[i]<<"$\n";
		for(int i=1;i<=n;i++)
		{
			int l=i,r=i,zz=0,num=0,ce=tt;
			while(l>=1&&r<=n)
			{
				if(s[l]!='?'&&s[r]!='?'&&s[l]!=s[r])break;
				if(s[l]!='?'&&s[r]=='?')zz|=1<<(s[l]-'a');
				if(s[r]!='?'&&s[l]=='?')zz|=1<<(s[r]-'a');
				if(s[l]=='?'&&s[r]=='?')num++;
				ce-=(s[l]=='?');
				if(l!=r)ce-=(s[r]=='?');
				// 
				ad(sum[zz],1ll*pw[num]*pw[ce]%mod);
//				cout<<zz<<' '<<num<<"%^%\n";
				l--,r++;
			}
		}
		for(int i=1;i<n;i++)
		{
			int l=i,r=i+1,zz=0,num=0,ce=tt;
			while(l>=1&&r<=n)
			{
				if(s[l]!='?'&&s[r]!='?'&&s[l]!=s[r])break;
				if(s[l]!='?'&&s[r]=='?')zz|=1<<(s[l]-'a');
				if(s[r]!='?'&&s[l]=='?')zz|=1<<(s[r]-'a');
				if(s[l]=='?'&&s[r]=='?')num++;
				ce-=(s[l]=='?');
				if(l!=r)ce-=(s[r]=='?');
				// 
				ad(sum[zz],1ll*pw[num]*pw[ce]%mod);
//				cout<<zz<<' '<<num<<"%^%\n";
				l--,r++;
			}
		}
		
		for(int j=0;j<17;j++)
			for(int i=1;i<(1<<17);i++)
				if(i>>j&1)ad(sum[i],sum[i-(1<<j)]);
		
		for(int i=0;i<(1<<17);i++)
		if(ct(i)==I)ans[i]=sum[i];
	}
	int q=read();
	while(q--)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		int zz=0;
		for(int i=1;i<=m;i++)
			zz|=(1<<(s[i]-'a'));
		cout<<ans[zz]<<"\n";
	}
	pc('1',1);
	return 0;
}