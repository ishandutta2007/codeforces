#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;};return *s++;}
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
	wt(x),pc(op,0);
}
const int xx=1e6+5;
int n,m,p;
vector<ll>v[xx<<2];
ll sum[xx<<2],a[xx<<2];
void build(int k,int l,int r)
{
	v[k].resize(r-l+1+1+1);
	if(l==r)
	{
		v[k][0]=-4e15,v[k][1]=p-a[l],v[k][2]=4e15;
		sum[k]=a[l];
//	for(int i=1;i<=r-l+1;i++)cout<<k<<" "<<l<<" "<<r<<" "<<i<<" "<<v[k][i]<<"@\n";
		return ;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	v[k][0]=-4e15;
	int lp=0;
	for(int i=1;i<=r-l+1;i++)
	{
		while((r-mid)<i-lp||v[k<<1][lp+1]-1+sum[k<<1]-1ll*p*lp<v[k<<1|1][i-lp])++lp;
//		cerr<<lp<<"@@\n";
		v[k][i]=max(v[k<<1|1][i-lp]+1ll*p*lp-sum[k<<1],v[k<<1][lp]);
	}
	v[k][r-l+1+1]=4e15;
//	for(int i=1;i<=r-l+1;i++)cout<<k<<" "<<l<<" "<<r<<" "<<i<<" "<<v[k][i]<<"@\n";
	
}
ll nw;
void ask(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
	{
		int L=0,R=r-l+1,ans=0;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(nw>=v[k][mid])ans=mid,L=mid+1;
			else R=mid-1;
		}
		nw=nw+sum[k]-1ll*p*ans;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid)ask(k<<1,l,mid,x,y);
	if(mid<y)ask(k<<1|1,mid+1,r,x,y);
	return;
}
signed main(){
	n=read(),m=read(),p=read();
	for(int i=1;i<=n;i++)a[i]=read();
//	for(int i=1;i<=n;i++)a[i]=i;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read();
//		int l=i,r=n;
		nw=0;ask(1,1,n,l,r);
		cout<<nw<<"\n";
	}
	
	pc('1',1);
	return 0;
}