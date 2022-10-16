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
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
int n,m,K,mod;
//nmj=k 
int f[105][105][105],c[105][105];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int red(int a){return a>=mod?a-mod:a;}
int main(){
	n=read(),m=read(),K=read(),mod=read();
	for(int i=0;i<105;i++)c[i][0]=1;
	for(int i=1;i<105;i++)
	{
		for(int j=1;j<=i;j++)c[i][j]=red(c[i-1][j]+c[i-1][j-1]);
//		cout<<c[i][1]<<"!!\n";
//		,cerr<<i<<" "<<j<<" "<<c[i][j]<<"!!\n";
		
	}
	for(int i=1;i<=n+1;i++)f[0][0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=K;j++)
		{
			for(int k=1;k<=min(n,n-i+1);k++)
			{
				for(int w=1;w<=i;w++)// 
				{
					for(int a=0;a<=j-(k==m);a++)
					{
						ad(f[i][j][k],1ll*f[w-1][a][k+1]*f[i-w][j-a-(k==m)][k+1]%mod*c[i-1][w-1]%mod);
//						cerr<<i<<" "<<j<<" "<<k<<" "<<w<<" "<<f[i][j][k]<<" "<<a<<"!!\n";
						
					}
				}
			}
		}
		if(1.0*clock()/CLOCKS_PER_SEC>=1.9)
		{
			puts("0");
			return 0;
		}
	}
	cout<<f[n][K][1]<<"\n";
	pc('1',1);
	return 0;
}