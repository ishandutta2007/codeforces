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

struct State {
    State *f=nullptr, *succ[26]={nullptr};
    int len, val;
    int mark=-1;

    State(int l, int v, const State* from=nullptr) {
        if(from!=nullptr) {
            *this=*from;
        }
        len=l, val=v;
    }
} *last, *root;
vector<State*> all_states;

void extend(int ch) {
    State *p=last, *np=new State(last->len+1, 1);
    all_states.pb(np);
    for(; p && !p->succ[ch]; p=p->f) {
        p->succ[ch]=np;
    }
    if(p==nullptr) {
        np->f=root;
    } else {
        State *q=p->succ[ch];
        if(q->len==p->len+1) {
            np->f=q;
        } else {
            State *nq=new State(p->len+1, 0, q);
            all_states.pb(nq);
            np->f=q->f=nq;
            for(; p && p->succ[ch]==q; p=p->f) {
                p->succ[ch]=nq;
            }
        }
    }
    last=np;
}

void go(State* &p, int& l, int ch) {
    while(p && !p->succ[ch]) {
        p=p->f, l=(p?p->len:0);
    }
    if(p) {
        p=p->succ[ch], ++l;
    } else {
        p=root, l=0;
    }
}

int main() {
    static char buf[1001000];
    scanf("%s", buf);
    int n=(int)strlen(buf);

    root=last=new State(0, 0);
    repn(i, n) extend(int(buf[i]-'a'));
    sort(all(all_states), [](State* const p, State* const q) { return p->len>q->len; });
    for(const auto& p: all_states) {
        p->f->val+=p->val;
    }

    int num; scanf("%d", &num);
    while(num--) {
        scanf("%s", buf);
        int len=(int)strlen(buf);
        State* p=root;
        int l=0;
        repn(i, len) go(p, l, int(buf[i]-'a'));
        int ans=0;
        repn(i, len) {
            go(p, l, int(buf[i]-'a'));
            while(p->f && p->f->len>=len) {
                p=p->f, l=p->len;
            }
            if(l>=len && p->mark!=num) {
                p->mark=num;
                ans+=p->val;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}