// https://uoj.ac/submission/429221 skip2004txdy!!!

#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int inf = 1e9 + 10;
const int N = 250100;

int n, m;

inline void down(int & x, int y) {
	if(x > y) x = y;
}

struct node {
	static node* null;

	node * pa, * c[2];
	int rev, cyc;

	int add;
	int va;
	int min_a;

	inline bool eql(int A) const {
		return va == A;
	}

	inline node(int A = 0) {
		static int first = 1;
		if(first) {
			first = 0;
			null = new node;
			null -> pa = null -> c[0] = null -> c[1] = null;
		}
		pa = c[0] = c[1] = null;
		rev = cyc = 0;
		min_a = va = A;
	}
	inline int get(int p = 1) const {
		return pa -> c[p] == this;
	}
	inline int is_twist() const {
		return cyc && !c[0] -> cyc && !c[1] -> cyc;
	}
	inline int is_root() const {
		return !(get() || get(0)) || pa -> is_twist();
	}
	inline node * set(int dir, node * son) {
		return c[dir] = son, son -> pa = this;
	}
	inline node* update() {
		cyc = c[0] -> cyc || c[1] -> cyc;
		min_a = va;
		min_a += c[0] -> min_a + c[1] -> min_a;
		return this;
	}
	inline node* update_twist() {
		min_a = std::min(c[0] -> min_a, c[1] -> min_a);
		return this;
	}
	inline node* reverse() {
		std::swap(c[0], c[1]), rev ^= 1;
		return this;
	}
	inline node* pushdown() {
		if(rev) {
			c[0] -> reverse(), c[1] -> reverse();
			rev = 0;
		}
		return this;
	}
	inline node* pushdown_twist() {
		return this;
	}
	inline node* rotate() {
		node * y = pa, * z = y -> pa;
		int b = get();
		if(z -> c[y -> get()] == y)
			z -> c[y -> get()] = this;
		y -> set(b, c[!b]);
		this -> set(!b, y);
		pa = z;
		y -> update();
		update();
		return this;
	}
	inline node* splay() {
		static node* stack[N];
		int top = 0;
		stack[top = 1] = this;
		for(node * x = this;!x -> is_root();)
			stack[++top] = x = x -> pa;
		for(;top;--top)
			stack[top] -> pushdown();
		for(;!is_root();rotate())
			if(!pa -> is_root())
				(get() ^ pa -> get() ? this : pa) -> rotate();
		return this -> update();
	}
	inline node* splay_to(node* to) {
		static node* stack[N];
		int top = 0;
		stack[top = 1] = this;
		for(node * x = this;x != to;)
			stack[++top] = x = x -> pa;
		for(;top;--top)
			stack[top] -> pushdown();
		for(;this -> pa != to;rotate())
			if(pa -> pa != to)
				(get() ^ pa -> get() ? this : pa) -> rotate();
		return this -> update();
	}
};

node * node::null;
std::map<node*, int> map;
inline int id(node * a) {
	static int tot = 0;
	return map.count(a) ? map[a] : map[a] = tot ++;
}

inline void retwist(node* x) {
	/*
         ?
            1
          T
        2   3
       4 5 6 7

	? -> 4 -> 2 -> 5 -> 1
	1 -> 6 -> 3 -> 7 -> ?

	? -> 4 -> 2 -> 5 -> 1 -> 6 -> 3
	3 -> 7 -> ?

         ?
            3
          T
        1   7
      2  6  
     4 5
        
        
	*/
	x -> pa -> pa -> splay();
	x -> pa -> pa -> splay();
	if(x -> pa -> pa -> c[1] == x -> pa) 
		x -> pa -> pa -> rotate();
	x -> pa -> pushdown_twist();
	if(x -> pa -> c[0] == x) {
		x -> reverse();
		x -> pa -> c[1] -> reverse();
		x -> pa -> reverse();
	}
	x -> pushdown();
	node * id1 = x -> pa -> pa;
	node * T = id1 -> c[0];
	node * id2 = T -> c[0];
	node * id3 = T -> c[1];
	node * id6 = id3 -> c[0];
	node * id7 = id3 -> c[1];

	id1 -> c[1] = node::null;
	if(id1 -> pa -> c[1] == id1) {
		id1 -> pa -> c[1] = id3;
	}
	id3 -> pa = id1 -> pa;
	id3 -> set(0, T);
	id3 -> c[1] = node::null;

	T -> set(0, id1);
	T -> set(1, id7);
	id1 -> set(0, id2);
	id1 -> set(1, id6);
	id1 -> update();
	T -> update_twist();
	id3 -> update();
	x -> splay();
}
inline void access(node * o) {
	o -> splay();
	if(o -> pa -> is_twist()) retwist(o);
	o -> c[1] = node::null, o -> update();
	for(node * t = o -> pa;t != node::null;t -> c[1] = o, o -> rotate(), t = o -> pa) {
		if(t -> splay() -> pa -> is_twist())
			retwist(t);
	}
}
inline void makeroot(node * x) {
	access(x), x -> reverse();
}
inline bool link(node * a, node * b, int A) {
	if(a == b) return false;
	makeroot(a);
	access(b);
	if(a -> pa == node::null) {
		node* edge = new node(A);
		edge -> set(1, a) -> update();
		edge -> pa = b;
		return true;
	} else if(b -> cyc == false) {
		node* edge = new node(A);
		node* twist = new node;
		twist -> cyc = 1;
		a -> splay_to(b);
		twist -> set(0, a -> c[1]);
		twist -> set(1, edge) -> update_twist();
		a -> set(1, twist) -> update();
		b -> update();
		return true;
	} else {
		return false;
	}
}
inline bool cut(node * a, node * b, int A) {
	if(a == b) return false;
	makeroot(a);
	access(b);
	if(a -> pa == node::null) 
		return false;
	a -> splay_to(b);
	if(a -> c[1] -> is_twist()) {
		a -> c[1] -> pushdown_twist();
		node * le = a -> c[1] -> c[0], * ri = a -> c[1] -> c[1];
		if(le -> c[0] == node::null && le -> c[1] == node::null && le -> eql(A)) {
			delete le, delete a -> c[1];
			a -> set(1, ri -> reverse()) -> update(), b -> update();
			return true;
		}
		if(ri -> c[0] == node::null && ri -> c[1] == node::null && ri -> eql(A)) {
			delete ri, delete a -> c[1];
			a -> set(1, le) -> update(), b -> update();
			return true;
		}
		return false;
	} else {
		if(a -> c[1] -> c[0] == node::null && a -> c[1] -> c[1] == node::null && a -> c[1] -> eql(A)) {
			delete a -> c[1];
			a -> pa = b -> c[0] = node::null, b -> update();
			a -> c[1] = node::null, a -> update();
			return true;
		} else {
			return false;
		}
	}
}

node a[N];

inline node* gr(node*x) {
	return x->pa==node::null?x:gr(x->pa);
}
const int M=500005;
int U[M],V[M];
int main() {
	int n,m;read(n,m);
	for(int i=1;i<=m;++i)read(U[i],V[i]);
	int l=1;ll ans=0;
	for(int r=1;r<=m;++r){
		while(!link(a+U[r],a+V[r],0))cut(a+U[l],a+V[l],0),++l;
		ans+=r-l+1;
	}
	printf("%lld\n",ans);
	return 0;
}