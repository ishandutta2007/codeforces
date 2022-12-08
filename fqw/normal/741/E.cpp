#include <algorithm>
#include <numeric>
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

template<int N>
struct RMQ {
    int log[N+1];

    int val[20][N];

    RMQ() {
        for(int k=0; (1<<k)<=N; ++k) {
            replr(i, 1<<k, 1<<(k+1)) log[i]=k;
        }
    }

    void init(const int* a, int n) {
        int k=log[n];
        repn(i, n) {
            val[0][i]=a[i];
        }
        repn(j, k) {
            repn(i, n-(1<<j)) {
                val[j+1][i]=min(val[j][i], val[j][i+(1<<j)]);
            }
        }
    }

    void init(const VI& a) {
        init(&a[0], sz(a));
    }

    int query(int l, int r) const {
        int j=log[r-l];
        return min(val[j][l], val[j][r-(1<<j)]);
    }
};

struct LCP {
    struct Node {
        const int len;
        Node *succ[26], *f;

        vector<Node*> children;
        int label;

        Node(int l, Node* copy=nullptr) : len(l) {
            if(copy) {
                memcpy(succ, copy->succ, sizeof(succ));
                f=copy->f;
            } else {
                fillchar(succ, 0);
                f=nullptr;
            }
        }
    } *root, *last;
    vector<Node*> nodes;
    vector<Node*> all_nodes;

    Node* extend(int ch) {
        Node *p=last, *np=new Node(p->len+1);
        all_nodes.pb(np);
        for(; p && !p->succ[ch]; p=p->f) {
            p->succ[ch]=np;
        }
        if(!p) {
            np->f=root;
        } else {
            Node *q=p->succ[ch];
            if(q->len==p->len+1) {
                np->f=q;
            } else {
                Node *nq=new Node(p->len+1, q);
                all_nodes.pb(nq);
                q->f=np->f=nq;
                for(; p && p->succ[ch]==q; p=p->f) {
                    p->succ[ch]=nq;
                }
            }
        }
        return last=np;
    }

    RMQ<800010> rmq;

    LCP(const string& s) {
        root=last=new Node(0);
        nodes.resize(sz(s));
        irepn(i, sz(s)) {
            nodes[i]=extend(s[i]-'a');
        }
        sort(all(all_nodes), [](Node* x, Node* y) { return x->len<y->len; });
        for(Node* p: all_nodes) p->f->children.pb(p);

        VI arr;
        const function<void(Node*)> dfs=[&](Node* p) {
            p->label=sz(arr);
            arr.pb(p->len);
            for(Node* q: p->children) {
                dfs(q);
                arr.pb(p->len);
            }
        };
        dfs(root);
        rmq.init(arr);
    }
    int query(int i, int j) const {
        if(i==j) return 1<<20;
        i=nodes[i]->label;
        j=nodes[j]->label;
        if(i>j) swap(i, j);
        return rmq.query(i, j+1);
    }
};

VI compute_ranks(const string& s, const string& t) {
    const string str=s+t;
    LCP *lcp=new LCP(str);
    const auto make=[&](int i) {
        VPI r;
        if(i<sz(s)) r.pb(mp(i, sz(s)));
        r.pb(mp(sz(s), sz(str)));
        if(i>0) r.pb(mp(0, i));
        return r;
    };
    const auto compare=[&](int i, int j) {
        VPI x=make(i), y=make(j);
        while(!x.empty() && !y.empty()) {
            int xi=x.back().fi, xlen=x.back().se-xi;
            int yi=y.back().fi, ylen=y.back().se-yi;
            int len=lcp->query(xi, yi);
            if(len<min(xlen, ylen)) {
                return str[xi+len]<str[yi+len];
            }
            if(xlen<=ylen) x.pop_back(); else x.back().fi+=ylen;
            if(ylen<=xlen) y.pop_back(); else y.back().fi+=xlen;
        }
        return i<j;
    };
    VI is(sz(s)+1);
    iota(all(is), 0);
    sort(all(is), compare);
    VI ranks(sz(s)+1);
    repn(i, sz(s)+1) ranks[is[i]]=i;
    return ranks;
}

int up_to_mod(int i, int a, int b) {
    int delta=b-i%a;
    if(delta<0) delta+=a;
    return i+delta;
}

int down_to_mod(int i, int a, int b) {
    int delta=i%a-b;
    if(delta<0) delta+=a;
    return i-delta;
}

void solve(VI a) {
    const int N=100001;

    VI index(sz(a));
    repn(i, sz(a)) index[a[i]]=i;
    static RMQ<N> large;
    large.init(a);
    const int kSmall=80;

    int qn; scanf("%d", &qn);
    struct Query {
        int l, r, k, x, y;
        int ans=1<<30;
        void read() { scanf("%d%d%d%d%d", &l,&r,&k,&x,&y); }
    };
    vector<Query> qs(qn);
    for(Query& q: qs) {
        q.read();
        if(q.k>=kSmall) {
            while(q.x<sz(a)) {
                int l0=max(q.l, q.x), r0=min(q.r, q.y);
                if(l0<=r0) {
                    setmin(q.ans, large.query(l0, r0+1));
                }
                q.x+=q.k, q.y+=q.k;
            }
        }
    }
    replr(k, 1, kSmall) {
        static int b[N], pos[N];
        int cur=0;
        repn(i, k) {
            for(int j=i; j<sz(a); j+=k) {
                b[cur]=a[j];
                pos[j]=cur;
                ++cur;
            }
        }
        static RMQ<N> rmq;
        rmq.init(b, cur);
        for(Query& q: qs) if(q.k==k) {
            rep(i, q.x, q.y) {
                int l0=up_to_mod(q.l, k, i);
                int r0=down_to_mod(q.r, k, i);
                if(l0<=r0) {
                    setmin(q.ans, rmq.query(pos[l0], pos[r0]+1));
                }
            }
        }
    }
    for(const auto& q: qs) {
        if(q.ans<sz(a)) printf("%d ", index[q.ans]);
        else printf("-1 ");
    }
    printf("\n");
}

int main() {
    static char buf[100010];
    scanf("%s", buf); string s(buf);
    scanf("%s", buf); string t(buf);
    VI ranks=compute_ranks(s, t);
    solve(ranks);
    return 0;
}