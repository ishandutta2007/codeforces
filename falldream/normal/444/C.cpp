#include<iostream>
#include<cstdio>
#include<set>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Tree{int l,r;long long x,val;}T[MN*4+5];
set<pair<int,int> >st;
int n,m,c[MN+5];

void Mark(int x,long long v){T[x].val+=v;T[x].x+=v*(T[x].r-T[x].l+1);}
void pushdown(int x){Mark(x<<1,T[x].val);Mark(x<<1|1,T[x].val);T[x].val=0;}

long long Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].x;
	int mid=T[x].l+T[x].r>>1;if(T[x].val) pushdown(x);
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r);	
}

void Modify(int x,int l,int r,int v)
{
	if(T[x].l==l&&T[x].r==r){Mark(x,v);return;}
	int mid=T[x].l+T[x].r>>1;if(T[x].val) pushdown(x);
	if(r<=mid) Modify(x<<1,l,r,v);
	else if(l>mid) Modify(x<<1|1,l,r,v);
	else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
	T[x].x=T[x<<1].x+T[x<<1|1].x; 
}

void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r))return;
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);	
}
inline int abs(int x){return x<0?-x:x;}
int main()
{
	n=read();m=read();Build(1,1,n);
	for(int i=1;i<=n;++i) st.insert(make_pair(i,c[i]=i));
	for(int i=1;i<=m;++i) if(read()==1)
	{
		int l=read(),r=read(),x=read();
		set<pair<int,int> >::iterator it=st.lower_bound(make_pair(l,0));	
		for(;it!=st.end()&&it->first<=r;it=st.lower_bound(make_pair(l,0)))
		{
			Modify(1,it->first,min(r,it->second),abs(c[it->first]-x));
			if(it->second>r) c[r+1]=c[it->first],st.insert(make_pair(r+1,it->second));
			st.erase(it);
		}
		for(;it!=st.begin()&&(--it)->second>=l;it=st.lower_bound(make_pair(l,0)))
		{
			Modify(1,max(l,it->first),min(it->second,r),abs(c[it->first]-x));
			if(it->first<l) st.insert(make_pair(it->first,l-1));
			if(it->second>r) c[r+1]=c[it->first],st.insert(make_pair(r+1,it->second));
			st.erase(it);
		}
		c[l]=x;st.insert(make_pair(l,r));
	}
	else {int l=read(),r=read();printf("%lld\n",Query(1,l,r));}
	return 0;
}