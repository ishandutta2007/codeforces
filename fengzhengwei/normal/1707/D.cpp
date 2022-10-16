#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define dd double
#define ull unsigned ll
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
#define uint unsigned int
struct Fast_mod
{
	uint M,a,b;
	inline Fast_mod(const uint m=2):M(m),a((1ull<<32)/m),b(((1ull<<32)%m<<32)/m){}
	inline ull red(ull x)const {return x-=(((((x&~0u)*a)+(x>>32)*b)>>32)+(x>>32)*a)*M,x>=M?x-M:x;}
}Fs;
const int xx=2005;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx],mod,n;
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
void ad(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int red(int x){return x>=mod?x-mod:x;}
int f[xx][xx],g[xx][xx];
int jiec[xx],ni[xx];
int C(int n,int m){return Fs.red(Fs.red(1ll*jiec[n]*ni[m])*ni[n-m]);}
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
int pr[xx][xx],sf[xx][xx];
void dfs(int x,int y)
{
	vector<int>To;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		To.push_back(e[i].to);
	}
	//1 
	int sz=To.size();
	
	for(int i=0;i<sz;i++)
		for(int j=0;j<=n;j++)
			pr[i][j]=Fs.red(1ll*(i?pr[i-1][j]:1)*g[To[i]][j]);
	
	for(int i=sz-1;i>=0;i--)
		for(int j=0;j<=n;j++)
			sf[i][j]=Fs.red(1ll*(i!=sz-1?sf[i+1][j]:1)*g[To[i]][j]);
	
	//0  
	
	for(int t=1;t<=n;t++)
		f[x][t]=sz?pr[sz-1][t]:1;
		///qd 
	if(x!=1)
	{
		for(int j=0;j<sz;j++)
		{
			ll sum=0;
			
			for(int t=1;t<=n;t++)
			{
				if(t!=1)sum=Fs.red(sum+1ll*(j!=0?pr[j-1][t-1]:1)*(j!=sz-1?sf[j+1][t-1]:1));
				f[x][t]=Fs.red(f[x][t]+1ll*sum*f[To[j]][t]);
			}
			
		}
	}
	
	for(int j=1;j<=n;j++)
		g[x][j]=Fs.red((j?g[x][j-1]:0)+f[x][j]);
	
//	for(int j=0;j<=n;j++)
//		cout<<j<<" "<<f[x][j]<<"%%\n";
}
int main(){
	n=read(),mod=read();
	Fs=Fast_mod(mod);
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=1ll*ni[i+1]*(i+1)%mod;
	
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0);
	
	// G 
	 
	for(int i=1;i<n;i++)
	{
		ll ans=0;
//		for(int j=0;j<=i;j++)cerr<<i<<" "<<j<<" "<<f[1][j]<<"$$\n";
//		exit(0);
		for(int j=0;j<=i;j++)
			ans+=Fs.red(1ll*((i-j)&1?mod-1:1)*C(i,j))*f[1][j],ans=Fs.red(ans);
		cout<<ans<<" ";
	}
	
	puts("");
	
	pc('1',1);
	return 0;
}