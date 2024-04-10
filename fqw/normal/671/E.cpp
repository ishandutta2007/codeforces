#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <functional>
#include <map>
#include <memory>
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
typedef pair<LL,int> PLI;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=100010;

class SegTree {
    struct Node {
        PLI minv;
        LL buf;
    } tr_[N*4];
    int n_;

#define MID int mid=(s+t)/2;
#define UPT tr_[x].minv=min(tr_[x*2].minv, tr_[x*2+1].minv);

    void push(int x, LL val) {
        tr_[x].minv.fi+=val;
        tr_[x].buf+=val;
    }
    void release(int x) {
        if(tr_[x].buf!=0) {
            push(x*2, tr_[x].buf);
            push(x*2+1, tr_[x].buf);
            tr_[x].buf=0;
        }
    }

    void init(int x, int s, int t, const LL val[]) {
        tr_[x].buf=0;
        if(s==t) {
            tr_[x].minv=mp(val[s], s);
        } else {
            MID;
            init(x*2, s, mid, val);
            init(x*2+1, mid+1, t, val);
            UPT;
        }
    }
    void add(int x, int s, int t, int st, int en, LL val) {
        if(st<=s && t<=en) {
            push(x, val); return;
        }
        release(x);
        MID;
        if(st<=mid) add(x*2, s, mid, st, en, val);
        if(mid<en) add(x*2+1, mid+1, t, st, en, val);
        UPT;
    }
    PLI getmin(int x, int s, int t, int st, int en) {
        if(st<=s && t<=en) {
            return tr_[x].minv;
        }
        release(x);
        MID;
        PLI r(1LL<<55, 1<<30);
        if(st<=mid) setmin(r, getmin(x*2, s, mid, st, en));
        if(mid<en) setmin(r, getmin(x*2+1, mid+1, t, st, en));
        UPT;
        return r;
    }
public:
    void init(int n) {
        static LL val[N]; fillchar(val, 0);
        init(n, val);
    }
    void init(int n, const LL val[]) {
        n_=n;
        init(1, 1, n_, val);
    }
    void add(int st, int en, LL val) {
        add(1, 1, n_, st, en, val);
    }
    PLI getmin(int st, int en) {
        return getmin(1, 1, n_, st, en);
    }
    LL get(int i) { return getmin(i, i).fi; }

    PLI get_first_neg(int st, int en) {
        if(st==en) return getmin(st, en);
        int mid=(st+en)/2;
        if(getmin(st, mid).fi<0) return get_first_neg(st, mid);
            else return get_first_neg(mid+1, en);
    }
    int get_last_le(LL limit) {
        int x=1, s=1, t=n_;
        while(s<t) {
            release(x);
            MID;
            if(tr_[x*2+1].minv.fi<=limit) {
                s=mid+1; x=x*2+1;
            } else {
                t=mid; x=x*2;
            }
        }
        return tr_[x].minv.fi<=limit ? s : -1;
    }
} r, f, g, h, z;

LL a[N], a2[N], w[N];
int n;
void dump() {
    auto print=[&](string name, SegTree& t) {
        cout<<name<<":";
        rep(i, 1, n) cout<<" "<<t.get(i);
        cout<<endl;
    };
    print("r", r);
    print("f", f);
    print("g", g);
    print("h", h);
}

void add_f(int st, int en, LL val) {
    f.add(st, en, val);
    z.add(st, en, val);
}

void add_r(int st, int en, LL val) {
    r.add(st, en, val);
}

void dec_h(int st, int en, LL val) {
    val=min(val, h.getmin(st, en).fi);
    h.add(st, en, -val);
    z.add(st, en, -val);
}

void dec_g(int st, int en, LL val) {
    int ind=en;
    while(st<=ind && val>0) {
        auto p=g.getmin(st, ind);
        LL delta=min(val, p.fi);
        g.add(st, ind, -delta);
        dec_h(st+1, ind, delta);
        if(ind<n) dec_h(ind+1, ind+1, delta);
        val-=delta, ind=p.se-1;
    }
}

void add_a(int i, LL val) {
    a2[i]+=val;
    add_f(i+1, n, val);
    add_r(i+1, n, val);
    dec_g(i, n, val);
}

int main() {
    //*
    LL limit; cin>>n>>limit;
    rep(i, 1, n-1) cin>>w[i];
    rep(i, 1, n) { cin>>a[i]; a2[i]=a[i]; }
    /*/
    srand(123);
    n=100000; LL limit=1000000000;
    rep(i, 1, n-1) w[i]=rand()+1;
    rep(i, 1, n) a[i]=a2[i]=rand();
    //*/

    static LL tmp[N];
    tmp[1]=0;
    rep(i, 2, n) tmp[i]=tmp[i-1]+a[i-1]-w[i-1];
    r.init(n, tmp);
    f.init(n);
    tmp[1]=0;
    rep(i, 2, n) tmp[i]=max(0ll, tmp[i-1]+w[i-1]-a[i]);
    g.init(n, tmp);
    h.init(n, tmp);
    z.init(n, tmp);

    int ans=1;
    rep(cur, 1, n-1) {
        /*
        cout<<"cur="<<cur<<endl;
        tmp[cur]=0;
        rep(i, cur+1, n) {
            tmp[i]=max(0ll, tmp[i-1]+w[i-1]-a2[i]);
            assert(tmp[i]==g.get(i));
            LL th=max(0ll, tmp[i-1]+w[i-1]-a[i]);
            cout<<"i="<<i<<" g="<<g.get(i)<<" th="<<th<<" h="<<h.get(i)<<" a2="<<a2[i]<<endl;
            assert(th==h.get(i));
        }
        */

        //cout<<"cur="<<cur<<endl; dump();
        while(1) {
            auto p=r.get_first_neg(cur, n);
            if(p.fi>=0) break;
            add_a(p.se-1, -p.fi);
        }


        //cout<<">>>"<<cur<<endl; dump();
        int i=z.get_last_le(limit);
        if(i>cur) setmax(ans, i-cur+1);

        add_r(cur+1, n, -(a2[cur]-w[cur]));
        add_f(cur+1, n, -(a2[cur]-a[cur]));
        dec_g(cur+1, n, g.get(cur+1));
        dec_h(cur+1, cur+1, h.get(cur+1));
    }
    cout<<ans<<endl;

    return 0;
}