#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2.5e5 + 5;
const int MAXM = 5e5 + 5;

namespace LCT
{
	struct Node
	{
		Node *fa;
		union{ Node *son[2]; struct{ Node *ls,*rs;};};
		bool rev_tag;
		int vtag, val, mx; 
		Node(void){}
		Node(Node *emp,int _val): fa(emp), ls(emp), rs(emp), rev_tag(0), vtag(-1), val(_val), mx(_val) {}
	}*emp = new Node(emp,-1), *hd = 0;
	
	inline Node* new_Node(int val)
	{
		if(!hd)
		{
			static const int SIZ = MAXN + MAXM;
			hd = new Node[SIZ+1];
			for(int i=0; i<SIZ; ++i) (hd + i) -> rs = hd + i + 1;
			(hd + SIZ) -> rs = 0;
		}
		Node *res = hd; hd = hd -> rs;
		*res = Node(emp,val);
		return res;
	}
	
	inline bool is_root(Node *u){ return u -> fa == emp || (u -> fa -> ls != u && u -> fa -> rs != u);}
	inline int get_ch(Node *u){ return u -> fa -> rs == u;}
	
	inline void upd_rev(Node *u)
	{
		u -> rev_tag ^= 1;
		swap(u -> ls, u -> rs);
	}
	inline void upd_v(Node *u,int k)
	{
		if(u -> mx != -1)
		{
			if(u -> val != -1) u -> val = k;
			u -> vtag = u -> mx = k;
		}
	}
	inline void push_up(Node *u)
	{
		u -> mx = max(max(u -> ls -> mx, u -> rs -> mx), u -> val);
	}
	inline void push_down(Node *u)
	{
		if(u -> rev_tag)
		{
			upd_rev(u -> ls); upd_rev(u -> rs);
			u -> rev_tag = 0;
		}
		if(u -> vtag != -1)
		{
			upd_v(u -> ls, u -> vtag); upd_v(u -> rs, u -> vtag);
			u -> vtag = -1;
		}
	}
	
	inline void rotate(Node *u)
	{
		Node *v = u -> fa, *w = v -> fa;
		int k = get_ch(u);
		if(!is_root(v)) w -> son[get_ch(v)] = u;
		
		v -> son[k] = u -> son[!k]; u -> son[!k] -> fa = v;
		u -> son[!k] = v; v -> fa = u; u -> fa = w;
		push_up(v); push_up(u);
	}
	inline void push_down_all(Node *u)
	{
		if(!is_root(u)) push_down_all(u -> fa);
		push_down(u);
	}
	inline void splay(Node *u)
	{
		push_down_all(u);
		for(Node *v; v = u -> fa, !is_root(u); rotate(u))
			if(!is_root(v)) rotate(get_ch(v) == get_ch(u)? v: u);
	}
	
	inline Node* access(Node *u)
	{
		Node *pre = emp;
		for(; u != emp; pre = u, u = u -> fa)
			splay(u), u -> rs = pre, push_up(u);
		return pre;
	}
	inline void make_root(Node *u){ upd_rev(access(u));}
	
	inline Node* find(Node *u)
	{
		access(u); splay(u); push_down(u);
		while(u -> ls != emp) u = u -> ls, push_down(u);
		splay(u); return u;
	}
	
	inline void link(Node *u,Node *v)
	{
		make_root(u); splay(u);
		u -> fa = v; push_up(v);
	}
	inline void cut(Node *u,Node *v)
	{
		make_root(u); access(v); splay(v);
		v -> ls = u -> fa = emp; push_up(v);
	}
	
	inline int query_mx(Node *u,Node *v)
	{
		make_root(u); access(v); splay(v);
		return v -> mx;
	}
	inline void update_val(Node *u,Node *v,int k)
	{
		make_root(u); access(v); splay(v);
		upd_v(v, k);
	}
} using namespace LCT;

int a[MAXM], b[MAXM];
Node *pn[MAXN], *pe[MAXM];

bool del[MAXM];
inline void adde(int id)
{
//	printf("add %d\n",id);
	int u = a[id], v = b[id];
	if(find(pn[u]) != find(pn[v]))
	{
		link(pe[id], pn[u]);
		link(pe[id], pn[v]);
		del[id] = 0;
	}
	else
	{
		update_val(pn[u], pn[v], id);
		del[id] = 1;
	}
//	printf("ok\n");
}

inline void dele(int id)
{
//	printf("del %d\n",id);
	int u = a[id], v = b[id];
	if(del[id])
	{
		assert(query_mx(pn[u], pn[v]) == id);
		update_val(pn[u], pn[v], 0);
	}
	else
	{
		int oth = query_mx(pn[u], pn[v]);
		if(oth > 0)
		{
			cut(pn[u], pe[id]);
			cut(pn[v], pe[id]);
			
			int uu = a[oth], vv = b[oth];
			link(pn[uu], pe[oth]);
			link(pn[vv], pe[oth]);
			del[oth] = 0;
			update_val(pn[u], pn[v], 0);
		}
		else
		{
			cut(pn[u], pe[id]);
			cut(pn[v], pe[id]);
		}
	}
//	printf("ok\n");
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d%d",&a[i],&b[i]);
	
	for(int i=1; i<=n; ++i) pn[i] = new_Node(-1);
	for(int i=1; i<=m; ++i) pe[i] = new_Node(0);
	
	ll ans = 0;
	for(int r=1,l=1; r<=m; ++r)
	{
		int u = a[r], v = b[r];
		while(l < r && find(pn[u]) == find(pn[v]) && query_mx(pn[u], pn[v]) > 0)
			dele(l++);
		adde(r);
		ans += r - l + 1;
	}
	
	printf("%lld",ans);
	return 0;
}