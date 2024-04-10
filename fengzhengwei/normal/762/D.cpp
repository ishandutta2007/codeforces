#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=1e5+5;
int n,a[4][xx];
ll f[4][xx],sum[xx];
ll mx[4];
void ad(ll &a,ll b){a<b?a=b:0;}
int main(){
	n=read();
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[1][i]+a[2][i]+a[3][i];
	mx[1]=0;
	mx[3]=-1e18;
	memset(f,-0x3f,sizeof(f));
	f[1][1]=0;
	for(int i=2;i<=n+1;i++)// 
	{
		ad(f[1][i],f[1][i-1]+a[1][i-1]);
		ad(f[1][i],f[2][i-1]+a[1][i-1]+a[2][i-1]);
		ad(f[1][i],f[3][i-1]+a[1][i-1]+a[2][i-1]+a[3][i-1]);
		ad(f[2][i],f[2][i-1]+a[2][i-1]);
		ad(f[2][i],f[1][i-1]+a[1][i-1]+a[2][i-1]);
		ad(f[2][i],f[3][i-1]+a[3][i-1]+a[2][i-1]);
		ad(f[3][i],f[3][i-1]+a[3][i-1]);
		ad(f[3][i],f[2][i-1]+a[3][i-1]+a[2][i-1]);
		ad(f[3][i],f[1][i-1]+a[3][i-1]+a[2][i-1]+a[1][i-1]);
		ad(f[1][i],mx[3]+sum[i-1]);
		ad(f[3][i],mx[1]+sum[i-1]);
		mx[1]=max(mx[1],-sum[i-1]+f[1][i]);
		mx[3]=max(mx[3],-sum[i-1]+f[3][i]);
	}
	cout<<f[3][n+1]<<"\n";
	pc('1',1);
	return 0;
}