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
const int xx=505,mod=1e9+7;
int n;
int a[xx][xx];
ll f[xx][xx][2];
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	for(int l=1;l<=n;l++)f[l][l][0]=1;
	for(int l=1;l<=n;l++)
	{
		for(int i=1,j;(j=i+l)<=n;i++)
		{
			//01 
			if(a[i][j])
			{
				for(int k=i;k<j;k++)
					f[i][j][1]+=(f[i][k][0]+f[i][k][1])*(f[k+1][j][0]+f[k+1][j][1])%mod;
			}
			for(int k=i+1;k<j;k++)
				f[i][j][0]+=f[i][k][1]*(f[k][j][0]+f[k][j][1])%mod;
			f[i][j][0]%=mod,f[i][j][1]%=mod;
		}
	}
	cout<<(f[1][n][0]+f[1][n][1])%mod<<"\n";
	pc('1',1);
	return 0;
}