#include<cstdio>
#include<cstring>
#include<algorithm>

typedef long long ll;

template<typename _Tp>void read(_Tp &x)
{
	register char ch=getchar();
	bool f=0;
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
const int N=250005;
struct seg_tr{
	struct Node{
		int ls,rs;
		bool l_col,r_col;
		int tot;
		bool tag;
	}f[N<<4];
	int node_cnt;
	inline void PushUp(const int &x)
	{
		f[x].tot=f[f[x].ls].tot+f[f[x].rs].tot-(f[f[x].ls].r_col&&f[f[x].rs].l_col);
		f[x].l_col=f[f[x].ls].l_col;
		f[x].r_col=f[f[x].rs].r_col;
	}
	inline void cover(const int &x)
	{
		f[x].l_col=f[x].r_col=1;
		f[x].tot=1;
		f[x].tag=1;
	}
	inline void PushDown(const int &x)
	{
		if(f[x].tag)
		{
			cover(f[x].ls);
			cover(f[x].rs);
			f[x].tag=0;
		}
	}
	int build(const int &l,const int &r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(const int &L,const int &R,const int &l,const int &r,const int &cur)
	{
		if(L<=l&&r<=R)
		{
			cover(cur);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(cur);
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
}tr;
int x[N],y[N];
int t[N<<1],pos;
int main()
{
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x[i]);
		read(y[i]);
		t[++pos]=x[i];
		t[++pos]=y[i];
	}
	std::sort(t+1,t+pos+1);
	int len=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		x[i]=std::lower_bound(t+1,t+len+1,x[i])-t;
		y[i]=std::lower_bound(t+1,t+len+1,y[i])-t;
		x[i]<<=1;
		y[i]<<=1;
	}
	len<<=1;
	int root=tr.build(1,len);
	for(int i=1;i<=n;++i)
	{
		tr.Update(x[i],y[i],1,len,root);
		tr.PushDown(root);
		tr.PushUp(root);
		printf("%d\n",tr.f[root].tot);
	}
	return 0;
}