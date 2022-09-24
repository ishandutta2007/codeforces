#include<bits/stdc++.h>
#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;
int op(int x,int y){
	return min(x,y);
}
int e(){
	return 2e9;
}
segtree<int,op,e> s(200005);
typedef long long ll;
typedef vector<int> poly;
int a[200005];
struct E{
	int to,id;
};
vector<E> gr[200005];
vector<int> g1[200005];
multiset<int> t[200005];
int n,m,low[200005],sign,p[200005],st[200005],Tp,N,T,fa[200005],d[200005],q;
int size[200005],w[200005],son[200005],top[200005],dfn[200005];
void Add(int x,int y){
	g1[x].push_back(y),g1[y].push_back(x);
}
void Tarjan(int x,int prt){
	dfn[x]=low[x]=++sign,st[++Tp]=x,T++;
	for(E i:gr[x]){
		if(i.id==prt)continue;
		int y=i.to;
		if(!dfn[y]){
			Tarjan(y,i.id),low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				p[0]=0;
				int tmp=0;
				while(tmp!=y)tmp=st[Tp--],p[++p[0]]=tmp;
				Add(++N,x),w[N]=2e9;
				for(int j=1;j<=p[0];j++)Add(N,p[j]),w[N]=min(w[N],w[p[j]]),t[N].insert(w[p[j]]);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int x,int f){
	size[x]=1,fa[x]=f,d[x]=d[f]+1;
	for(int y:g1[x]){
		if(y==f)continue;
		dfs(y,x),size[x]+=size[y];
		if(size[y]>size[son[x]])son[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp,dfn[x]=++sign,s.set(dfn[x],w[x]);
	if(son[x])dfs2(son[x],tp);
	for(int y:g1[x]){
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
int Query(int x,int y){
	int ret=2e9;
	while(top[x]^top[y]){
		if(d[top[x]]<d[top[y]])swap(x,y);
		ret=min(ret,s.prod(dfn[top[x]],dfn[x]+1)),x=fa[top[x]];
	}
	if(d[x]>d[y])swap(x,y);
	ret=min(ret,s.prod(dfn[x],dfn[y]+1));
	if(x>n)ret=min(ret,w[fa[x]]);
	return ret;
}
char opt[10];
int main(){
	scanf("%d%d%d",&n,&m,&q),N=n;
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),gr[x].push_back({y,i}),gr[y].push_back({x,i});
	Tarjan(1,0),sign=0,memset(dfn,0,sizeof(dfn)),dfs(1,0),dfs2(1,1);
	while(q--){
		int x,y;
		scanf("%s%d%d",opt,&x,&y);
		if(opt[0]=='A')printf("%d\n",Query(x,y));
		else {
			if(fa[x]>n){
				t[fa[x]].erase(t[fa[x]].find(w[x]));
				t[fa[x]].insert(y);
				s.set(dfn[fa[x]],*t[fa[x]].begin());
			}
			w[x]=y,s.set(dfn[x],y);
		}
	}
}