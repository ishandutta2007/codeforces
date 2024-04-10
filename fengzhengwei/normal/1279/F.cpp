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
const int xx=1e6+5;
int n,k,L;
char s[xx];
int a[xx],sum[xx];
struct no{int fi,se;}f[xx];
no ad(no x,int a,int b){x.fi+=a,x.se+=b;return x;}
void upd(no &a,no b){if(a.fi<b.fi||(a.fi==b.fi&&a.se>b.se))a=b;}
int check(int dlt)
{
	for(int i=1;i<=n;i++)
	{
		f[i]=ad(f[i-1],a[i],0);
		upd(f[i],ad(f[max(0,i-L)],min(L,i)+dlt,1));
	}
	return f[n].se;
}
int main(){
	n=read(),k=read(),L=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')a[i]=1;
		else a[i]=0;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	//1 
	int res=0;
	int l=-L,r=0,ans=0;
	// 
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)<=k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans);
	res=max(res,f[n].fi-k*ans);
	for(int i=1;i<=n;i++)a[i]^=1,sum[i]=sum[i-1]+a[i];
	l=-L,r=0,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)<=k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans);
	res=max(res,f[n].fi-k*ans);
	cout<<n-res<<"\n";
//	cout<<f[n].fi-k*ans<<"\n";
	
	pc('1',1);
	return 0;
}