#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXQ = 1e5 + 5;

inline int rnd(void){ return (rand()<<15) | rand();}

struct Treap
{
	struct Node
	{
		int val,siz,fix;
		Node *son[2];
		ll sum[5];
		Node(){}
		Node(int val_): val(val_), siz(1), fix(rnd()), son(), sum() { sum[1] = val;}
	}*emp, *root;
	Treap(void): emp(new Node(0)), root(emp) { emp -> siz = 0;}
	Node* new_Node(int val = 0){ Node *res = new Node(val); res -> son[0] = res -> son[1] = emp; return res;}
	inline void push_up(Node *u)
	{
		Node *l = u -> son[0], *r = u -> son[1];
		u -> siz = l -> siz + r -> siz + 1;
		for(int i=0; i<5; ++i) u -> sum[i] = l -> sum[i];
		for(int i=0; i<5; ++i) u -> sum[(l -> siz + 1 + i)%5] += r -> sum[i];
		u -> sum[(l -> siz + 1)%5] += u -> val;
	}
	void split(Node *u,Node *&l,Node *&r,int val)
	{
		if(!u -> val){ l = r = emp; return;}
		if(u -> val <= val) l = u, split(u -> son[1], l -> son[1], r, val);
		else r = u, split(u -> son[0], l, r -> son[0], val);
		if(l -> val) push_up(l);
		if(r -> val) push_up(r);
	}
	inline void split(Node *&l,Node *&r,int val){ split(root, l, r, val);}
	void merge(Node *&u,Node *l,Node *r)
	{
		if(!l -> val){ u = r; return;}
		if(!r -> val){ u = l; return;}
		if(l -> fix < r -> fix) u = l, merge(u -> son[1], l -> son[1], r);
		else u = r, merge(u -> son[0], l, r -> son[0]);
		push_up(u);
	}
	inline void merge(Node *l,Node *r){ merge(root, l, r);}
	inline ll query(void){ return root -> sum[3];}
}tree;

int main(void)
{
	srand((unsigned long long)new char);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		static char s[10];
		scanf("%s",s+1);
		if(s[1] == 's') printf("%lld\n",tree.query());
		else
		{
			int x;
			scanf("%d",&x);
			if(s[1] == 'a')
			{
				Treap::Node *l,*r,*mid;
				tree.split(l, r, x);
				mid = tree.new_Node(x);
				tree.merge(l, l, mid);
				tree.merge(l, r);
			}
			else
			{
				Treap::Node *l,*r,*mid;
				tree.split(l, r, x);
				tree.split(l, l, mid, x-1);
				tree.merge(l, r);
				delete mid;
			}
		}
	}
	return 0;
}