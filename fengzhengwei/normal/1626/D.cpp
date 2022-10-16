#include<bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
const int xx=5e5+5,yy=2e5+5,mod=998244353;
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
//ll jiec[xx];
//ll ni[xx];
//ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
//void pr()
//{
//	jiec[0]=1;
//	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
//	ni[xx-1]=ksm(jiec[xx-1],mod-2);
//	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//}
int T,n,m,k,x,y,z;
//struct node{int next,to,v;}e[xx];
//int cnt,h[xx];
//void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
int a[xx];
char s[xx];
int lg[xx],ce[xx];
int t[xx],pre[xx],suf[xx];
int g(int x){return (1<<ce[x])-x;}
int get(int i,int y) 
{
	if(i+1>=y)return 1e9;
	return g(pre[i])+g(suf[y])+g(pre[y-1]-pre[i]);
}
signed main(){
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	for(int i=1;i<xx;i++)ce[i]=(i==(i&-i))?lg[i]:lg[i]+1;
	ce[0]=0;
	T=read();
	while(T--)
	{
//		memset(a,0,sizeof(a));
//		memset(t,0,sizeof(t));
//		memset(pre,0,sizeof(pre));
//		memset(suf,0,sizeof(suf));
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=0;i<=n+10;i++)t[i]=pre[i]=suf[i]=0;
		for(int i=1;i<=n;i++)t[a[i]]++;
		for(int i=1;i<=n+10;i++)pre[i]=pre[i-1]+t[i];
		for(int i=n+9;i>=1;i--)suf[i]=suf[i+1]+t[i];
		int ans=1e9;
		int lim=lg[n];
//		cout<<g(0)<<"!!!\n";
		for(int i=0;i<=n;i++)//x=i+1 
		{
			ans=min(ans,g(pre[i])+g(n-pre[i])+1);//y=n+1
			ans=min(ans,g(pre[i])+g(suf[i+2])+g(t[i+1]));//y=i+2 
			//y 
			for(int k=0;k<=lim;k++)
			{
				y=a[n-(1<<k)+1];
				ans=min(ans,get(i,y));
				ans=min(ans,get(i,y-1));
				ans=min(ans,get(i,y+1));
			}
//			for(int j=0)
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}