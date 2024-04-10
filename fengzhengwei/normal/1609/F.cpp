#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
const int xx=1e6+5;
int n;
ll v[xx],a[xx];
struct nod{int mx,mv;}e[xx<<2];
nod upd(nod a,nod b)
{
	if(a.mx>b.mx)return a;
	if(a.mx<b.mx)return b;
	return {a.mx,a.mv+b.mv};
}
int adt[xx<<2];
void build(int k,int l,int r)
{
	e[k]={0,r-l+1};adt[k]=0;
	if(l==r)return ;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void ad(int k,int z){e[k].mx+=z,adt[k]+=z;}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void Cg(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);int mid=l+r>>1;
	if(x<=mid)Cg(k<<1,l,mid,x,y,z);
	if(mid<y)Cg(k<<1|1,mid+1,r,x,y,z);
	e[k]=upd(e[k<<1],e[k<<1|1]);
}
void cg(int k,int l,int r,int x,int y,int z)
{
//	cout<<x<<" "<<y<<" "<<z<<"\n";
	Cg(k,l,r,x,y,z);
}
struct no{int l,r;};
no stk1[xx],stk2[xx];
int cr[xx],stk[xx],top,rmx[xx],rmn[xx],lmx[xx],lmn[xx],top1,top2;
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=0;j<60;j++)v[i]+=(a[i]>>j&1);
	}
	top=0;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[i]>a[stk[top]])top--;
		if(top)rmx[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[i]>a[stk[top]])top--;
		if(top)lmx[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[i]<a[stk[top]])top--;
		if(top)rmn[i]=stk[top];
		stk[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[i]<a[stk[top]])top--;
		if(top)lmn[i]=stk[top];
		stk[++top]=i;
	}
	ll ans=0;
	for(int I=0;I<=60;I++)
	{
		build(1,1,n);
		top1=top2=0;
		for(int i=1;i<=n;i++)
		{
			if(cr[i]||v[i]==I)
			{
				while(top1&&stk1[top1].l>lmx[i])cg(1,1,n,stk1[top1].l,stk1[top1].r,-1),top1--;
				while(top2&&stk2[top2].l>lmn[i])cg(1,1,n,stk2[top2].l,stk2[top2].r,-1),top2--;
				if(v[i]==I)
				{
					assert(!top1||stk1[top1].r<=lmx[i]);
					assert(!top2||stk2[top2].r<=lmn[i]);
					stk1[++top1]={lmx[i]+1,i},cr[rmx[i]]=1;
					stk2[++top2]={lmn[i]+1,i},cr[rmn[i]]=1;
					cg(1,1,n,stk1[top1].l,stk1[top1].r,1);
					cg(1,1,n,stk2[top2].l,stk2[top2].r,1);
				}
			}
//			if(cr[i])cout<<cr[i]<<" "<<i<<"!\n";
//			if(v[i]==I)cout<<cr[i]<<" "<<i<<"!\n";
			cr[i]=0;
//			cout<<e[1].mx<<"!!\n";
			assert(e[1].mx<=2);
			if(e[1].mx==2)ans+=e[1].mv;
//			,cout<<I<<" "<<i<<" qq "<<e[1].mv<<"\n";
		}
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}