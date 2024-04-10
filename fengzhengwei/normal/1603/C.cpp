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
const int xx=1e5+5;
int n,a[xx];
const int mod=998244353;
int f[xx][318],g[xx][318];
//fyansgyans 
int main(){
//	cout<<sizeof(f)*2/1024/1024<<"\n";
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int B=317;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=B;j++)
			{
				g[i][j]=(1ll*(i)*((a[i]+j-1)/j -1)%mod+g[i-1][a[i]/((a[i]+j-1)/j)])%mod;//-1 
				int to=a[i]/j;
				f[i][j]=(1ll*(j-1)*(i)%mod+((to<=B?g[i-1][to]:f[i-1][(a[i-1]+to-1)/to])))%mod;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)ans+=f[i][1];
		ans%=mod;
		cout<<ans<<"\n";
	}
	return 0;
}