#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=505;
int n;
struct nod{ll a,b,k;bool operator<(const nod&w)const{return b>w.b;};}e[xx<<1];
ll f[2][xx];
void ad(ll &a,ll b){(a<b)?a=b:0;}
int main(){
	memset(f,-0x3f,sizeof(f));
	n=read();
	for(int i=1;i<=n;i++)e[i].a=read(),e[i].b=read(),e[i].k=read();
	sort(e+1,e+n+1);
//	for(int i=1;i<=n;i++)cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].k<<"\n";
	f[0][0]=0;
	for(int i=0;i<n;i++)
	{
		int I=i&1,T=I^1;
		for(int j=0;j<=n;j++)
		{
			if(f[I][j]<-1e9)continue;
			ad(f[T][j],f[I][j]+e[i+1].a-e[i+1].b*e[i+1].k);
			ad(f[T][j+1],f[I][j]+e[i+1].a-e[i+1].b*j);
			ad(f[T][j],f[I][j]);
			f[I][j]=-1e18;
		}
	}
	ll ans=0;
	for(int j=0;j<=n;j++)ad(ans,f[n&1][j]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}