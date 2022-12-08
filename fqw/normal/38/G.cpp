#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
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
template<class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os<<"("<<v.first<<", "<<v.second<<")"; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& v) { os<<"["; repn(i, sz(v)) { if(i) os<<", "; os<<v[i]; } return os<<"]"; }
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct Node {
    int v, i, maxv, size, rand;
    Node *l=nullptr, *r=nullptr;
    Node(int val, int ind)
        : v(val), i(ind), maxv(val), size(1), rand(std::rand()) {}
};

Node* update(Node* x) {
    x->size=1, x->maxv=x->v;
    if(x->l) {
        x->size+=x->l->size;
        setmax(x->maxv, x->l->maxv);
    }
    if(x->r) {
        x->size+=x->r->size;
        setmax(x->maxv, x->r->maxv);
    }
    return x;
}

Node* lrotate(Node* x) {
    Node* y=x->l; x->l=y->r, y->r=x;
    update(x), update(y);
    return y;
}

Node* rrotate(Node* x) {
    Node* y=x->r; x->r=y->l, y->l=x;
    update(x), update(y);
    return y;
}

Node* insert(Node* x, int ind, int val, int i) {
    if(x==nullptr) {
        return new Node(val, i);
    }
    int lsize=1+(x->l ? x->l->size : 0);
    int rmax=max(x->v, x->r ? x->r->maxv : 0);
    if(ind<lsize && val>rmax) {
        x->l=insert(x->l, ind, val, i);
        if(x->l->rand>x->rand) x=lrotate(x);
    } else {
        x->r=insert(x->r, ind-lsize, val, i);
        if(x->r->rand>x->rand) x=rrotate(x);
    }
    return update(x);
}

void print(Node* x) {
    if(x==nullptr) return;
    print(x->l);
    printf("%d ", x->i+1);
    print(x->r);
}

int main() {
    int n; scanf("%d", &n);
    Node* root=nullptr;
    repn(i, n) {
        int a, c; scanf("%d%d", &a,&c);
        //printf("%d %d %d\n",i-c,a,i);
        root=insert(root, i-c, a, i);
    }
    print(root); printf("\n");

    return 0;
}