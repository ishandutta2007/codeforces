#include<bits/stdc++.h>
#define ll long long
#define dd long double
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
const int xx=2005;
int n,a,b;
dd p[xx],u[xx];
//a p b u  (1-(1-p)(1-u)=p+u-pu) 
struct nod{dd f;int num;nod(){f=-1e18,num=1e9;}};
void upd(nod&a,nod b)
{
	if(a.f<b.f)a=b;
	else if(a.f==b.f&&a.num>b.num)a=b;
}
nod D(nod a,dd x,int y)
{
	a.f+=x,a.num+=y;
	return a;
}
dd dlt;
nod em,ans;// 
nod f[xx][xx];
//ba 

void check()
{
	em.f=em.num=0;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)f[i][j]=nod();
	f[0][0]=em;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(j!=b)
			{
				upd(f[i+1][j+1],D(f[i][j],p[i+1]+u[i+1]-p[i+1]*u[i+1]+dlt,1));
				upd(f[i+1][j+1],D(f[i][j],u[i+1],0));
			}
			upd(f[i+1][j],f[i][j]);
			upd(f[i+1][j],D(f[i][j],p[i+1]+dlt,1));
		}
	}
	ans=nod();
	for(int i=1;i<=n;i++)upd(ans,f[n][b]);
}
signed main(){
	n=read(),a=read(),b=read();
	for(int i=1;i<=n;i++)scanf("%Lf",&p[i]);
	for(int i=1;i<=n;i++)scanf("%Lf",&u[i]);
	dd l=-n,r=n;
	while(l+(0.0001)<=r)
	{
		dd mid=(l+r)/2;
		dlt=mid;
		check();
		if(ans.num<=a)l=mid;// 
		else r=mid;
		if(ans.num==a)break;
	}
	dlt=l;
	check();
//	assert(ans.num==a);
	cout<<fixed<<setprecision(4)<<ans.f-dlt*a<<"\n";//adlt 
	pc('1',1);
	return 0;
}