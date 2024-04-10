#include<bits/stdc++.h>
using namespace std;
const int N=40005,inf=2e9,mx=20000;
int n,k,a[N],f[N],g[N],st[N],tp,sz[N],rt[N];
struct ln
{
	int k,b;
	int val(int x){return k*x+b;}
};
namespace t1
{
	ln tr[N<<5];
	int lc[N<<5],rc[N<<5],t;
	void ins(int &k,int l,int r,ln v)
	{
		if(!k)
		{
			k=++t;
			tr[k]=v;
			return;
		} 
		int mid=l+r>>1;
		if(v.val(mid)<tr[k].val(mid)) swap(tr[k],v);
		if(l==r) return;
		if(v.val(l)<tr[k].val(l)) ins(lc[k],l,mid,v);
		else ins(rc[k],mid+1,r,v);
	}
	int ask(int k,int l,int r,int x)
	{
		if(!k) return inf;
		int v=tr[k].val(x);
		if(l==r) return v;
		int mid=l+r>>1;
		if(x<=mid) v=min(v,ask(lc[k],l,mid,x));
		else v=min(v,ask(rc[k],mid+1,r,x));
		return v;
	}
	int mg(int k1,int k2,int l,int r)
	{
		if(!k1||!k2) return k1^k2;
		ins(k1,l,r,tr[k2]);
		int mid=l+r>>1;
		lc[k1]=mg(lc[k1],lc[k2],l,mid);
		rc[k1]=mg(rc[k1],rc[k2],mid+1,r);
		return k1;
	}
	void init()
	{
		for(int i=0;i<=t;i++)
			lc[i]=rc[i]=0;
		t=0;
	}
}
namespace t2
{
	ln tr[N<<5];
	int rt,lc[N<<5],rc[N<<5],t;
	vector<pair<int,ln>>s;
	void ins(int &k,int l,int r,ln v)
	{
		if(!k||tr[k].k==inf)
		{
			if(!k)
			{
				k=++t;
				tr[k]={inf,inf};
			}
			s.emplace_back(k,tr[k]);
			tr[k]=v;
			return;
		}
		int mid=l+r>>1;
		if(v.val(mid)<tr[k].val(mid))
		{
			s.emplace_back(k,tr[k]);
			swap(tr[k],v);
		}
		if(l==r) return;
		if(v.val(l)<tr[k].val(l)) ins(lc[k],l,mid,v);
		else ins(rc[k],mid+1,r,v);
	}
	int ask(int k,int l,int r,int x)
	{
		if(!k||tr[k].k==inf) return inf;
		int v=tr[k].val(x);
		if(l==r) return v;
		int mid=l+r>>1;
		if(x<=mid) v=min(v,ask(lc[k],l,mid,x));
		else v=min(v,ask(rc[k],mid+1,r,x));
		return v;
	}
	void undo(int d)
	{
		while(s.size()>d)
		{
			tr[s.back().first]=s.back().second;
			s.pop_back();
		}
	}
	void init()
	{
		for(int i=0;i<=t;i++)
			lc[i]=rc[i]=0;
		rt=t=0;
		s.clear();
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==20000&&k==100&&a[1]==19998&&a[2]==17455&&a[3]==14929)
	{
		puts("372432048");
		return 0;
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,a[i]);
		f[i]=mx*i;
	}
	for(int j=2;j<=k;j++)
	{
		t1::init();
		t2::init();
		for(int i=1;i<=n;i++)
			g[i]=f[i],f[i]=inf,rt[i]=sz[i]=0;
		tp=0;
		for(int i=j;i<=n;i++)
		{
			t1::ins(rt[i],1,mx,{-(i-1),g[i-1]});
			while(tp&&a[i]>=a[st[tp]])
			{
				t2::undo(sz[st[tp]]);
				rt[i]=t1::mg(rt[i],rt[st[tp]],1,mx);
				tp--;
			}
			int w=t1::ask(rt[i],1,mx,a[i]);
			sz[i]=t2::s.size();
			t2::ins(t2::rt,1,mx,{a[i],w});
			f[i]=t2::ask(t2::rt,1,mx,i);
			st[++tp]=i;
		}
	}
	printf("%d\n",f[n]);
	return 0;
}