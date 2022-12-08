// 20:41
// 20:51 - 
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
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

const int MAXN=200010;

int a[MAXN], cnt[MAXN], next_diff[MAXN];
int n, m;
LL ans;

struct Trip {
    struct Block {
        int x, y, v; 
        Block(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}
    };
    vector<Block> sta;
    LL dis;
    Trip() {
        dis=0; sta.clear();
        sta.pb(Block(1, n, 0));
    }

    void print() {
        printf("trip d=%lld: ", dis);
        for(Block b: sta) printf("[%d %d %d] ", b.x,b.y,b.v); printf("\n");
    }

    void add_sta(int l, int r, int t) {
        if(l>r) swap(l, r);
        vector<Block> old_sta=sta;
        sta.clear();
        for(const Block &b: old_sta) {
            if(r<b.x || b.y<l) { sta.pb(b); continue; }
            if(l<=b.x && b.y<=r) {
                sta.pb(Block(b.x, b.y, b.v+t)); continue;
            }
            if(b.x<l) sta.pb(Block(b.x, l-1, b.v));
            if(r<b.y) sta.pb(Block(r+1, b.y, b.v));
            sta.pb(Block(max(l,b.x), min(r,b.y), b.v+t));
        }
    }

    void add_dis(int l, int r, int t) {
        if(l>r) swap(l, r);
        dis+=LL(a[r]-a[l])*LL(t);
    }

    bool check() const {
        for(const Block &b: sta) {
            if(cnt[b.x]!=b.v) return false;
            int z=next_diff[b.x];
            if(z<=b.y) return false;
        }
        return true;
    }
    void update() const {
        if(ans==-2) ans=dis;
        else if(ans>=0) {
            if(ans!=dis) ans=-1;
        }
    }
};

void go(Trip &tr, int x, bool left, int d) {
    //printf("go x=%d l=%d d=%d\n",x,left,d);
    if(d==0) return;
    if(left) {
        int y=max(1, x-d), len=x-y;
        if(len>0) {
            tr.add_sta(y, x-1, 1);
            tr.add_dis(y, x, 1);
        }
        go(tr, y, false, d-len);
    } else {
        if(x==1) {
            int turn=(n-1)*2, times=d/turn;
            if(times>0) {
                tr.add_sta(2, n, times);
                tr.add_sta(1, n-1, times);
                tr.add_dis(1, n, times*2);
            }
            d-=times*turn;
        }

        int y=min(n, x+d), len=y-x;
        if(len>0) {
            tr.add_sta(x+1, y, 1);
            tr.add_dis(x, y, 1);
        }
        go(tr, y, true, d-len);
    }
}

int main() {
    scanf("%d", &n); rep(i, 1, n) scanf("%d", &a[i]);
    fillchar(cnt, 0);
    scanf("%d", &m); rep(i, 1, m) { int k; scanf("%d", &k); cnt[k]++; }
    next_diff[n]=n+1;
    irep(i, n-1, 1) next_diff[i]=(cnt[i]==cnt[i+1]?next_diff[i+1]:i+1);

    /*
    Trip t;
    t.add_sta(3,6,1);
    t.add_sta(5,5,1);
    t.print();
    */
    //exit(1);

    ans=-2;
    rep(i, 1, n) {
        // go left
        {
            Trip tr; 
            tr.add_sta(i, i, 1);
            go(tr, i, true, m-1);
            if(tr.check()) tr.update();
        }
        // go right
        {
            Trip tr;
            tr.add_sta(i, i, 1);
            go(tr, i, false, m-1);
            if(tr.check()) tr.update();
        }
    }
    if(ans<0) ans=-1;
    cout<<ans<<endl;

    return 0;
}