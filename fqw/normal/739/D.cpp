// 9:53 - 10:48 - wa
#include <algorithm>
#include <map>
#include <set>
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

struct Entry {
    int dep, cir;
    int i;
};

vector<Entry> read_entries() {
    const auto parse=[](string s) {
        if(s=="?") return -1;
        return stoi(s);
    };
    int n; cin>>n;
    vector<Entry> entries(n);
    repn(i, n) {
        string d, c; cin>>d>>c;
        entries[i].dep=parse(d);
        entries[i].cir=parse(c);
        entries[i].i=i;
    }
    return entries;
}

struct BipartiteGraph {
    const int n, m;
    vector<vector<bool>> g;

    BipartiteGraph(int _n, int _m) : n(_n), m(_m), g(n, vector<bool>(m, false)) {}

    void add_edge(int i, int j) { g[i][j]=true; }

    VI match() {
        vector<int> lnk(m, -1), ans(n, -1);
        repn(cur, n) {
            vector<bool> vis(m, false);
            const function<bool(int)> find=[&](int i) {
                repn(j, m) if(g[i][j] && !vis[j]) {
                    vis[j]=true;
                    if(lnk[j]<0 || find(lnk[j])) {
                        lnk[j]=i, ans[i]=j;
                        return true;
                    }
                }
                return false;
            };
            if(!find(cur)) return VI();
        }
        return ans;
    }
};

struct FGraph {
    vector<Entry> circle;
    vector<Entry> leaves;
};

VI answers;

void build_functional_graph(FGraph g) {
    int cir=g.circle[0].cir;
    assert(sz(g.circle)==cir);
    map<int, VI> m;
    for(const auto& e: g.circle) m[0].pb(e.i);
    for(const auto& e: g.leaves) m[e.dep].pb(e.i);
    repn(i, cir) answers[m[0][i]]=m[0][(i+1)%cir];
    for(const auto& kv: m) if(kv.fi>0) {
        for(int i: kv.se) answers[i]=m[kv.fi-1][0];
    }
}

bool solve(int force_cir, int force_depth,
           map<int, vector<FGraph>> m, vector<Entry> entries) {
    struct Requirement {
        int dep, cir, c_index;
    };
    vector<Requirement> reqs;
    for(const auto& kv: m) {
        const int cir=kv.fi;
        repn(i, sz(kv.se)) {
            const FGraph& g=kv.se[i];
            repn(_, cir-sz(g.circle)) {
                reqs.pb({0, cir, i});
            }
            set<int> depths;
            if(cir==force_cir && i==0) {
                depths.insert(force_depth);
            } else {
                depths.insert(0);
            }
            for(const auto& e: g.leaves) {
                depths.insert(e.dep);
            }
            int max_depth=*depths.rbegin();
            rep(d, 1, max_depth) {
                if(depths.count(d)==0) {
                    reqs.pb({d, cir, i});
                }
            }
        }
    }
    //for(const auto& r: reqs) printf("%d %d %d\n", r.dep,r.cir,r.c_index);

    vector<bool> used(sz(entries), false);
    if(sz(reqs)>0) {
        BipartiteGraph g(sz(reqs), sz(entries));
        repn(i, sz(reqs)) repn(j, sz(entries)) {
            if(entries[j].cir>=0 && entries[j].cir!=reqs[i].cir) continue;
            if(entries[j].dep>=0 && entries[j].dep!=reqs[i].dep) continue;
            g.add_edge(i, j);
        }
        VI match=g.match();
        if(match.empty()) return false;

        repn(i, sz(reqs)) {
            int j=match[i];
            used[j]=true;
            entries[j].cir=reqs[i].cir;
            entries[j].dep=reqs[i].dep;
            if(reqs[i].dep==0) {
                m[reqs[i].cir][reqs[i].c_index].circle.pb(entries[j]);
            } else {
                m[reqs[i].cir][reqs[i].c_index].leaves.pb(entries[j]);
            }
        }
    }
    repn(i, sz(entries)) if(!used[i]) {
        auto& e=entries[i];
        if(e.cir>=0) {
            e.dep=1;
            m[e.cir][0].leaves.pb(e);
        } else if(e.dep!=0) {
            if(e.dep<0) e.dep=1;
            e.cir=force_cir;
            m[force_cir][0].leaves.pb(e);
        } else {
            e.cir=1;
            m[1].pb(FGraph());
            m[1].back().circle.pb(e);
        }
    }

    for(const auto& kv: m) {
        for(const auto& fg: kv.se) {
            build_functional_graph(fg);
        }
    }
    for(int i: answers) cout<<i+1<<" ";
    cout<<endl;
    return true;
}

int main() {
    auto entries=read_entries();
    answers.resize(sz(entries));

    map<int, vector<FGraph>> m;
    auto tmp=entries; entries.clear();
    for(const auto& e: tmp) {
        if(e.dep>=0 && e.cir>=0) {
            if(m.count(e.cir)==0) {
                m[e.cir].pb(FGraph());
            }
            if(e.dep==0) {
                if(sz(m[e.cir].back().circle)==e.cir) {
                    m[e.cir].pb(FGraph());
                }
                m[e.cir].back().circle.pb(e);
            } else {
                m[e.cir][0].leaves.pb(e);
            }
        } else {
            entries.pb(e);
        }
    }
    for(const auto& e: entries) {
        if(e.cir>=0 && m.count(e.cir)==0) {
            m[e.cir].pb(FGraph());
        }
    }
    if(m.empty()) {
        m[1].pb(FGraph());
    }

    int max_depth=0;
    for(const auto& e: entries) {
        setmax(max_depth, e.dep);
    }
    bool ok=false;
    for(auto& kv: m) {
        if(solve(kv.fi, max_depth, m, entries)) {
            ok=true;
            break;
        }
    }
    if(!ok) cout<<-1<<endl;
    return 0;
}