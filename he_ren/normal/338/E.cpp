#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e5 + 5;
const int MAXM = 1.5e5 + 5;
const int inf = 0x3f3f3f3f;

struct Treap
{
	struct Node
	{
		int val,sum,mx,tag,fix;
		Node *ls,*rs;
		Node(void){}
		Node(int _val,int _sum,Node *emp): val(_val), sum(_sum), mx(_sum), tag(0), fix(rand()), ls(emp), rs(emp) {}
	}*emp, *rt, *list;
	Treap(void): emp(new Node(0,-inf,0)), rt(emp) { emp -> fix = -1;}
	inline Node *new_Node(int val,int sum)
	{
		if(!list)
		{
			static const int SZ = 1e4;
			list = new Node[SZ+1];
			for(int i=0; i<SZ; ++i)
				(list+i) -> rs = list+i+1;
			(list + SZ) -> rs = 0;
		}
		Node *res = list;
		list = list -> rs;
		res -> val = val; res -> sum = res -> mx = sum; res -> tag = 0;
		res -> fix = rand(); res -> ls = res -> rs = emp;
		return res;
	}
	inline void del_Node(Node *&u,Node *to){ u -> rs = list; list = u; u = to;}
	
	inline void push_up(Node *u){ u -> mx = max(u -> sum, max(u -> ls -> mx, u -> rs -> mx));}
	inline void upd(Node *u,int k){ u -> tag += k; u -> sum += k; u -> mx += k;}
	inline void push_down(Node *u)
	{
		if(u -> tag)
		{
			if(~u -> ls -> fix) upd(u -> ls, u -> tag);
			if(~u -> rs -> fix) upd(u -> rs, u -> tag);
			u -> tag = 0;
		}
	}
	void split(Node *u,Node *&l,Node *&r,int k)
	{
		if(u -> fix == -1){ l = r = emp; return;}
		push_down(u);
		if(u -> val <= k) l = u, split(u -> rs, l -> rs, r, k);
		else r = u, split(u -> ls, l, r -> ls, k);
		if(~l -> fix) push_up(l);
		if(~r -> fix) push_up(r);
	}
	void merge(Node *&u,Node *l,Node *r)
	{
		if(l -> fix == -1){ u = r; return;}
		if(r -> fix == -1){ u = l; return;}
		push_down(l); push_down(r);
		if(l -> fix < r -> fix) u = l, merge(u -> rs, l -> rs, r);
		else u = r, merge(u -> ls, l, r -> ls);
		push_up(u);
	}
	inline int getr(Node *u)
	{
		if(u -> fix == -1) return 0;
		while(~u -> rs -> fix) push_down(u), u = u -> rs;
		return u -> sum;
	}
	
	inline void insert(int x,int k)
	{
		int val = x * 2 + (k == 1);
		Node *l,*r;
		split(rt,l,r,val);
		Node *u = new_Node(val,getr(l)+k);
		upd(r,k);
		merge(rt,l,u); merge(rt,rt,r);
	}
	inline void erase(int x,int k)
	{
		int val = x * 2 + (k == 1);
		Node *l,*mid,*r;
		split(rt,l,r,val); split(l,l,mid,val-1);
		push_down(mid);
		Node *ml = mid -> ls, *mr = mid -> rs;
		merge(l,l,ml); merge(r,mr,r); del_Node(mid,0);
		upd(r,-k);
		merge(rt,l,r);
	}
	inline int query(void){ return rt -> mx;}
}tree;

int a[MAXN], b[MAXM];

int main(void)
{
	srand((unsigned long long)new char);
	
	int n,m,h;
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=m; ++i)
		tree.insert(h - b[i], -1);
	
	int ans = 0;
	for(int i=1; i<m; ++i) tree.insert(a[i], 1);
	for(int i=1; i+m-1 <= n; ++i)
	{
		tree.insert(a[i+m-1], 1);
		if(tree.query() <= 0) ++ans;
		tree.erase(a[i], 1);
	}
	printf("%d",ans);
	return 0;
}