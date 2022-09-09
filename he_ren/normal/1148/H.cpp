#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

struct RMQ
{
	int mn[MAXN<<2], n;
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	void update(int u,int l,int r,int q,int k)
	{
		if(l == r){ mn[u] = k; return;}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
		push_up(u);
	}
	int get_fir(int u,int l,int r,int k)
	{
		if(l == r) return l;
		int mid = (l+r)>>1;
		return mn[ls(u)] <= k? get_fir(lson(u),k): get_fir(rson(u),k);
	}
	
	inline void update(int q,int k){ update(1,0,n,q,k);}
	inline int get_fir(int k){ return mn[1] <= k? get_fir(1,0,n,k): inf;}
	#undef ls
	#undef rs
	#undef lson
	#undef rson
}rmq;

namespace SegT
{
	struct Data
	{
		ll a,b;
		Data(void){}
		Data(ll _a,int _b): a(_a), b(_b) {}
	};
	inline Data operator + (const Data &p,const Data &q)
	{
		return Data(p.a + q.a, p.b + q.b);
	}
	inline Data operator * (const Data &p,int k)
	{
		return Data(p.a * k, p.b * k);
	}
	inline Data& operator += (Data &p,const Data &q){ return p = p + q;}
	
	struct Node
	{
		Data sum, tag;
		Node *ls, *rs;
		Node(void){}
		Node(Node *emp): sum(0,0), tag(0,0), ls(emp), rs(emp) {}
	}*hd, *emp;
	inline void init(void)
	{
		hd = 0;
		emp = new Node();
		*emp = Node(emp);
	}
	inline Node *new_Node(void)
	{
		if(!hd)
		{
			const int SIZ = 1e7;
			hd = new Node[SIZ+1];
			for(int i=0; i<SIZ; ++i) hd[i].rs = &hd[i+1];
			hd[SIZ].rs = 0;
		}
		Node *res = hd; hd = hd -> rs;
		*res = Node(emp);
		return res;
	}
	inline Node* copy(Node *u)
	{
		Node *res = new_Node();
		*res = *u;
		return res;
	}
	
	int n;
	#define lson(u) u -> ls,l,mid
	#define rson(u) u -> rs,mid+1,r
	void update(Node *&u,int l,int r,int ql,int qr,ll k1,int k2)
	{
		u = copy(u);
		u -> sum += Data(k1, k2) * (qr - ql + 1);
		if(ql<=l && r<=qr){ u -> tag += Data(k1, k2); return;}
		int mid = (l+r)>>1;
		if(ql<=mid && mid<qr)
			update(lson(u), ql, mid, k1, k2),
			update(rson(u), mid+1, qr, k1, k2);
		else if(ql<=mid)
			update(lson(u), ql, qr, k1, k2);
		else
			update(rson(u), ql, qr, k1, k2);
	}
	
	Data query(Node *u,int l,int r,int ql,int qr)
	{
		if(u == emp) return Data(0,0);
		if(ql<=l && r<=qr) return u -> sum;
		int mid = (l+r)>>1;
		Data res = u -> tag * (qr - ql + 1);
		if(ql<=mid && mid<qr)
			return res + query(lson(u),ql,mid) + query(rson(u),mid+1,qr);
		else
			return res + (ql<=mid? query(lson(u),ql,qr): query(rson(u),ql,qr));
	}
	
	inline void update(Node *&u,int ql,int qr,ll k1,int k2){ if(ql<=qr) update(u,1,n,ql,qr,k1,k2);}
	inline Data query(Node *u,int ql,int qr){ return ql<=qr? query(u,1,n,ql,qr): Data(0,0);}
	#undef lson
	#undef rson
} using SegT::Data; using SegT::Node;

struct Counter_2D
{
	vector<int> tim;
	vector<Node*> rt;
	inline void init(void)
	{
		tim.push_back(0);
		rt.push_back(SegT::emp);
	}
	inline void update(int x,int yl,int yr,ll k)
	{
		if(tim.back() != x)
		{
			tim.push_back(x);
			rt.push_back(rt.back());
		}
		int siz = (int)tim.size();
		SegT::update(rt[siz-1], yl, yr, (-x+1) * k, k);
	}
	inline ll query(int x,int yl,int yr)
	{
		int pos = upper_bound(tim.begin(), tim.end(), x) - tim.begin() - 1;
		Data res = SegT::query(rt[pos], yl, yr);
		return res.a + (ll)res.b * x;
	}
	inline ll query(int xl,int xr,int yl,int yr)
	{
		if(xl > xr || yl > yr) return 0;
		return query(xr,yl,yr) - query(xl-1,yl,yr);
	}
}dat[MAXN];

int curpos;
int f[MAXN];

set<int> premn;
typedef set<int>::iterator Iter;

inline void update_seg(Iter it,int k)
{
	int x = *it;
	int l = f[x] + 1, r;
	if(x) r = f[*(--it)];
	else r = curpos;
	dat[x].update(curpos, l, r, k);
}

int main(void)
{	
	int n;
	scanf("%d",&n);
	
	premn.insert(0);
	
	rmq.n = n + 1;
	SegT::n = n;
	SegT::init();
	for(int i=0; i<=n+1; ++i) dat[i].init();
	
	ll ans = 0;
	for(curpos=1; curpos<=n; ++curpos)
	{
		int x,ql,qr,qk;
		scanf("%d%d%d%d",&x,&ql,&qr,&qk);
		x = (x + ans) % (n + 1);
		ql = (ql + ans) % curpos + 1;
		qr = (qr + ans) % curpos + 1;
		qk = (qk + ans) % (n + 1);
		if(ql > qr) swap(ql, qr);
		
		dat[0].update(curpos, curpos, curpos, 1);
		
		Iter it = premn.find(x);
		if(it != premn.end())
		{
			update_seg(it, -1);
			++it;
			if(it != premn.end())
				update_seg(it, -1);
			--it;
			
			f[x] = curpos; rmq.update(x, curpos);
			
			int val;
			if(x != 0) premn.erase(it--), val = f[*it] - 1;
			else premn.erase(it), val = f[0];
			
			while(1)
			{
				int i = rmq.get_fir(val);
				pair<Iter,bool> tmp = premn.insert(i);
				update_seg(tmp.first, 1);
				val = f[i] - 1;
				if(tmp.second == 0 || f[i] == 0) break;
			}
		}
		else f[x] = curpos, rmq.update(x, curpos);
		
		ans = dat[qk].query(ql, qr, ql, qr);
		printf("%lld\n",ans);
	}
	return 0;
}