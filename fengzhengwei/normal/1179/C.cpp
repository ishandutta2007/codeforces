#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	int w=1;
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
	wt(x),pc(c,0);
}
const int xx=1e6+5;
int n,m,a[xx],b[xx];
int mn[xx<<2],adt[xx<<2];
void ad(int k,int a){mn[k]+=a,adt[k]+=a;}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void cg(int k,int l,int r,int x,int y,int z)
{
//	cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<"\n";
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
int ef(int k,int l,int r)
{
//	cout<<k<<" "<<l<<" "<<r<<"\n";
	if(mn[k]>=0)return -1;
	if(l==r)return l;int mid=l+r>>1;
	pd(k);
	if(mn[k<<1|1]<0)return ef(k<<1|1,mid+1,r);
	return ef(k<<1,l,mid);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=n;i++)cg(1,1,1e6,1,a[i],-1);
	for(int i=1;i<=m;i++)cg(1,1,1e6,1,b[i],1);
	int q=read();
	while(q--)
	{
		int op=read();
		if(op==1)
		{
			int i=read(),v=read();
			cg(1,1,1e6,1,a[i],1);
			a[i]=v;
			cg(1,1,1e6,1,a[i],-1);
		}
		else 
		{
			int i=read(),v=read();
			cg(1,1,1e6,1,b[i],-1);
			b[i]=v;
			cg(1,1,1e6,1,b[i],1);
		}
//	cout<<mn[1]<<"\n";
		cout<<ef(1,1,1e6)<<"\n";
	}
	pc('1',1);
	return 0;
}