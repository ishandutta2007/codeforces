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
const int xx=1e5+5;
int n,c,a[xx],b[xx],id[xx];
signed main(){
	n=read(),c=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)id[i]=i;
	ll ans=1e18,sum=0;
	sort(id+1,id+n+1,[&](int x,int y){return -a[x]+b[x]+1ll*c*(n-x)<-a[y]+b[y]+1ll*c*(n-y);});
	for(int i=1;i<=n;i++)sum+=a[i];
	ans=min(ans,sum);
	for(int i=1;i<=n;i++)
	{
		int x=id[i];
		sum+=(-a[x]+b[x]+1ll*c*(n-x));
		ans=min(ans,sum-1ll*c*(1ll*i*(i-1)/2));
	}
	cout<<ans<<'\n';
	pc('1',1);
	return 0;
}