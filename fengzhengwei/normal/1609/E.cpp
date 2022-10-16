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
//Aab(t)CCBt-1btc 
const int xx=1e5+5;
struct node{ll mnA,mnC,AC;}e[xx<<2];
char s[xx];
int adA[xx<<2],adC[xx<<2],n,m;
node upd(node x,node y)
{
	node c;
	c.mnA=min(x.mnA,y.mnA);
	c.mnC=min(x.mnC,y.mnC);
	c.AC=min(x.AC,y.AC);
	c.AC=min(x.mnA+y.mnC,c.AC);
	return c;
}
void Ad(int x,int z,int op)
{
	if(op==0)
	{
		adA[x]+=z;
		e[x].mnA+=z;
		e[x].AC+=z;
	}
	else 
	{
		adC[x]+=z;
		e[x].mnC+=z;
		e[x].AC+=z;
	}
}
void pd(int k)
{
	if(adA[k])
	{
		Ad(k<<1,adA[k],0);
		Ad(k<<1|1,adA[k],0);
		adA[k]=0;
	}
	if(adC[k])
	{
		Ad(k<<1,adC[k],1);
		Ad(k<<1|1,adC[k],1);
		adC[k]=0;
	}
}
void cg(int k,int l,int r,int x,int y,int z,int op)
{
	if(x>y)return;
	if(x<=l&&r<=y)return Ad(k,z,op);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z,op);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z,op);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		e[k].mnA=0;
		e[k].mnC=0;
		e[k].AC=1e18;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void Cg(int x,int op)
{
	if(s[x]=='a')
	{
		cg(1,0,n+1,x,n+1,op,0);
	}
	if(s[x]=='c')
	{
		cg(1,0,n+1,0,x,op,1);
	}
	if(s[x]=='b')
	{
		cg(1,0,n+1,x,n+1,-op,0);
		cg(1,0,n+1,x+1,n+1,op,1);
	}
}
void out(int k,int l,int r,int op)
{
	if(l==r)
	{
		if(op==0)cout<<e[k].mnA<<" ";
		else cout<<e[k].mnC<<" ";
		return;
	}
	pd(k);
	int mid=l+r>>1;
	out(k<<1,l,mid,op);
	out(k<<1|1,mid+1,r,op);
}
signed main(){
	n=read(),m=read();
	scanf("%s",s+1);
	build(1,0,n+1);
	for(int i=1;i<=n;i++)
	{
		Cg(i,1);
//		out(1,0,n+1,0);
//		puts("");
//		out(1,0,n+1,1);
//		puts("");
//		puts("");
	}
//	cout<<e[1].AC<<"\n";
	for(int i=1;i<=m;i++)
	{
		int a=read();
		char c;
		while((c=getchar())!='a'&&c!='b'&&c!='c');
		Cg(a,-1);
		s[a]=c;
		Cg(a,1);
		cout<<e[1].AC<<"\n";
	}
	
	pc('1',1);
	return 0;
}