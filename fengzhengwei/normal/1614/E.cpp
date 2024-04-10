#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0');
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
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n;
const int xx=2e5+5;
struct nod{int tg,l,r;}e[xx*410];
int cst;
void ad(int &k,int z)
{
	if(!k)k=++cst;
	e[k].tg+=z;
}
void pd(int k)
{
	if(e[k].tg)
	{
		ad(e[k].l,e[k].tg);
		ad(e[k].r,e[k].tg);
		e[k].tg=0;
	}
}
int ask(int k,int l,int r,int x)
{
	if(!k)return x;
	if(l==r)return e[k].tg+x;
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)return ask(e[k].l,l,mid,x);
	return ask(e[k].r,mid+1,r,x);
}
void cg(int &k,int l,int r,int x,int y,int z)
{
	if(x>y)return ;
	if(!k)k=++cst;
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(e[k].l,l,mid,x,y,z);
	if(mid<y)cg(e[k].r,mid+1,r,x,y,z);
}
int root;
int ef(int l,int r,int z)//z 
{
//	cerr<<r-l<<"\n";
	int ans=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(ask(root,0,1e9,mid)<=z)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
//	freopen("b.out","w",stdout);
//	cout<<sizeof(e)/1024/1024<<"\n";
	n=read();
	int last=0;
	for(int i=1;i<=n;i++)
	{
		int T=read(),x=ef(max(0,T-i-3),min(1000000000,T+i+3),T-1);
//		cout<<x<<"\n";
		cg(root,0,1e9,0,x,1);
		x=ef(max(0,T-i-3),min(1000000000,T+i+3),T)+1;
		cg(root,0,1e9,x,1e9,-1);
		int k=read();
		while(k--)
		{
			x=(read()+last)%(1000000000+1);
			cout<<(last=ask(root,0,1e9,x))<<"\n";
		}
	}
//	cerr<<cst<<"\n";
	pc('1',1);
	return 0;
}