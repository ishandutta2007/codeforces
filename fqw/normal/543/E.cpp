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

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define rep2(i, n) rep(i, 0, (n)-1)
#define irep2(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200010;
const int MAXNum=655;
const int MAXSize=455;

PII a[MAXN];
int n, m;

int bv[MAXNum][MAXNum], bv0[MAXNum][MAXNum], bvl[MAXN], bvr[MAXN];
VI bevents[MAXNum];
int bsize, bnum;

int bfirst(int p) { return (p-1)*bsize+1; }
int blast(int p) { return min(n, p*bsize); }
int bid(int i) { return (i-1)/bsize+1; }

void preprocess() {
    sort(a+1, a+n+1, greater<PII>());

    static int nums[MAXN], val[MAXNum], buf[MAXNum];
    bsize=450;
    bnum=(n-1)/bsize+1;
    fillchar(nums, 0); fillchar(val, 0); fillchar(buf, 0);
    fillchar(bv[0], 0);
    fillchar(bv0[0], 0);
    rep(i, 1, bnum) bevents[i].clear();
    rep(k, 1, n) {
        int l=max(1, a[k].se-m+1), r=a[k].se;
        int vl0=val[bid(l)], vr0=val[bid(r)];
        // update: add [l,r] by one
        for(int i=l; i<=r; ) {
            int p=bid(i);
            if(i==bfirst(p) && blast(p)<=r) {
                val[p]++; buf[p]++;
                i=blast(p)+1;
            }
            else {
                if(buf[p]!=0) {
                    int x=bfirst(p), y=blast(p);
                    rep(j, x, y) nums[j]+=buf[p];
                    buf[p]=0;
                }
                for(int j=min(r, blast(p)); i<=j; ++i) {
                    nums[i]++;
                    setmax(val[p], nums[i]);
                }
            }
        }
        // save bvl & bvr
        bvl[k]=val[bid(l)]-vl0;
        bvr[k]=val[bid(r)]-vr0;
        if(bid(l)==bid(r)) bvr[k]=0;
        // save bv & bv0
        if(k%bsize==0) {
            rep(p, 1, bnum) {
                bv[k/bsize][p]=val[p];
                bv0[k/bsize][p]=buf[p]+nums[bfirst(p)];
            }
        }
        // save bevent
        bool z=false;
        if(l!=bfirst(bid(l))) bevents[bid(l)].PB(k), z=true;
        if(bid(l)!=bid(r) || !z) bevents[bid(r)].PB(k);
    }
}

int cnt;
int query_block(int k0, int l, int r) {
    //printf("query_block %d %d %d\n",k0,l,r);
    assert(bid(l)==bid(r));
    int p=bid(l), first=bfirst(p), k1=k0/bsize*bsize;

    int v[MAXSize];
    fillchar(v, 0);
    //printf("%d\n", (int)bevents[p].size());
    for(int k: bevents[p]) {
        ++cnt;
        if(k>k1) break;
        int x=max(0, a[k].se-m+1-first);
        int y=min(bsize-1, a[k].se-first);
        if(x<=y) v[x]++, v[y+1]--;
    }
    int delta=bv0[k0/bsize][p]-v[0];
    rep(k, k1+1, k0) {
        int x=max(0, a[k].se-m+1-first);
        int y=min(bsize-1, a[k].se-first);
        if(x<=y) v[x]++, v[y+1]--;
    }
    rep(i, 0, bsize-1) {
        v[i+1]+=v[i];
        v[i]+=delta;
    }
    l=max(l-first, 0);
    r=min(r-first, bsize-1);
    int ans=0;
    rep(i, l, r) setmax(ans, v[i]);
    return ans;
}

int query_history(int k, int l, int r) {
    //printf("query_history %d %d %d\n",k,l,r);fflush(stdout);
    static int val[MAXNum], buf[MAXNum];
    memmove(val, bv[k/bsize], sizeof(val));
    fillchar(buf, 0);
    //rep(i, 1, bnum) printf("  val[%d]=%d\n",i,val[i]);
    rep(cur, k/bsize*bsize+1, k) {
        int x=max(1, a[cur].se-m+1), y=a[cur].se;
        x=bid(x), y=bid(y);
        if(bvl[cur]!=0) {
            buf[x]+=bvl[cur]; buf[x+1]-=bvl[cur];
        }
        if(bvr[cur]!=0) {
            buf[y]+=bvr[cur]; buf[y+1]-=bvr[cur];
        }
        ++x, --y;
        if(x<=y) buf[x]+=1, buf[y+1]-=1;
    }
    rep(i, 0, bnum) {
        buf[i+1]+=buf[i];
        val[i]+=buf[i];
    }
    //rep(i, 1, bnum) printf("  val[%d]=%d\n",i,val[i]);

    int ans=0;
    int cid=1, cfirst=1, clast=bsize;
    while(clast<l) ++cid, cfirst+=bsize, clast+=bsize;

    for(int i=l; i<=r; ) {
        //int p=bid(i);
        //if(i==bfirst(p) && blast(p)<=r) {
        if(i==cfirst && clast<=r) {
            setmax(ans, val[cid]);
            i=clast+1;
            //i=blast(p)+1;
        }
        else {
            int j=min(clast, r);
            //int j=min(blast(p), r);
            setmax(ans, query_block(k, i, j));
            i=j+1;
        }
        ++cid, cfirst+=bsize, clast+=bsize;
    }
    return ans;
}

int query(int l, int r, int q) {
    int i=int(lower_bound(a+1, a+n+1, MP(q,0), greater<PII>())-a);
    assert(i>=1 && i<=n+1);
    int ans=m-query_history(i-1, l, r);
    return ans;
}

int main() {
    /*
    n=m=200000; rep(i, 1, n) a[i].fi=rand(), a[i].se=i;
    preprocess(); 
    //rep(i, 1, 200000) { int l=1+rand()%100, r=100-rand()%100; if(l>r) swap(l,r); query(l,r,rand()); }
    cnt=0;
    rep(i, 1, 200000) { 
        if(i%1000==0) printf("i=%d cnt=%d\n", i,cnt), fflush(stdout), cnt=0;
        if(i%1000==0) printf("bsize=%d\n",bsize);
        //int l=rand()%n+1, r=rand()%n+1; if(l>r) swap(l,r); query(l,r,rand()); 
        int p=rand()%n+1;
        int l=1, r=1; if(l>r) swap(l,r); query(l,r,rand()); 
        //int l=1+rand()%100, r=n-rand()%100; if(l>r) swap(l,r); query(l,r,rand());
    }
    return 0;
    //*/

    scanf("%d%d", &n,&m);
    rep(i, 1, n) scanf("%d", &a[i].fi), a[i].se=i;
    preprocess();

    int cs; scanf("%d", &cs);
    int pans=0;
    while(cs--) {
        int l, r, x;
        scanf("%d%d%d", &l,&r,&x);
        int q=x^pans;
        int ans=query(l, r, q);
        printf("%d\n", ans);
        pans=ans;
    }

    return 0;
}