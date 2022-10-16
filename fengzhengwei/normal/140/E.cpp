#include<bits/stdc++.h>
#define ll long long
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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
int n,m,mod;
int f[5005][5005];
int t[2][5005];
int c[5005];
int jiec[5005],l[1000005];
signed main(){
//	cout<<sizeof(c)/1024/1024<<"\n";
	n=read(),m=read(),mod=read();
	f[0][0]=1;
	c[0]=1;
	jiec[0]=1;
	for(int i=1;i<=5000;i++)c[i]=1ll*c[i-1]*(m-i+1)%mod;
	for(int i=1;i<=5000;i++)jiec[i]=1ll*jiec[i-1]*i%mod;
	for(int i=1;i<=5000;i++)
		for(int j=1;j<=5000;j++)
			f[i][j]=(f[i-1][j-1]+1ll*(j-1)*f[i-1][j])%mod;
	for(int i=1;i<=n;i++)
		l[i]=read();
	t[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		ll sgm=0;
		for(int j=0;j<=l[i-1];j++)sgm+=t[(i-1)&1][j];
		sgm%=mod;
		if(i>=2)
		for(int j=0;j<=l[i-2];j++)t[i&1][j]=0;
		for(int j=1;j<=l[i];j++)
			t[i&1][j]=(sgm*c[j]%mod-1ll*t[(i-1)&1][j]*jiec[j]%mod+mod)*f[l[i]][j]%mod;
//			,cout<<i<<" "<<j<<" "<<t[i&1][j]<<" "<<i<<" "<<c[j]<<" "<<sgm<<" "<<f[l[i]][j]<<" "<<-1ll*t[(i-1)&1][j]*jiec[j]<<"\n";
	}
	int i=n; 
	ll sgm=0;
	for(int j=0;j<=l[i];j++)sgm+=t[i&1][j];
	sgm%=mod;
	cout<<sgm<<"\n";
	pc('1',1);
	return 0;
}