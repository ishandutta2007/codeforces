//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353

template<typename T, typename F>
struct segtree{
	int sz;
	vector<T>seg;
	const F f;
	const T e;
	segtree(){}
	segtree(int n, const F f, const T e): f(f), e(e) {
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void init(int n){
		sz = 1;
		while(sz < n) sz <<= 1;
		seg.assign(2*sz, e);
	}
	void update(int a, T p){
		a += sz-1;
		seg[a] = p;
		while(a){
			a = (a-1)/2;
			seg[a] = f(seg[a*2+1], seg[a*2+2]);
		}
	}
	void make(vector<T>a){
		rep(i, a.size()) seg[i+sz-1] = a[i];
		for(int i=sz-2;i>=0;i--) seg[i] = f(seg[i*2+1], seg[i*2+2]);
	}
	T query(int a, int b){
		a += sz-1, b += sz-1;
		T L = e, R = e;
		while(a <= b){
			if((a&1) == 0) { L = f(L, seg[a++]); }
			if((b&1) == 1) { R = f(seg[b--], R); }
			if(a > b) break;
			a = (a-1) >> 1;
			b = (b-1) >> 1;
		}
		return f(L, R);
	}
};

int n, p[200005], w[200005];
int q, x[50005], y[50005];

struct node{
	int l, r, m;
	int lnum, rnum;
	int up;
	ll sum;
}nd[400005];

vector<int>lst[400005], bit[400005];
int bottom[400005];

void assign(int pos, int num){
	int cur = bottom[pos];
	while(1){
		lst[cur].pb(num);
		if(cur == 0) return;
		cur = nd[cur].up;
	}
}

ll calc(int pos){
	int cur = bottom[pos];
	ll ret = 0;
	while(1){
		ll all = 1LL * (nd[cur].m-nd[cur].l+1) * (nd[cur].r-nd[cur].m);
		ret += min(nd[cur].sum, all-nd[cur].sum);
		if(cur == 0) return ret;
		cur = nd[cur].up;
	}
}

void add(int id, int a, int v){
	for(;a<bit[id].size();a+=a&-a){
		bit[id][a] += v;
	}
}
int query(int id, int a){
	int ret = 0;
	for(;a;a-=a&-a){
		ret += bit[id][a];
	}
	return ret;
}
void push(int pos, int num, int coef){
	int cur = bottom[pos];
	while(1){
		int k = POSL(lst[cur], num);
		add(cur, k+1, coef);
		if(nd[cur].l != nd[cur].r) {
    		if(pos <= nd[cur].m){
    			int x = POSL(lst[nd[cur].rnum], num);
    			nd[cur].sum += coef * query(nd[cur].rnum, x);
    		}
    		else{
    			int x = POSU(lst[nd[cur].lnum], num);
    			nd[cur].sum += coef * (query(nd[cur].lnum, lst[nd[cur].lnum].size()) - query(nd[cur].lnum, x));
    		}
		}
		if(cur == 0) return;
		cur = nd[cur].up;
	}
}
auto f = [](const P &a, const P &b){return min(a, b);};
segtree<P, decltype(f)>kaede(0, f, mp(INF, INF));

void go(int lb, int ub, int &id){
	nd[id].l = lb; nd[id].r = ub;
	if(lb == ub){
		nd[id].m = lb;
		nd[id].sum = 0;
		nd[id].lnum = nd[id].rnum = -1;
		bottom[lb] = id;
		return;
	}
	auto x = kaede.query(lb, ub-1);
   	nd[id].m = x.sc;
   	int pre_id = id;
   	id++;
    nd[pre_id].lnum = id; nd[id].up = pre_id;
   	go(lb, x.sc, id);
   	id++;
   	nd[pre_id].rnum = id; nd[id].up = pre_id;
   	go(x.sc+1, ub, id);
}

int main(){
	scanf("%d", &n);
	repn(i, n){
		scanf("%d", &p[i]);
	}
	kaede.init(n+5);
	repn(i, n-1){
		scanf("%d", &w[i]);
		kaede.update(i, mp(w[i], i));
	}
	int id = 0;
    go(1, n, id);
	repn(i, n) assign(i, p[i]);
	scanf("%d", &q);
	repn(i, q){
		scanf("%d %d", &x[i], &y[i]);
		swap(p[x[i]], p[y[i]]);
		assign(x[i], p[x[i]]);
		assign(y[i], p[y[i]]);
	}
	rep(i, id+1){
		SORT(lst[i]);
		bit[i].resize(lst[i].size()+2, 0);
	}
	for(int i=q;i>=1;i--) swap(p[x[i]], p[y[i]]);
	ll zan = 0;
	repn(i, n){
		zan -= calc(i);
		push(i, p[i], 1);
		zan += calc(i);
	}
	repn(i, q){
		zan -= calc(x[i]);
		push(x[i], p[x[i]], -1);
		zan += calc(x[i]);
		
		zan -= calc(y[i]);
		push(y[i], p[y[i]], -1);
		zan += calc(y[i]);
		
		swap(p[x[i]], p[y[i]]);
		
		zan -= calc(x[i]);
		push(x[i], p[x[i]], 1);
		zan += calc(x[i]);
		
		zan -= calc(y[i]);
		push(y[i], p[y[i]], 1);
		zan += calc(y[i]);
		
		printf("%lld\n", zan);
	}
}