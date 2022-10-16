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
const int xx=2e5+5;
int n,m,a[xx],pr[xx],t[xx],f[xx][21];
int sum[xx<<2],adt[xx<<2];
void ad(int x,int z)
{
	sum[x]+=z;
	adt[x]+=z;
}
void pd(int x){if(adt[x])ad(x<<1,adt[x]),ad(x<<1|1,adt[x]),adt[x]=0;}
void cg(int k,int l,int r,int x,int y,int z)
{
//	assert(l<=r);
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	sum[k]=max(sum[k<<1],sum[k<<1|1]);
}
void build(int k,int l,int r)
{
//	cout<<k<<" "<<l<<" ss "<<r<<"\n";
	sum[k]=adt[k]=0;
	if(l==r)return ;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
	{
		pr[i]=t[a[i]];
		t[a[i]]=i;
	}
	for(int j=1;j<=m;j++)
	{
		build(1,0,n);
		
		for(int i=1;i<=n;i++)
		{
//		cerr<<j<<" "<<i<<" "<<pr[i]<<"\n";
			cg(1,0,n,pr[i],i-1,1);
			f[i][j]=sum[1];
			cg(1,0,n,i,i,f[i][j-1]);
		}
	}
	cout<<f[n][m]<<"\n";
	pc('1',1);
	return 0;
}