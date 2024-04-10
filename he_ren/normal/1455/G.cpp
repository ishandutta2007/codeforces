#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int maxv = 2e5;
const int MAXP = MAXN * 20;
const ll linf = 0x3f3f3f3f3f3f3f3f;

namespace SegT
{
	int ls[MAXP], rs[MAXP], pcnt = 0;
	ll tag[MAXP], mn[MAXP];
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	inline void init(void)
	{
		memset(mn, 0x3f, sizeof(mn));
	}
	inline void push_up(int u)
	{
		mn[u] = min(mn[ls[u]], mn[rs[u]]);
	}
	inline void upd(int u,ll k)
	{
		if(mn[u] != linf)
		{
			mn[u] += k;
			tag[u] += k;
		}
	}
	inline void push_down(int u)
	{
		if(tag[u])
		{
			upd(ls[u], tag[u]); upd(rs[u], tag[u]);
			tag[u] = 0;
		}
	}
	void set(int &u,int l,int r,int q,ll k)
	{
		if(!u) u = ++pcnt;
		if(l == r){ mn[u] = k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(q<=mid) set(lson(u),q,k);
		else set(rson(u),q,k);
		push_up(u);
	}
	ll erase(int u,int l,int r,int q)
	{
		if(mn[u] == linf) return linf;
		if(l == r){ ll res = mn[u]; mn[u] = linf; return res;}
		push_down(u);
		int mid = (l+r)>>1;
		ll res = q<=mid? erase(lson(u),q): erase(rson(u),q);
		push_up(u);
		return res;
	}
	void merge(int &u,int l,int r,int v)
	{
		if(!u){ u = v; return;}
		if(!v) return;
		mn[u] = min(mn[u], mn[v]);
		if(l == r) return;
		push_down(u); push_down(v);
		int mid = (l+r)>>1;
		merge(lson(u),ls[v]); merge(rson(u),rs[v]);
	}
}

int main(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	
	SegT::init();
	stack<int> sta;
	
	int rt = 0;
	SegT::set(rt,0,maxv, 0, 0);
	while(n--)
	{
		static char op[10];
		scanf("%s",op);
		if(op[0] == 's')
		{
			int x, k;
			scanf("%d%d",&x,&k);
			
			ll cur = SegT::mn[rt];
			if(cur != linf)
			{
				SegT::upd(rt, k);
				if(x != s) SegT::set(rt,0,maxv, x, cur);
			}
		}
		else if(op[0] == 'i')
		{
			int x;
			scanf("%d",&x);
			
			ll cur = SegT::erase(rt,0,maxv, x);
			int nrt = 0;
			if(cur != linf) SegT::set(nrt,0,maxv, x, cur);
			sta.push(rt);
			rt = nrt;
		}
		else
		{
			SegT::merge(rt,0,maxv, sta.top());
			sta.pop();
		}
	}
	
	printf("%lld",SegT::mn[rt]);
	return 0;
}