#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
using ll = long long;
template<typename T, typename ...Args>
void print(T arg, Args&&... args) {
    cout << arg;
    ((cout << " " << args ), ...);
    cout << "\n";
}
template<typename ...Args>
void read(Args&... args) {
    (cin >> ... >> args);
}

static char buf[450 << 20];
void* operator new(size_t s) {
    static size_t i = sizeof buf;
    assert(s < i);
    return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 1e9+1e7;
struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    int add=0, mi = -inf, ma = inf;
    //    , mset = inf, madd = 0, val = -inf;
    Node(int lo,int hi):lo(lo),hi(hi){
        mi = lo, ma = hi-1;
    }
    int query(int x) {
        if(x < lo  || x >= hi) return -1;
        if(mi == ma) return mi;
        push();
        return max(l->query(x), r->query(x));
    }
    void update(int T) {
        if(ma < T) {
            ++add; ++mi; ++ma;
        }
        else if(mi > T) {
            --add; --mi; --ma;
        }
        else if(mi == T && ma == T) return;
        else {
            push(); l->update(T); r->update(T);
            mi = l->mi;
            ma = r->ma;
        }
    }
    void pushadd(int v) {
        add += v; mi += v; ma += v;
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        l->pushadd(add);
        r->pushadd(add);
        add=0;
    }
};


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    read(n);
    const int M=1e9+1;
    Node *t = new Node(0,M);
    int lastans = 0;
    const int MOD = 1e9+1;
    rep(i,0,n) {
        int T,k;
        read(T,k);
        t->update(T);
        rep(j,0,k) {
            int x; read(x);
            x=(x+lastans)%MOD;
            lastans = t->query(x);
            print(lastans);
        }
    }
}