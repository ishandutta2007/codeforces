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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
const int xx=205,mod=1e9+7;
int n,m,f[205][205][1005];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int a[xx];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=m;k++)
			{
				if(!f[i][j][k])continue;
				if(k+j*(a[i+1]-a[i])>m)continue;
				int to=k+j*(a[i+1]-a[i]);
				ad(f[i+1][j][to],1ll*f[i][j][k]*j%mod);//
				if(j)ad(f[i+1][j-1][to],1ll*f[i][j][k]*j%mod);// 
				ad(f[i+1][j+1][to],f[i][j][k]);// 
				ad(f[i+1][j][to],f[i][j][k]);// 
			}
		}
	}
	int ans=0;
	for(int k=0;k<=m;k++)ad(ans,f[n][0][k]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}