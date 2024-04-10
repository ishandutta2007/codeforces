// 8:49 - 9:11 - wa
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

const auto read_string=[] { 
    static char buf[1000010];
    scanf("%s", buf);
    return string(buf);
};

struct State {
    const int l;
    State *succ[26], *f;
    State(int _l, const State* copy=nullptr) : l(_l) {
        if(copy) {
            f=copy->f;
            memcpy(succ, copy->succ, sizeof(succ));
        } else {
            f=nullptr;
            fillchar(succ, 0);
        }
    }

    vector<State*> children;
    int x=-1, y=-1;
} *root, *last;
vector<State*> all_states;

void extend(int ch) {
    State *p=last, *np=new State(p->l+1);
    all_states.pb(np);
    for(; p && !p->succ[ch]; p=p->f) {
        p->succ[ch]=np;
    }
    if(!p) {
        np->f=root;
    } else {
        State* q=p->succ[ch];
        if(q->l==p->l+1) {
            np->f=q;
        } else {
            State* nq=new State(p->l+1, q);
            all_states.pb(nq);
            np->f=q->f=nq;
            for(; p && p->succ[ch]==q; p=p->f) {
                p->succ[ch]=nq;
            }
        }
    }
    if(np->f->l==np->l) {
        np=np->f;
    }
    last=np;
}

struct FenwickTree {
    VI tr;
    FenwickTree(int n) : tr(n+1) {}

    void _add(int i, int val) {
        ++i;
        for(; i<sz(tr); i+=i&-i) tr[i]+=val;
    }

    void add(int l, int r, int val) {
        _add(l, val);
        _add(r, -val);
    }

    int get(int i) {
        ++i;
        int ans=0;
        for(; i>0; i-=i&-i) ans+=tr[i];
        return ans;
    }
};

int main() {
    int num, n; scanf("%d%d", &num, &n);
    last=root=new State(0);
    all_states.pb(root);
    vector<State*> states;
    repn(i, n) {
        last=root;
        const string s=read_string();
        for(char ch: s) {
            extend(ch-'a');
        }
        /*
        State* p=root;
        for(char ch: s) {
            p=p->succ[ch-'a'];
        }
        states.pb(p);
        */
        states.pb(last);
    }
    for(State* p: all_states) {
        if(p->f) p->f->children.pb(p);
    }
    int label=0;
    const function<void(State*)> dfs=[&label,&dfs](State* p) {
        p->x=label++;
        for(State* q: p->children) {
            dfs(q);
        }
        p->y=label;
    };
    dfs(root);

    FenwickTree tr(label);
    vector<bool> inside(n, true);
    repn(i, n) {
        tr.add(states[i]->x, states[i]->y, 1);
    }
    while(num--) {
        string s=read_string();
        if(s[0]=='?') {
            State* x=root;
            int len=0;
            LL ans=0;
            for(char c: s.substr(1)) {
                const int ch=c-'a';
                while(x!=root && !x->succ[ch]) {
                    x=x->f, len=x->l;
                }
                if(x->succ[ch]) {
                    x=x->succ[ch], ++len;
                }
                if(len==x->l) {
                    ans+=tr.get(x->x);
                } else {
                    ans+=tr.get(x->f->x);
                }
            }
            printf("%lld\n", ans);
        } else if(s[0]=='+') {
            int i=int(stoi(s.substr(1)))-1;
            if(!inside[i]) {
                inside[i]=true;
                tr.add(states[i]->x, states[i]->y, 1);
            }
        } else if(s[0]=='-') {
            int i=int(stoi(s.substr(1)))-1;
            if(inside[i]) {
                inside[i]=false;
                tr.add(states[i]->x, states[i]->y, -1);
            }
        }
    }
    return 0;
}