// 11:36
// 11:48 - 12:09
#include <cassert>
#include <cstring>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
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

const int NODES=100010;

class Treap { //{{{
    struct Node {
        char ch; int n;
        int rkey;
        int l, r, size;
    } tr[NODES+1];
    VI pool;
    int root;

    void update(int x) {
        tr[x].size=tr[tr[x].l].size+tr[tr[x].r].size+tr[x].n;
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
    int insert(int x, int ind, int y) {
        if(x==0) return y;
        int lsize=tr[tr[x].l].size+tr[x].n;
        if(ind<=lsize) {
            tr[x].l=insert(tr[x].l, ind, y);
            if(tr[tr[x].l].rkey>tr[x].rkey)
                x=lrotate(x);
        } else {
            tr[x].r=insert(tr[x].r, ind-lsize, y);
            if(tr[tr[x].r].rkey>tr[x].rkey)
                x=rrotate(x);
        }
        update(x);
        return x;
    }
    int remove(int x, int ind) {
        int psize=tr[tr[x].l].size+1;
        int lsize=tr[tr[x].l].size+tr[x].n;
        if(ind<0 || (psize<=ind && ind<=lsize)) {
            if(ind>0) {
                loffset=psize-ind;
                roffset=lsize-ind;
                removed=x;
                rem=tr[x].ch, rem_n=tr[x].n;
            }
            if(tr[x].l==0 && tr[x].r==0)
                return 0;
            if(tr[tr[x].l].rkey>tr[tr[x].r].rkey) {
                x=lrotate(x);
                tr[x].r=remove(tr[x].r, -1);
            } else {
                x=rrotate(x);
                tr[x].l=remove(tr[x].l, -1);
            }
        } else {
            if(ind<psize)
                tr[x].l=remove(tr[x].l, ind);
            else
                tr[x].r=remove(tr[x].r, ind-lsize);
        }
        update(x);
        return x;
    }

public:
    int loffset, roffset, removed;
    char rem; int rem_n;
    void init() {
        root=0;
        pool.clear(); rep(i, 1, NODES-1) pool.pb(i);
        tr[0].rkey=-1;
        tr[0].size=0;
    }
    void ins(int ind, char ch, int n) {
        int x=pool.back(); pool.pop_back();
        tr[x].ch=ch, tr[x].n=n, tr[x].size=n;
        tr[x].l=tr[x].r=0; tr[x].rkey=rand();
        root=insert(root, ind, x);
    }
    void del(int ind) {
        root=remove(root, ind);
        pool.pb(removed);
    }
}; //}}}

Treap tr;
char str[100010];

int main() {
    int n, q; scanf("%d%d", &n,&q);
    scanf("%s", str+1);

    tr.init();
    rep(i, 1, n) tr.ins(i, str[i], 1);

    rep(qi, 1, q) {
        int l, r, k; scanf("%d%d%d", &l,&r,&k);
        map<char, int> tot;
        while(l<=r) {
            tr.del(r);
            int l2=r+tr.loffset;
            int r2=r+tr.roffset;
            int deserved_l=max(l, l2);
            int deserved_r=min(r, r2);
            assert(deserved_l<=r && r<=deserved_r);
            if(deserved_r<r2)
                tr.ins(l2, tr.rem, r2-deserved_r);
            if(l2<deserved_l)
                tr.ins(l2, tr.rem, deserved_l-l2);
            tot[tr.rem]+=deserved_r-deserved_l+1;
            r=deserved_l-1;
        }
        vector<pair<char, int> > lst(all(tot));
        if(k==1) reverse(all(lst));
        for(auto &p: lst) tr.ins(l, p.fi, p.se);
    }

    while(n>0) {
        tr.del(1); n-=tr.rem_n;
        repn(i, tr.rem_n) putchar(tr.rem);
    }
    printf("\n");

    return 0;
}