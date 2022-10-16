#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define ull unsigned ll 
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
const int xx=2e5+5,mod=1e9+7;
int jiec[xx],ni[xx];
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
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=1ll*ni[i+1]*(i+1)%mod;
}
ll C(int n,int m){return n<m||n<0||m<0?0:1ll*jiec[n]*ni[m]%mod*ni[n-m]%mod;}
int n,m,k,s,lin[xx];
int f[2005][22];
struct nod
{
	int x,y;
	bool operator<(const nod&w)const{return x==w.x?y<w.y:x<w.x;}
}e[xx<<1];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:a;}
void ad(int &a,ll b){a=(a+b)%mod;}
int red(int x){return x>=mod?x-mod:x;}
int main(){
	pre();
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),m=read(),k=read(),s=read();
	lin[0]=s;
	for(int i=1;i<=30;i++)lin[i]=(lin[i-1]+1)/2;
	for(int i=1;i<=k;i++)
		e[i].x=read(),e[i].y=read();
	sort(e+1,e+k+1);
	int op=0;
	if(!(e[k].x==n&&e[k].y==m))op=1,e[++k].x=n,e[k].y=m;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=21;j++)
		{
			for(int k=1;k<i;k++)
				if(e[k].x<=e[i].x&&e[k].y<=e[i].y)
					ad(f[i][j],1ll*f[k][j]*C(e[i].x-e[k].x+e[i].y-e[k].y,e[i].x-e[k].x));
			f[i][j]=red(mod-f[i][j]+C(e[i].x-1+e[i].y-1,e[i].x-1));
		}
		for(int j=21;j>=1;j--)
			f[i][j]=red(mod+f[i][j]-f[i][j-1]);
//		for(int j=21;j>=1;j--)if(f[i][j])cerr<<i<<" "<<j<<" "<<f[i][j]<<"@@\n";
	}
	int ans=0;
	for(int j=1;j<=21;j++)
		ad(ans,1ll*lin[j-op]*f[k][j]);
	int tt=C(n-1+m-1,m-1);
	for(int j=1;j<=21;j++)ad(tt,mod-f[k][j]);
//	,cerr<<f[n][j]<<"$\n";
//	cerr<<ans<<" "<<C(n-1+m-1,m-1)<<"$$\n";
	cout<<1ll*(ans+tt)*ksm(C(n-1+m-1,m-1),mod-2)%mod<<"\n";
	pc('1',1);
	return 0;
}