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
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;else if(c==EOF)return -1;
	int ans=c-'0';
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
const int xx=5e5+15;
int n,m;
struct nod{int mn,num;}e[xx<<3];
int adt[xx<<3];
void ad(int x,int z){adt[x]+=z,e[x].mn+=z;}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void upd(int k){e[k].mn=min(e[k<<1].mn,e[k<<1|1].mn);e[k].num=0;if(e[k].mn==e[k<<1].mn)e[k].num+=e[k<<1].num;if(e[k].mn==e[k<<1|1].mn)e[k].num+=e[k<<1|1].num;}
void one(int k,int l,int r,int x,int y)
{
	if(l==r)return e[k].num=y,void();
	pd(k);int mid=l+r>>1;
	if(x<=mid)one(k<<1,l,mid,x,y);
	else one(k<<1|1,mid+1,r,x,y);
	upd(k);
}
void cg(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return ad(k,z),void();
	pd(k);int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	upd(k);
//	cout<<k<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<" "<<e[k].mn<<" "<<e[k].num<<"\n";
}
int a[xx];
signed main(){
	//01e6+1,n+10 
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	a[0]=1e6+1,a[n+1]=0;
	for(int i=1;i<=n+1;i++)
		if(a[i-1]>a[i])cg(1,0,1e6,a[i],a[i-1]-1,1);
	for(int i=1;i<=n;i++)one(1,0,1e6,a[i],1);
//	cout<<e[1].num<<" "<<e[1].mn<<"\n";
//	exit(0);
	for(int i=1;i<=m;i++)
	{
		int I=read(),b=read();
		if(a[I-1]>a[I])cg(1,0,1e6,a[I],a[I-1]-1,-1);
		if(a[I]>a[I+1])cg(1,0,1e6,a[I+1],a[I]-1,-1);
		one(1,0,1e6,a[I],0);
		a[I]=b;
		if(a[I-1]>a[I])cg(1,0,1e6,a[I],a[I-1]-1,1);
		if(a[I]>a[I+1])cg(1,0,1e6,a[I+1],a[I]-1,1);
		one(1,0,1e6,a[I],1);
		assert(e[1].mn==1);
		cout<<e[1].num<<"\n";
	}
	pc('1',1);
	return 0;
}