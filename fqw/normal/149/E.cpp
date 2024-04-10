// 8:07 - 8:24 - wa
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
    State* succ[26];
    State* f;
    bool is_end;
    int l, min_end=-1;

    State(int _l, bool _is_end, const State* copy=nullptr) : is_end(_is_end), l(_l) {
        if(copy) {
            f=copy->f;
            memcpy(succ, copy->succ, sizeof(succ));
        } else {
            f=nullptr;
            fillchar(succ, 0);
        }
    }
};

struct SAM {
    State *root, *last;
    vector<State*> all_states;

    void extend(int ch) {
        State *p=last, *np=new State(p->l+1, true);
        all_states.pb(np);
        for(; p && !p->succ[ch]; p=p->f) {
            p->succ[ch]=np;
        }
        if(!p) {
            np->f=root;
        } else {
            State *q=p->succ[ch];
            if(q->l==p->l+1) {
                np->f=q;
            } else {
                State *nq=new State(p->l+1, false, q);
                all_states.pb(nq);
                np->f=q->f=nq;
                for(; p && p->succ[ch]==q; p=p->f) {
                    p->succ[ch]=nq;
                }
            }
        }
        last=np;
    }

    SAM(const string& s) {
        last=root=new State(0, false);
        all_states.pb(root);
        for(char ch: s) {
            extend(ch-'A');
        }
        sort(all(all_states), [](const State* a, const State* b) { return a->l>b->l; });
        for(State* p: all_states) {
            p->min_end=p->is_end ?  p->l : p->min_end=numeric_limits<int>::max();
        }
        for(State* p: all_states) if(p->f) {
            setmin(p->f->min_end, p->min_end);
        }
    }
};

int main() {
    string s;
    cin>>s; SAM pro(s);
    reverse(all(s)); SAM rev(s);

    int num; cin>>num;
    int ans=0;
    while(num--) {
        string t; cin>>t;
        
        VI a(sz(t), -1);
        State* cur=pro.root;
        repn(i, sz(t)) {
            cur=cur->succ[t[i]-'A'];
            if(!cur) break;
            a[i]=cur->min_end;
        }

        bool ok=false;
        cur=rev.root;
        irepn(i, sz(t)) if(i>0) {
            cur=cur->succ[t[i]-'A'];
            if(!cur) break;
            if(a[i-1]>=0) {
                if(a[i-1]+cur->min_end<=sz(s)) {
                    ok=true;
                    break;
                }
            }
        }
        if(ok) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}