#include <functional>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define sz(a) static_cast<int>(a.size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define repn0(i, n) for(i=0; i<n; ++i)
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
bool upt(PII& a, PII b) {
    if(b.se>a.se || (b.se==a.se && b.fi<a.fi)) {
        a=b; return true;
    }
    return false;
}

const int LOG=20;

struct TreapNode {
    PII v, best;
    int mink, maxk;
    int rnd;
    TreapNode *l, *r;
    TreapNode(PII val) :
        v(val), best(val), mink(v.fi), maxk(v.fi), 
        rnd(rand()), l(nullptr), r(nullptr) {}
    void update() {
        best=v; mink=maxk=v.fi;
        if(l!=nullptr) { upt(best, l->best); mink=l->mink; }
        if(r!=nullptr) { upt(best, r->best); maxk=r->maxk; }
    }
    TreapNode* lrotate() {
        TreapNode* y=l;
        l=y->r; y->r=this;
        update();
        return y;
    }
    TreapNode* rrotate() {
        TreapNode* y=r;
        r=y->l; y->l=this;
        update();
        return y;
    }
};

TreapNode* insert(TreapNode* x, int k, int v) {
    if(x==nullptr) {
        return new TreapNode(mp(k, v));
    }
    if(x->v.fi==k) {
        x->v.se+=v;
        x->update();
        return x;
    }
    if(k<x->v.fi) {
        x->l=insert(x->l, k, v);
        if(x->l->rnd>x->rnd) x=x->lrotate();
    } else {
        x->r=insert(x->r, k, v);
        if(x->r->rnd>x->rnd) x=x->rrotate();
    }
    x->update();
    return x;
}

PII query(TreapNode* x, int l, int r) {
    if(x==nullptr || r<x->mink || l>x->maxk) return mp(0, 0);
    if(l<=x->mink && x->maxk<=r) {
        return x->best;
    }
    if(l>x->v.fi) return query(x->r, l, r);
    if(r<x->v.fi) return query(x->l, l, r);
    auto ans=x->v;
    upt(ans, query(x->l, l, r));
    upt(ans, query(x->r, l, r));
    return ans;
}

TreapNode* merge(TreapNode* x, int xn, TreapNode* y, int yn) {
    if(x==nullptr) return y;
    if(y==nullptr) return x;
    if(xn<yn) return merge(y, yn, x, xn);
    function<void(TreapNode*)> dfs=[&](TreapNode* cur) {
        if(cur==nullptr) return;
        dfs(cur->l);
        dfs(cur->r);
        x=insert(x, cur->v.fi, cur->v.se);
        delete cur;
    };
    dfs(y);
    return x;
}

struct State {
    int l;
    vector<State*> succ=vector<State*>(26);
    State* f=nullptr;

    int original=0;
    vector<State*> up=vector<State*>(LOG);
    vector<pair<PII, int>> queries;
    TreapNode* tr=nullptr;
    int tr_sz=0;

    State(int _l, State* from=nullptr) : l(_l) {
        if(from) {
            succ=from->succ; f=from->f;
        }
    }
} *init;
vector<State*> all_states;

State* extend(State* last, int ch) {
    static int len=0;
    State *p=last, *np=new State(++len);
    all_states.pb(np);
    for(; p && p->succ[ch]==nullptr; p=p->f)
        p->succ[ch]=np;
    if(p==nullptr) np->f=init;
    else {
        State* q=p->succ[ch];
        if(q->l==p->l+1) np->f=q;
        else {
            State* nq=new State(p->l+1, q);
            all_states.pb(nq);
            np->f=q->f=nq;
            for(; p && p->succ[ch]==q; p=p->f)
                p->succ[ch]=nq;
        }
    }
    return np;
}

int main() {
    auto read=[](string* s) {
        static char buf[501000];
        scanf("%s", buf); *s=string(buf);
    };
    init=new State(0);
    string s; read(&s);
    vector<State*> sp(s.size());
    State* cur=init;
    repn(i, s.size()) {
        cur=extend(cur, int(s[i]-'a'));
        sp[i]=cur;
    }
    int m; scanf("%d", &m);
    rep(k, 1, m) {
        read(&s);
        cur=init;
        repn(i, s.size()) {
            cur=extend(cur, int(s[i]-'a'));
            cur->original=k;
        }
    }

    repn(i, LOG) init->up[i]=init;
    for(State* p: all_states) p->up[0]=p->f;
    rep(i, 1, LOG-1) {
        for(State* p: all_states) p->up[i]=p->up[i-1]->up[i-1];
    }

    int q; scanf("%d", &q);
    VPI ans(q);
    repn(k, q) {
        int l, r, pl, pr; scanf("%d%d%d%d", &l,&r,&pl,&pr);
        --pl, --pr;
        cur=sp[pr];
        irepn(i, LOG) {
            State* tmp=cur->up[i];
            if(tmp->l>=pr-pl+1) cur=tmp;
        }
        ans[k]=mp(l, 0);
        cur->queries.pb(mp(mp(l, r), k));
    }
    sort(all(all_states), [](const State* a, const State* b) { return a->l>b->l; });
    for(State* p: all_states) {
        if(p->original>0) {
            p->tr=insert(p->tr, p->original, 1);
            p->tr_sz+=1;
        }
        p->original=-1;
        if(p->tr) {
            for(const auto& kv: p->queries) {
                PII r=query(p->tr, kv.fi.fi, kv.fi.se);
                if(r.fi>0) ans[kv.se]=r;
            }
        }
        p->f->tr=merge(p->f->tr, p->f->tr_sz, p->tr, p->tr_sz);
        p->f->tr_sz+=p->tr_sz;
    }
    for(const auto& x: ans) printf("%d %d\n", x.fi,x.se);

    return 0;
}