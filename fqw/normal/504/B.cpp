#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

template<class T> class FenwickTree {
    std::vector<T> a;
    int n; T v0;
public:
    FenwickTree() { }
    FenwickTree(int n, T v) : a(size_t(n+1), v), n(n), v0(v) { }
    void add(int x, T v) { for(; x<=n; x+=(x&-x)) a[(size_t)x]+=v; }
    T get(int x) const { T r=v0; for(; x>=1; x-=(x&-x)) r+=a[(size_t)x]; return r; }
};
class Treap {
    struct Node {
        int val, rkey;
        int l, r, size;
    } tr[200010];
    int num, root;

    void update(int x) {
        tr[x].size=tr[tr[x].l].size+tr[tr[x].r].size+1;
    }
    int lrotate(int x) {
        int y=tr[x].l; tr[x].l=tr[y].r; tr[y].r=x;
        update(x); update(y);
        return y;
    }
    int rrotate(int x) {
        int y=tr[x].r; tr[x].r=tr[y].l; tr[y].l=x;
        update(x); update(y);
        return y;
    }
    int insert(int x, int y) {
        if(x==0) return y;
        if(tr[y].val<tr[x].val) {
            tr[x].l=insert(tr[x].l, y);
            if(tr[tr[x].l].rkey>tr[x].rkey)
                x=lrotate(x);
        }
        else {
            tr[x].r=insert(tr[x].r, y);
            if(tr[tr[x].r].rkey>tr[x].rkey)
                x=rrotate(x);
        }
        update(x);
        return x;
    }
    int remove(int x, int val) {
        if(tr[x].val==val) {
            if(tr[x].l==0 && tr[x].r==0)
                return 0;
            if(tr[tr[x].l].rkey>tr[tr[x].r].rkey) {
                x=lrotate(x);
                tr[x].r=remove(tr[x].r, val);
            }
            else {
                x=rrotate(x);
                tr[x].l=remove(tr[x].l, val);
            }
        }
        else {
            if(val<tr[x].val)
                tr[x].l=remove(tr[x].l, val);
            else
                tr[x].r=remove(tr[x].r, val);
        }
        update(x);
        return x;
    }
    int ask(int x, int ind) {
        assert(ind<=tr[x].size);
        int ls=tr[tr[x].l].size;
        if(ind<=ls)
            return ask(tr[x].l, ind);
        if(ind==ls+1)
            return tr[x].val;
        return ask(tr[x].r, ind-ls-1);
    }

public:
    void init() {
        num=root=0;
        tr[0].rkey=-1;
        tr[0].size=0;
    }
    void add(int val) {
        int x=++num;
        tr[x].val=val, tr[x].rkey=rand();
        tr[x].l=tr[x].r=0, tr[x].size=1;
        root=insert(root, x);
    }
    void del(int val) {
        root=remove(root, val);
    }
    int query(int ind) {
        return ask(root, ind);
    }
};

int x[200000], y[200000], z[200000];
int n;

void decode(int a[]) {
    FenwickTree<int> tr(n, 0);
    irepn(i, n) {
        tr.add(a[i]+1, 1);
        a[i]=tr.get(a[i]);
    }
}

void encode(int a[]) {
    static Treap tr;
    tr.init();
    repn(i, n) tr.add(i);
    repn(i, n) {
        a[i]=tr.query(a[i]+1);
        tr.del(a[i]);
    }
}

int main() {
    scanf("%d", &n);
    repn(i, n) scanf("%d", &x[i]);
    repn(i, n) scanf("%d", &y[i]);
    decode(x);
    decode(y);
    //repn(i, n) printf("%d ", x[i]); printf("\n");
    //repn(i, n) printf("%d ", y[i]); printf("\n");
    int r=0;
    irepn(i, n) {
        int num=n-i;
        int cur=x[i]+y[i]+r;
        z[i]=cur%num;
        r=cur/num;
    }
    //assert(r==0);
    //repn(i, n) printf("%d ", z[i]); printf("\n");
    encode(z);
    repn(i, n) printf("%d ", z[i]); printf("\n");
    return 0;
}