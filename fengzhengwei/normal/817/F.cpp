#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=1e5+5;
struct node
{
	int maxx,minn,add,l,r;
	node(){maxx=minn=l=r=0,add=-1;}
}e[xx<<7];//1e8+1
int cst;
void ad(int x,int s)
{
	if(s==1||s==0)
	{
		e[x].add=s;
		e[x].maxx=e[x].minn=s;
		return;
	}
	if(e[x].add==-1)
	{
		e[x].add=s;
		swap(e[x].maxx,e[x].minn);
		e[x].maxx^=1;
		e[x].minn^=1;
		return;
	}
	if(e[x].add==2)
	{
		e[x].add=-1;
		swap(e[x].maxx,e[x].minn);
		e[x].maxx^=1;
		e[x].minn^=1;
		return;
	}
	e[x].add^=1;
	swap(e[x].maxx,e[x].minn);
	e[x].maxx^=1;
	e[x].minn^=1;
}
void pd(int k)
{
	if(e[k].add==-1)return;
	if(!e[k].l)e[k].l=++cst;
	if(!e[k].r)e[k].r=++cst;
	ad(e[k].l,e[k].add);
	ad(e[k].r,e[k].add);
	e[k].add=-1;
	return;
}
void ph(int k)
{
	e[k].maxx=max(e[e[k].l].maxx,e[e[k].r].maxx);
	e[k].minn=min(e[e[k].l].minn,e[e[k].r].minn);
}
void change(int &k,ll l,ll r,ll x,ll y,int z)
{
	if(x>y)return;
	if(!k)k=++cst;
	if(x<=l&&r<=y)return ad(k,z);
	ll mid=l+r>>1;
	pd(k);
	if(x<=mid)change(e[k].l,l,mid,x,y,z);
	if(mid<y)change(e[k].r,mid+1,r,x,y,z);
	ph(k);
//	cout<<k<<" "<<l<<" "<<r<<" "<<e[k].maxx<<" sss "<<e[k].minn<<"\n";
}
ll ask(int k,ll l,ll r)
{
	if(!k)return l;
	if(l==r)return l;
	pd(k);
	ll mid=l+r>>1;
	if(e[e[k].l].minn==0)return ask(e[k].l,l,mid);
	return ask(e[k].r,mid+1,r);
}
ll l[xx];
ll r[xx];
int op[xx];
ll lsh[xx<<2];
signed main(){
	int tot;
	int root=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		int ops=read();
		ops--;
		if(ops==0)ops=1;
		else if(ops==1)ops=0;
		op[i]=ops;
		l[i]=read();
		r[i]=read();
		lsh[++tot]=l[i];
		lsh[++tot]=r[i];
		lsh[++tot]=r[i]+1;
	}
	lsh[++tot]=1;
	sort(lsh+1,lsh+tot+1);
	tot=unique(lsh+1,lsh+tot+1)-lsh-1;
	for(int i=1;i<=n;i++)
	{
		l[i]=lower_bound(lsh+1,lsh+tot+1,l[i])-lsh;
		r[i]=lower_bound(lsh+1,lsh+tot+1,r[i])-lsh;
		change(root,1,tot+1,l[i],r[i],op[i]);
		cout<<lsh[ask(root,1,tot+1)]<<"\n";
	}
	return 0;
}