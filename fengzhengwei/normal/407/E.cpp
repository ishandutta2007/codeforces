#include<bits/stdc++.h>
#define ll long long
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
const int xx=2e5+5;
int n,k,d;
map<int,vector<int> >mp;
ll a[xx];
int ans,aid;
ll mn[xx<<2],adt[xx<<2];
void ad(int k,ll z){mn[k]+=z;adt[k]+=z;}
void pd(int k){if(adt[k])ad(k<<1,adt[k]),ad(k<<1|1,adt[k]),adt[k]=0;}
void cg(int k,int l,int r,int x,int y,ll z)
{
	if(x<=l&&r<=y)return ad(k,z);
	pd(k);int mid=l+r>>1;
	if(x<=mid)cg(k<<1,l,mid,x,y,z);
	if(mid<y)cg(k<<1|1,mid+1,r,x,y,z);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
ll Cr;
int find(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)
		if(mn[k]>Cr)return r+1;
//		mn[k]<=Cr?l:r+1;
	if(l==r)return l;
	pd(k);int mid=l+r>>1;
	if(y<=mid)return find(k<<1,l,mid,x,y);
	if(mid<x)return find(k<<1|1,mid+1,r,x,y);
	int a;
	if((a=find(k<<1,l,mid,x,y))!=mid+1)return a;
	return find(k<<1|1,mid+1,r,x,y);
}
void build(int k,int l,int r)
{
	if(l==r)return mn[k]=l,void();
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
struct nod{int l,r;ll v;};
nod smn[xx],smx[xx];
int tpmn,tpmx;
map<ll,int>lst;
void solve(int l,int r)
{
	if(r<1)return;
	lst.clear();
	tpmn=tpmx=0;
	//mx-mn 
	// 
	int al=l-1;
	//mx-mn+1-(r-l+1)<=k 
	//mx-mn-r+l<=k
	//mx-mn+l<=k+r
	for(int i=l;i<=r;i++)
	{
		int L=i;
		while(tpmn&&smn[tpmn].v>=(a[i]/d))cg(1,1,n,smn[tpmn].l,smn[tpmn].r,smn[tpmn].v),L=smn[tpmn].l,tpmn--;
		cg(1,1,n,L,i,-a[i]/d),smn[++tpmn]={L,i,(a[i]/d)};
		L=i;
		while(tpmx&&smx[tpmx].v<=(a[i]/d))cg(1,1,n,smx[tpmx].l,smx[tpmx].r,-smx[tpmx].v),L=smx[tpmx].l,tpmx--;
		cg(1,1,n,L,i,a[i]/d),smx[++tpmx]={L,i,(a[i]/d)};
		al=max(al,lst[a[i]]),lst[a[i]]=i;
		Cr=k+i;
		assert(al<i);
		int to=find(1,1,n,al+1,i);
		if(ans<i-to+1)ans=i-to+1,aid=1e9;
		if(ans==i-to+1)aid=min(aid,to);
	}
}
signed main(){
	n=read(),k=read(),d=read();
	if(d==0)
	{
		a[0]=-1e9-1;
		for(int i=1;i<=n;i++)a[i]=read();
		int id=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])id=i;
			if(ans<i-id+1)ans=i-id+1,aid=id;
		}
		cout<<aid<<" "<<aid+ans-1<<"\n";
		exit(0);
	}
	build(1,1,n);
	Cr=k;
	for(int i=1;i<=n;i++)
		a[i]=read()+1ll*d*1e9;
	for(int i=1;i<=n;i++)
		mp[a[i]%d].push_back(i);
	for(auto it:mp)
	{
		int ls=-1,st=-1;
		for(auto y:it.second)
		{
			if(y!=ls+1)solve(st,ls),st=ls=y;
			else ls=y;
		}
		solve(st,ls);
	}
	cout<<aid<<" "<<aid+ans-1<<"\n";
	pc('1',1);
	return 0;
}