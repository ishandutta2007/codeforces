// LUOGU_RID: 91499285
#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1

#include <algorithm>
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

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

#endif  // ATCODER_INTERNAL_BITOP_HPP
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

#endif  // ATCODER_SEGTREE_HPP
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=5e5+5;
int n,q,fa[15];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct info{int num,tl[3],tr[3];};
info upd(info A,info B)
{
	int num=A.num+B.num;
	for(int i=1;i<=8;i++)fa[i]=i;
	for(int i=0;i<3;i++)
		if(A.tr[i]&&B.tl[i])if(find(A.tr[i])!=find(B.tl[i]+4))--num,fa[find(A.tr[i])]=B.tl[i]+4;
	int bel[9]={0,0,0,0,0,0,0,0,0},tt=0;
	info C;C.num=num;
	for(int i=0;i<3;i++)
		C.tl[i]=A.tl[i],C.tr[i]=B.tr[i]?(B.tr[i]+4):0;
	for(int i=0;i<3;i++)
	{
		if(C.tl[i]&&!bel[find(C.tl[i])])bel[find(C.tl[i])]=++tt;
		if(C.tr[i]&&!bel[find(C.tr[i])])bel[find(C.tr[i])]=++tt;
	}
	for(int i=0;i<3;i++)C.tl[i]=bel[find(C.tl[i])],C.tr[i]=bel[find(C.tr[i])];
	return C;
}
info E(){return {};}
atcoder::segtree<info,upd,E>sg;
char s[3][xx];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read();
	for(int i=0;i<=2;i++)
		for(int j=0;j<n;j++)
		{
			char c;
			while((c=getchar())!='0'&&c!='1');
			s[i][j]=c-'0';
		}
	vector<info>v;
	for(int j=0;j<n;j++)
	{
		info nw={1};
		if(s[0][j]&&!s[1][j]&&s[2][j])
			nw={2,1,0,2,1,0,2};
		else if(!(s[0][j]|s[1][j]|s[2][j]))
			nw.num=0;
		else 
		{
			for(int i=0;i<3;i++)if(s[i][j])nw.tl[i]=nw.tr[i]=1;
		}
		v.push_back(nw);
//		if(j==0)cerr<<nw.tl[0]<<" "<<nw.tl[1]<<" "<<nw.tl[2]<<"\n";
//		if(j==1)cerr<<nw.tl[0]<<" "<<nw.tl[1]<<" "<<nw.tl[2]<<"\n";
	}
	sg=atcoder::segtree<info,upd,E>(v);
//	info it=upd(v[0],v[1]);
//	info it=sg.prod(0,2);
//	cerr<<it.tl[0]<<" "<<it.tl[1]<<" "<<it.tl[2]<<" "<<it.num<<"\n";
//	cerr<<it.tr[0]<<" "<<it.tr[1]<<" "<<it.tr[2]<<"\n";
	
	q=read();
	while(q--)
	{
		int l=read()-1,r=read();
		cout<<sg.prod(l,r).num<<"\n";
	}
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}