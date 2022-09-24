#include<bits/stdc++.h>
using namespace std;
#include <algorithm>

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
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=1e6;
int n,m;
struct Thing{
	ll x,val,id;
}a[200005];
bool operator <(const Thing x,const Thing &y){
	return x.x<y.x;
}
ll c1[200005],c2[200005],b[200005];
ll op(ll x,ll y){
	return max(x,y);
}
ll e(){
	return -1e18;
}
int ans[200005],hasl[200005],hasr[200005];
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].val),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int L=lower_bound(a+1,a+n+1,(Thing){a[i].x-a[i].val,0,0})-a;
		c1[L]++,c1[i]--;
		c2[L]-=(a[i].x-a[i].val),c2[i]+=(a[i].x-a[i].val);
		int R=lower_bound(a+1,a+n+1,(Thing){a[i].x+a[i].val,0,0})-a;
		c1[i]--,c1[R]++;
		c2[i]+=(a[i].x+a[i].val),c2[R]-=(a[i].x+a[i].val);
	}
	segtree<ll,op,e> t1(n+5),t2(n+5);
	for(int i=1;i<=n;i++){
		c1[i]+=c1[i-1],c2[i]+=c2[i-1];
		b[i]=c1[i]*a[i].x+c2[i];
		t1.set(i,b[i]-a[i].x);
		t2.set(i,b[i]+a[i].x);
		hasl[i]=hasl[i-1]+(b[i]>m);
	}
	for(int i=n;i>=1;i--)hasr[i]=hasr[i+1]+(b[i]>m);
	for(int i=1;i<=n;i++){
		int L=lower_bound(a+1,a+n+1,(Thing){a[i].x-a[i].val,0,0})-a;
		int R=lower_bound(a+1,a+n+1,(Thing){a[i].x+a[i].val,0,0})-a;
		ans[a[i].id]=0;
		if(hasl[L-1]||hasr[R])continue;
		if(t1.prod(L,i)<=a[i].val-a[i].x+m){
			if(t2.prod(i,R)<=a[i].val+a[i].x+m){
				ans[a[i].id]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	puts("");
	for(int i=1;i<=n+1;i++)c1[i]=c2[i]=b[i]=ans[i]=hasl[i]=hasr[i]=0,a[i]={0,0,0};
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}