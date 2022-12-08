#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
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

const int N=200020;

struct Node {
    LL l, r;
    LL buf;
} tr[N*4];

void update(int x) {
    tr[x].l=tr[x*2].l, tr[x].r=tr[x*2+1].r;
}

void release(int x) {
    if(tr[x].buf!=0) {
        for(int y: {x*2, x*2+1}) {
            tr[y].l+=tr[x].buf;
            tr[y].r+=tr[x].buf;
            tr[y].buf+=tr[x].buf;
        }
        tr[x].buf=0;
    }
}

void add(int x, int s, int t, int st, int en, LL val) {
    if(st<=s && t<=en) {
        tr[x].l+=val, tr[x].r+=val;
        tr[x].buf+=val;
        return;
    }
    release(x);
    int mid=(s+t)/2;
    if(st<=mid) add(x*2, s, mid, st, en, val);
    if(mid<en) add(x*2+1, mid+1, t, st, en, val);
    update(x);
}

int first_ge0(int x, int s, int t, int st, int en) {
    if(s==t) {
        if(tr[x].l>=0) return s; else return s+1;
    }
    release(x);
    int mid=(s+t)/2; bool left=false;
    if(st>mid) left=false;
    else if(en<=mid) left=true;
    else left=(tr[x*2].r>=0);

    if(left) {
        return first_ge0(x*2, s, mid, st, en);
    } else {
        return first_ge0(x*2+1, mid+1, t, st, en);
    }
}

int last_le0(int x, int s, int t, int st, int en) {
    if(s==t) {
        if(tr[x].l<=0) return s; else return s-1;
    }
    release(x);
    int mid=(s+t)/2; bool left=false;
    if(st>mid) left=false;
    else if(en<=mid) left=true;
    else left=!(tr[x*2+1].l<=0);

    if(left) {
        return last_le0(x*2, s, mid, st, en);
    } else {
        return last_le0(x*2+1, mid+1, t, st, en);
    }
}

void print(int x, int s, int t, int st, int en) {
    if(s==t) {
        printf("%d ", (int)tr[x].l);
        return;
    }
    release(x);
    int mid=(s+t)/2;
    if(st<=mid) print(x*2, s, mid, st, en);
    if(mid<en) print(x*2+1, mid+1, t, st, en);
}

int main() {
    int n; scanf("%d", &n);
    static int a[N]; rep(i, 1, n) scanf("%d", &a[i]);
    static int b[N]; rep(i, 1, n) scanf("%d", &b[i]);
    fillchar(tr, 0);

    VI ma; ma.pb(0); a[0]=1<<30; 
    VI mb; mb.pb(0); b[0]=-(1<<30);
    LL ans=0;
    rep(i, 1, n) {
        add(1, 1, n, i, i, -a[i]);
        while(a[ma.back()]<=a[i]) {
            const int j=ma.back(); ma.pop_back();
            add(1, 1, n, ma.back()+1, j, -(a[i]-a[j]));
        }
        ma.pb(i);
        add(1, 1, n, i, i, b[i]);
        while(b[mb.back()]>=b[i]) {
            const int j=mb.back(); mb.pop_back();
            add(1, 1, n, mb.back()+1, j, b[i]-b[j]);
        }
        mb.pb(i);

        //print(1, 1, n, 1, i); printf("\n");

        const int j=first_ge0(1, 1, n, 1, i);
        const int k=last_le0(1, 1, n, 1, i);
        //printf("%d %d\n",j,k);
        ans+=k-j+1;
    }
    cout<<ans<<endl;
    return 0;
}