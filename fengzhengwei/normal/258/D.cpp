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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=3e3+5,mod=1e9+7,ni2=(mod+1)/2;
int n,q,a[xx],x[xx],y[xx];
// 
//fxyixydlt 
int pw[xx],dlt;
dd f[xx][xx],lin[xx][xx];
int main(){
	pw[0]=1;
	for(int i=1;i<xx;i++)pw[i]=pw[i]*2%mod;
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)
		x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i<j)f[i][j]=1;
	dlt=1;
	for(int i=q;i>=1;i--)
	{
		int a=x[i],b=y[i];
		//*2 
		//x=a y!=b/y=a x!=b
		for(int j=1;j<=n;j++)lin[a][j]=lin[b][j]=lin[a][b]=lin[b][a]=lin[j][a]=lin[j][b]=0;
		for(int j=1;j<=n;j++)
		{
			if(j==b)continue;
			//dlt 
			lin[a][j]=(f[a][j]+f[b][j])/2;
			lin[j][a]=(f[j][a]+f[j][b])/2;
		}
		//x=b y!=a/y=b x!=a 
		for(int j=1;j<=n;j++)
		{
			if(j==a)continue;
			lin[b][j]=(f[a][j]+f[b][j])/2;
			lin[j][b]=(f[j][a]+f[j][b])/2;
		}
		//x=a y=b 
		lin[a][b]=(f[a][b]+f[b][a])/2;
		//x=b y=a 
		lin[b][a]=(f[a][b]+f[b][a])/2;
		dlt*=2,dlt%=mod;
		for(int j=1;j<=n;j++)
		{
			if(j==b)continue;
			//dlt 
			f[a][j]=lin[a][j],f[j][a]=lin[j][a];
		}
		
		for(int j=1;j<=n;j++)
		{
			if(j==a)continue;
			//dlt 
			f[b][j]=lin[b][j],f[j][b]=lin[j][b];
		}
		f[a][b]=lin[a][b],f[b][a]=lin[b][a];
//		cout<<i<<"!!ASD\n";
//		{
//			for(int i=1;i<=n;i++)
//				for(int j=1;j<=n;j++)
//				{
//					cout<<i<<" "<<j<<" "<<1ll*f[i][j]*dlt%mod<<"\n";
//				}
//		}
//		puts("");
		
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//		{
//			cout<<i<<" "<<j<<" "<<1ll*f[i][j]*dlt%mod<<"\n";
//		}
	dd ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]>a[j])ans+=1ll*f[i][j];
	cout<<fixed<<setprecision(6)<<ans<<"\n";
	pc('1',1);
	return 0;
}