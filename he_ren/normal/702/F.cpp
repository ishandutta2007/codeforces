#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

inline int rnd(void){ return (rand()<<15) | rand();}

namespace Treap
{
	struct Node
	{
		Node *ls,*rs;
		int fix, val, cnt, tag_val, tag_cnt;
		Node(void){}
		Node(int _val,Node *emp): ls(emp), rs(emp), fix(rnd()), val(_val), cnt(0), tag_val(0), tag_cnt(0) {};
	}p[MAXM], *rt, *emp;
	int pcnt = 0;
	inline void init(void)
	{
		rt = emp = &p[0];
		*emp = Node(0,emp);
	}
	inline Node* new_Node(int val){ return &(p[++pcnt] = Node(val, emp));}
	
	inline void upd(Node *u,int k1,int k2)
	{
		if(u != emp)
		{
			u -> val += k1; u -> cnt += k2;
			u -> tag_val += k1; u -> tag_cnt += k2;
		}
	}
	inline void push_down(Node *u)
	{
		upd(u -> ls, u -> tag_val, u -> tag_cnt);
		upd(u -> rs, u -> tag_val, u -> tag_cnt);
		u -> tag_val = u -> tag_cnt = 0;
	}
	inline void push_down_all(Node *u)
	{
		if(u == emp) return;
		push_down(u);
		push_down_all(u -> ls); push_down_all(u -> rs);
	}
	
	void split_val(Node *u,Node *&l,Node *&r,int k)
	{
		if(u == emp){ l = r = emp; return;}
		push_down(u);
		if(u -> val <= k) l = u, split_val(u -> rs, l -> rs, r, k);
		else r = u, split_val(u -> ls, l, r -> ls, k);
	}
	void merge(Node *&u,Node *l,Node *r)
	{
		if(l == emp){ u = r; return;}
		if(r == emp){ u = l; return;}
		push_down(l); push_down(r);
		if(l -> fix < r -> fix) u = l, merge(u -> rs, l -> rs, r);
		else u = r, merge(u -> ls, l, r -> ls);
	}
	
	inline Node* insert(Node *u)
	{
		Node *l, *r;
		split_val(rt, l, r, u -> val);
		merge(rt, l, u); merge(rt, rt, r);
		return u;
	}
	inline Node* insert(int k){ return insert(new_Node(k));}
	void insert_all(Node *&u)
	{
		if(u == emp) return;
		push_down(u);
		insert_all(u -> ls); insert_all(u -> rs);
		insert(u); u = emp;
	}
	
	inline void update(int k)
	{
		Node *l, *mid, *r;
		split_val(rt, l, r, k * 2); split_val(l, l, mid, k-1);
		upd(mid, -k, 1); upd(r, -k, 1);
		merge(rt, l, r);
		insert_all(mid);
	}
} using namespace Treap;

pii a[MAXN];
int b[MAXM];
Node *pt[MAXM];

int main(void)
{	
	srand((unsigned long long)new char ^ time(0));
	
	int n, m;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i] = {-y, x};
	}
	sort(a+1,a+n+1);
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	Treap::init();
	for(int i=1; i<=m; ++i) pt[i] = insert(b[i]);
	for(int i=1; i<=n; ++i) update(a[i].second);
	
	Treap::push_down_all(rt);
	
	for(int i=1; i<=m; ++i) printf("%d ",pt[i] -> cnt);
	return 0;
}