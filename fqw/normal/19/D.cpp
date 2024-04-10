// 2:25
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
    PII key;
    int max_se, rand;
    Node *l, *r;
};

Node* lrotate(Node* x) {
    Node* y=x->l; x->l=y->r; y->r=x;
    return y;
}

Node* rrotate(Node* x) {
    Node* y=x->r; x->r=y->l; y->l=x;
    return y;
}

void update(Node* x) {
    x->max_se=x->key.se;
    if(x->l) setmax(x->max_se, x->l->max_se);
    if(x->r) setmax(x->max_se, x->r->max_se);
}

Node* insert(Node* x, PII key) {
    if(x==nullptr) {
        x=new Node();
        x->key=key;
        x->max_se=key.se, x->rand=rand();
        x->l=x->r=nullptr;
        return x;
    }
    if(key<x->key) {
        x->l=insert(x->l, key);
        if(x->l->rand>x->rand) {
            x=lrotate(x);
        }
    } else {
        x->r=insert(x->r, key);
        if(x->r->rand>x->rand) {
            x=rrotate(x);
        }
    }
    update(x);
    return x;
}

Node* remove(Node* x, PII key) {
    if(x->key==key) {
        if(x->l==nullptr && x->r==nullptr) {
            return nullptr;
        }
        if(x->l && (x->r==nullptr || x->l->rand>x->r->rand)) {
            x=lrotate(x);
            x->r=remove(x->r, key);
        } else {
            x=rrotate(x);
            x->l=remove(x->l, key);
        }
    } else {
        if(key<x->key) {
            x->l=remove(x->l, key);
        } else {
            x->r=remove(x->r, key);
        }
    }
    update(x);
    return x;
}

pair<bool, PII> find(Node* x, PII p) {
    if(x==nullptr) {
        return mp(false, PII());
    }
    if(p<=x->key) {
        auto r=find(x->l, p);
        if(r.fi) return r;
        if(p.se<=x->key.se) {
            return mp(true, x->key);
        }
        if(x->r && x->r->max_se>=p.se) {
            return find(x->r, p);
        } else {
            return mp(false, PII());
        }
    } else {
        return find(x->r, p);
    }
}

int main() {
    int n; scanf("%d", &n);
    Node* root=nullptr;
    while(n--) {
        char op[9]; int x, y;
        scanf("%s%d%d", op,&x,&y);
        if(op[0]=='a') {
            root=insert(root, mp(x, y));
        } else if(op[0]=='r') {
            root=remove(root, mp(x, y));
        } else if(op[0]=='f') {
            auto r=find(root, mp(x+1, y+1));
            if(r.fi) {
                printf("%d %d\n", r.se.fi, r.se.se);
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}