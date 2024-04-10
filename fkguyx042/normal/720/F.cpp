#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>
#include<queue>

#define ls tree[t].l
#define rs tree[t].r
#define Ls tree[t1].l
#define Rs tree[t1].r
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 10000005
#define seed 23333

using namespace std;
priority_queue<pair<long long,pair<int,int> > >Q;
int i,j,m,n,p,bl[N],id[N],root[N],tot,last_r[N],Min[N],f[N];
long long a[N],k,G,ans,Ans,b[N];
const long long inf=(long long)1e15;
struct Segment{
	int l,r;
}seg[N];
inline int cmp(int A,int b)
{
		if (a[A]!=a[b])
		return a[A]<a[b];
		return A<b;
}
struct Node{
	int sum,l,r;
	long long tot;
}tree[M];
void update(int ll,int l,int r,int t,int t1)
{
		if (l==r) 
		{
				tree[t].sum=1;
				tree[t].tot=a[id[ll]];
		}
		else 
		{
				if (ll<=mid)
				{
					  ls=++tot;
					  tree[ls]=tree[Ls];
					  update(ll,l,mid,ls,Ls);	
				}
				else 
				{
					  rs=++tot;
					  tree[rs]=tree[Rs];
					  update(ll,mid+1,r,rs,Rs);
				}
				tree[t].sum=tree[ls].sum+tree[rs].sum;
				tree[t].tot=tree[ls].tot+tree[rs].tot;
		}
}
void build()
{
	for (i=1;i<=n;++i)
	{
			root[i]=++tot;
			tree[root[i]]=tree[root[i-1]];
			update(bl[i-1],0,n,root[i],root[i-1]);
	}
}
int Upper_bound(long long x)
{
	 int l=0,r=n+1,Mid=1000000;
	 while ((l+r)>>1!=Mid)
	 {
	 		Mid=(l+r)>>1;
	 		if (a[id[Mid]]>x) r=Mid;
	 		else l=Mid;
	 }
	 return r;
}
int ask(int ll,int rr,int l,int r,int t)
{
	 if (ll>rr) return 0;
	 if (ll<=l&&r<=rr) return tree[t].sum;
	 else 
	 {	
	 		int S=0;
	 		if (ll<=mid) S+=ask(ll,rr,l,mid,ls);
	 		if (rr>mid)  S+=ask(ll,rr,mid+1,r,rs);
	 		return S;
	 }
}
long long check(long long x)
{
	 long long s=0;
	 for (i=1;i<=n;++i)
	 {
	 		int y=Upper_bound(a[i]-x);
	 		if (y==0) continue;
	 		s+=ask(0,y-1,0,n,root[i]);
	 }
	 return s;
}
long long getsum(long long x)
{
	long long l=-inf,r=inf,Mid=inf;
	while ((l+r)>>1!=Mid)
	{
		  Mid=(l+r)>>1;
		  if (check(Mid)>=x) l=Mid;
		  else r=Mid; 
	}
	return l;
}
long long Find(int &x,int ll,int rr,int l,int r,int t)
{
			if (ll>rr||!G) return 0;
			if (ll<=l&&r<=rr)
			{
					if (G>=tree[t].sum) 
					{
						G-=tree[t].sum;
						x=r;
						return tree[t].tot;
					}
					else 
					{
						return Find(x,ll,rr,l,mid,ls)+Find(x,ll,rr,mid+1,r,rs);
					}
			}
			else 
			{
					long long S=0;
					if (ll<=mid) S+=Find(x,ll,rr,l,mid,ls);
					if (rr>mid)  S+=Find(x,ll,rr,mid+1,r,rs);
					return S;
			}
}
int Got(int ll,int rr,int l,int r,int t)
{
		if (ll>rr) return n+1;
		if (!tree[t].sum) return n+1;
		if (l==r) return l;
		if (ll<=l&&r<=rr)
		{
				if (tree[ls].sum) return Got(ll,rr,l,mid,ls);
				return Got(ll,rr,mid+1,r,rs); 
		}
		int S;
		if (ll<=mid)
		{
			 S=Got(ll,rr,l,mid,ls);
			 if (S<n+1) return S;	
		}
		if (rr>mid)
		{
			 S=Got(ll,rr,mid+1,r,rs);
			 if (S<n+1) return S;
		}
		return n+1; 
}
#undef ls
#undef rs

//another segment_tree
#define ls tree[t].l
#define rs tree[t].r
void change_kth(long long ll,long long c,long long l,long long r,int t)
{
		if (l==r) 
		{
				tree[t].sum+=c;
				tree[t].tot+=c*ll;
		}
		else 
		{
				if (ll<=mid)
				{
						if (!ls) ls=++tot;
						change_kth(ll,c,l,mid,ls);
				}
				else
				{
						if (!rs) rs=++tot;
						change_kth(ll,c,mid+1,r,rs); 
				}
				tree[t].sum+=c;
				tree[t].tot+=c*ll;
		}
}
long long used_kth(int p,long long l,long long r,int t)
{
		if (l==r) return p*l;
		else 
		{
				if (tree[rs].sum>=p) return used_kth(p,mid+1,r,rs);
				return used_kth(p-tree[rs].sum,l,mid,ls)+tree[rs].tot;
		}
}
#undef ls
#undef rs
//

#define ls (t<<1)
#define rs ((t<<1)|1)
// max_segment tree
struct Max_seg{
		long long l_max,r_max,sum;
}tr[N*4],pts;
void up(Max_seg &a,Max_seg b,Max_seg c)
{
	a.sum=b.sum+c.sum;
	a.l_max=max(b.l_max,b.sum+c.l_max);
	a.r_max=max(c.r_max,c.sum+b.r_max);
}
void seg_ask(int ll,int rr,int l,int r,int t)
{
		if (ll>rr) return;
		if (ll<=l&&r<=rr) up(pts,pts,tr[t]);
		else 
		{
				if (ll<=mid) seg_ask(ll,rr,l,mid,ls);
				if (rr>mid)  seg_ask(ll,rr,mid+1,r,rs);
		}
}
void build_tree(int l,int r,int t)
{
		if (l==r) 
		{
			tr[t].l_max=max(0ll,b[l]);
			tr[t].r_max=max(0ll,b[l]);
			tr[t].sum=b[l];
		}
		else 
		{
			build_tree(l,mid,ls); build_tree(mid+1,r,rs);
			up(tr[t],tr[ls],tr[rs]);
		}
}
set<int>st;
void Ins(int x)
{
		ans+=b[x];
		st.insert(x);
		set<int>::iterator it=st.lower_bound(x);
		--it;
		int l=*it;
		++it; ++it;
		int r=*it;
		--it;
		if (l!=0||r!=n+1)
		{
				pts=(Max_seg){0,0,0};
				seg_ask(l+1,r-1,1,n,1);
				if (l==0)	ans-=pts.r_max;
				else if (r==n+1) ans-=pts.l_max;
				else ans-=pts.l_max+pts.r_max,change_kth(a[r-1]-a[l]-(pts.l_max+pts.r_max),-1,-inf,inf,1);
		}
		//work l
		{
				pts=(Max_seg){0,0,0};
				seg_ask(l+1,x-1,1,n,1);
				if (l==0) ans+=pts.r_max;
				else ans+=pts.l_max+pts.r_max,change_kth(a[x-1]-a[l]-(pts.l_max+pts.r_max),1,-inf,inf,1);				
		}
		//work r
		{
				pts=(Max_seg){0,0,0};
				seg_ask(x+1,r-1,1,n,1);
				if (r==n+1) ans+=pts.l_max;
				else ans+=pts.l_max+pts.r_max,change_kth(a[r-1]-a[x]-(pts.l_max+pts.r_max),1,-inf,inf,1);				
		}
}
void Del(int x)
{
		ans-=b[x];
		set<int>::iterator it=st.lower_bound(x);
		--it;
		int l=*it;
		++it; ++it;
		int r=*it;
		--it;
		if (l!=0||r!=n+1)
		{
				pts=(Max_seg){0,0,0};
				seg_ask(l+1,r-1,1,n,1);
				if (l==0)	ans+=pts.r_max;
				else if (r==n+1) ans+=pts.l_max;
				else ans+=pts.l_max+pts.r_max,change_kth(a[r-1]-a[l]-(pts.l_max+pts.r_max),1,-inf,inf,1);
		}
		//work l
		{
				pts=(Max_seg){0,0,0};
				seg_ask(l+1,x-1,1,n,1);
				if (l==0) ans-=pts.r_max;
				else ans-=pts.l_max+pts.r_max,change_kth(a[x-1]-a[l]-(pts.l_max+pts.r_max),-1,-inf,inf,1);				
		}
		//work r
		{
				pts=(Max_seg){0,0,0};
				seg_ask(x+1,r-1,1,n,1);
				if (r==n+1) ans-=pts.l_max;
				else ans-=pts.l_max+pts.r_max,change_kth(a[r-1]-a[x]-(pts.l_max+pts.r_max),-1,-inf,inf,1);				
		}
		st.erase(x);
}
void del(int l,int r)
{
		for (;;)
		{
				set<int>::iterator it=st.lower_bound(l);
				if (*it>r) return;
				Del(*it); 
		}
}
//
void clear()
{
		int i;
		for (i=1;i<=tot;++i) tree[i].sum=tree[i].l=tree[i].r=tree[i].tot=0;
		tot=1;
}
int main()
{
		scanf("%d%I64d",&n,&k);
		for (i=1;i<=n;++i) scanf("%I64d",&a[i]),b[i]=a[i],a[i]+=a[i-1],id[i]=i;
		sort(id,id+n+1,cmp);
		Min[0]=id[0];
		for (i=1;i<=n;++i) Min[i]=min(Min[i-1],id[i]);
		for (i=0;i<=n;++i) bl[id[i]]=i;
		build();
		long long last=getsum(k-n);
		G=k-n;
		memset(last_r,-1,sizeof(last_r));
		for (i=1;i<=n&&G>0;++i)
		{
				long long L=G;
				int x=Upper_bound(a[i]-last-1);
				if (!x) continue;
				ans-=Find(last_r[i],0,x-1,0,n,root[i]);
				ans+=(L-G)*a[i];
		}
		for (i=1;i<=n&&G>0;++i)
		{
				long long L=G;
				int x=Upper_bound(a[i]-last),y=Upper_bound(a[i]-last-1);
				if (y==x) continue;
				ans-=Find(last_r[i],y,x-1,0,n,root[i]);
				ans+=(L-G)*a[i];
		}
		for (i=1;i<=n;++i) 
		{
				int x=Got(last_r[i]+1,n,0,n,root[i]);
				if (x>n) continue;
				Q.push(mk(a[i]-a[id[x]],mk(i,x))); 
		}
		for (i=1;i<=n;++i)
		{
			pair<long long,pair<int,int> > x=Q.top(); Q.pop();
			seg[i]=(Segment){id[x.se.se]+1,x.se.fi};
			int y=Got(x.se.se+1,n,0,n,root[x.se.fi]);
			if (y>n) continue;
			Q.push(mk(a[x.se.fi]-a[id[y]],mk(x.se.fi,y)));
		}
		for (i=1;i<=n;++i)
		{
				if (last_r[i]==-1) continue;
				if (Min[last_r[i]]>=i) continue;
				f[Min[last_r[i]]+1]++; f[i+1]--;
		}
		clear();
		build_tree(1,n,1);
		for (i=1;i<=n;++i) f[i]+=f[i-1]; 
		st.insert(0); st.insert(n+1);
		for (i=1;i<=n;++i) 
			if (!f[i]) Ins(i);
		Ans=-8333583335000000001;
		for (i=0;i<=min((long long)n,k);++i) 
		{
			int used=min((long long)n,k)-i;
			if (used>(int)st.size()-2) 
			{
				if (i<n)
				del(seg[i+1].l,seg[i+1].r),
				ans+=a[seg[i+1].r]-a[seg[i+1].l-1];
				continue;
			} 
			if (used==0&&st.size()>2) 
			{
				if (i<n)
				del(seg[i+1].l,seg[i+1].r),
				ans+=a[seg[i+1].r]-a[seg[i+1].l-1];
				continue;
			} 
			Ans=max(Ans,ans+used_kth((int)st.size()-2-used,-inf,inf,1));
			if (i<n)
			del(seg[i+1].l,seg[i+1].r),
			ans+=a[seg[i+1].r]-a[seg[i+1].l-1];
		}
		printf("%I64d\n",Ans);
}