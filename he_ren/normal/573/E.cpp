#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

mt19937 rnd((unsigned long long)new char ^ time(0));

struct Node
{
	Node *ls, *rs;
	int fix, siz;
	ll diff, tag;
	Node(void){}
	Node(Node *emp,ll _diff): ls(emp), rs(emp), fix(rnd()), siz(1), diff(_diff), tag(0) {}
}pool[MAXN];
Node *emp = pool, *curpool = pool;
void init(void)
{
	*emp = Node(emp, 0); emp -> siz = 0;
}
Node* new_Node(ll diff){ return &(*++curpool = Node(emp, diff));}
void push_up(Node *u){ u -> siz = u -> ls -> siz + u -> rs -> siz + 1;}
void upd(Node *u,ll k)
{
	if(u == emp) return;
	u -> diff += k; u -> tag += k;
}
void push_down(Node *u)
{
	if(u -> tag)
	{
		upd(u -> ls, u -> tag); upd(u -> rs, u -> tag);
		u -> tag = 0;
	}
}
void merge(Node *&u,Node *l,Node *r)
{
	if(l == emp){ u = r; return;}
	if(r == emp){ u = l; return;}
	push_down(l); push_down(r);
	if(l -> fix > r -> fix)
		u = l, merge(u -> rs, l -> rs, r);
	else
		u = r, merge(u -> ls, l, r -> ls);
	push_up(u);
}
void split_siz(Node *u,Node *&l,Node *&r,int k)
{
	if(u == emp){ l = r = emp; return;}
	push_down(u);
	if(u -> ls -> siz < k)
		l = u, split_siz(u -> rs, l -> rs, r, k - u -> ls -> siz - 1), push_up(l);
	else
		r = u, split_siz(u -> ls, l, r -> ls, k), push_up(r);
}
int search(Node *u,int pre,ll k)
{
	if(u == emp) return pre + 1;
	push_down(u);
	if((pre + u -> ls -> siz + 1) * k > u -> diff)
		return search(u -> ls, pre, k);
	else
		return search(u -> rs, pre + u -> ls -> siz + 1, k);
}
ll* flat(Node *u,ll *a)
{
	if(u == emp) return a;
	push_down(u);
	a = flat(u -> ls, a) + 1;
	*a = u -> diff;
	return flat(u -> rs, a);
}

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	init();
	Node *rt = emp;
	for(int i=1; i<=n; ++i)
	{
		int pos = search(rt, 0, a[i]);
		Node *l, *r;
		split_siz(rt, l, r, pos-1);
		upd(r, a[i]);
		merge(rt, l, new_Node((ll)a[i] * pos));
		merge(rt, rt, r);
	}
	
	static ll diff[MAXN];
	flat(rt, diff);
	
	ll ans = 0, cur = 0;
	for(int i=1; i<=n; ++i)
		cur += diff[i],
		ans = max(ans, cur);
	printf("%lld",ans);
	return 0;
}