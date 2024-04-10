// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
typedef long long ll;
template<typename _Tp>void read(_Tp &x)
{
	register char ch(getchar());
	bool f(0);
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template<typename _Tp>inline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
int len;
struct seg_tr{
	struct Node{
		int ls,rs;
		int tag;
		ll ans0,ans1;
		bool rev;
		inline Node():tag(-1){}
	}f[1000005];
	int node_cnt;
	inline void PushUp(const int &x)
	{
		f[x].ans0=min(f[f[x].ls].ans0,f[f[x].rs].ans0);
		f[x].ans1=min(f[f[x].ls].ans1,f[f[x].rs].ans1);
	}
	inline void cover(const int &x,const int &col,const int &l)
	{
		f[x].rev=0;
		f[x].tag=col;
		if(col)
		{
			f[x].ans0=len+1;
			f[x].ans1=l;
		}
		else
		{
			f[x].ans0=l;
			f[x].ans1=len+1;
		}
	}
	inline void reverse(const int &x)
	{
		f[x].rev^=1;
		std::swap(f[x].ans0,f[x].ans1);
	}
	inline void PushDown(const int &x,const int &l,const int &r)
	{
		if(~f[x].tag)
		{
			cover(f[x].ls,f[x].tag,l);
			cover(f[x].rs,f[x].tag,((l+r)>>1)+1);
			f[x].tag=-1;
		}
		if(f[x].rev)
		{
			reverse(f[x].ls);
			reverse(f[x].rs);
			f[x].rev=0;
		}
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].ans0=l;
			f[cur].ans1=len+1;
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(const int &cur,const int &L,const int &R,const int &l,const int &r,const int &col)
	{
		if(L<=l&&r<=R)
		{
			cover(cur,col,l);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur,l,r);
		if(L<=mid) Update(f[cur].ls,L,R,l,mid,col);
		if(R>mid) Update(f[cur].rs,L,R,mid+1,r,col);
		PushUp(cur);
	}
	void flip(const int &cur,const int &L,const int &R,const int &l,const int &r)
	{
		if(L<=l&&r<=R)
		{
			reverse(cur);
			return;
		}
		PushDown(cur,l,r);
		int mid=(l+r)>>1;
		if(L<=mid) flip(f[cur].ls,L,R,l,mid);
		if(R>mid) flip(f[cur].rs,L,R,mid+1,r);
		PushUp(cur);
	}
}tr;
const int N=100005;
ll t[N<<2],pos;
int opt[N];
ll l[N],r[N];
int main()
{
// 	freopen("a.in","r",stdin);
// 	freopen("a.out","w",stdout);
	int _;
	read(_);
	for(int i=1;i<=_;++i)
	{
		read(opt[i]),read(l[i]),read(r[i]);
		t[++pos]=l[i];
		t[++pos]=r[i];
		t[++pos]=r[i]+1;
	}
	t[++pos]=1;
	std::sort(t+1,t+pos+1);
	len=std::unique(t+1,t+pos+1)-t-1;
	t[len+1]=t[400001]=1000000000000000001ll;
	int root=tr.build(1,len+1);
	for(int i=1;i<=_;++i)
	{
		l[i]=std::lower_bound(t+1,t+len+1,l[i])-t;
		r[i]=std::lower_bound(t+1,t+len+1,r[i])-t;
		if(opt[i]==1)
		{
			tr.Update(root,l[i],r[i],1,len+1,1);
		}
		else if(opt[i]==2)
		{
			tr.Update(root,l[i],r[i],1,len+1,0);
		}
		else
		{
			tr.flip(root,l[i],r[i],1,len+1);
		}
		printf("%lld\n",t[tr.f[root].ans0]);
	}
	return 0;
}