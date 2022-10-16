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
const int xx=5e3+5;
ll f[xx][xx];
int x[xx],a[xx],b[xx],c[xx],d[xx],n,s,e;
void ad(ll &a,ll b){a>b?a=b:0;}
int main(){
	n=read(),s=read(),e=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++)a[i]=read()+x[i];
	for(int i=1;i<=n;i++)b[i]=read()-x[i];
	for(int i=1;i<=n;i++)c[i]=read()+x[i];
	for(int i=1;i<=n;i++)d[i]=read()-x[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(f[i][j]>1e18)continue;
//			cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<i+1<<" "<<j+1<<"!!\n";
			if(i>=s&&i>=e&&j==1)continue;// 
			if(i+1!=s&&i+1!=e)
			{
				if(j>=2)ad(f[i+1][j-1],f[i][j]+c[i+1]+a[i+1]);
				if(j>=1+(i+1>s))ad(f[i+1][j],f[i][j]+c[i+1]+b[i+1]);// 
				if(j>=1+(i+1>e))ad(f[i+1][j],f[i][j]+d[i+1]+a[i+1]);// 
				ad(f[i+1][j+1],f[i][j]+d[i+1]+b[i+1]);
			}
			//st 
			// 
			if(i+1==s)
			{
				if(j>=1)ad(f[i+1][j],f[i][j]+c[i+1]);
				ad(f[i+1][j+1],f[i][j]+d[i+1]);
			}
			if(i+1==e)
			{
				if(j>=1)ad(f[i+1][j],f[i][j]+a[i+1]);
				ad(f[i+1][j+1],f[i][j]+b[i+1]);
			}
		}
	}
	cout<<f[n][1]<<"\n";
	pc('1',1);
	return 0;
}