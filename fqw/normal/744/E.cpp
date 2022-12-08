#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
typedef unsigned long long ULL;
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

struct Hash {
    static constexpr LL M=LL(1e9)+7;
    LL v1; ULL v2;

    Hash(int v=0) : v1(v), v2(v) {}
    Hash(LL x, ULL y) : v1(x), v2(y) {}
    bool operator==(const Hash& h) const { return v1==h.v1 && v2==h.v2; }
    Hash operator+(const Hash& h) const { return Hash((v1+h.v1)%M, v2+h.v2); }
    Hash operator-(const Hash& h) const { return Hash((v1-h.v1+M)%M, v2-h.v2); }
    Hash operator*(const Hash& h) const { return Hash(v1*h.v1%M, v2*h.v2); }
    static Hash P() { return Hash(911, 1009); }
    static Hash pow_P(int n) {
        static vector<Hash> mem={Hash(1)};
        while(n>=sz(mem)) {
            mem.pb(mem.back()*Hash::P());
        }
        return mem[n];
    }

    struct Hasher {
        size_t operator()(const Hash& h) const {
            return h.v1^h.v2;
        }
    };
};

struct StringHash {
    const int n;
    vector<Hash> vs;

    StringHash(const string& s) : n(sz(s)) {
        vs.resize(n+1);
        repn(i, n) {
            vs[i+1]=vs[i]*Hash::P()+Hash(s[i]);
        }
    }

    Hash value() const { return substr(0, n); }
    Hash prefix(int len) const { return substr(0, len); }
    Hash suffix(int len) const { return substr(n-len, n); }
    Hash substr(int l, int r) const { return vs[r]-vs[l]*Hash::pow_P(r-l); }
};

bool find_circle_without_0(const vector<VI>& es) {
    bool found=false;
    VI vis(sz(es));
    const function<void(int)> dfs=[&](int x) {
        vis[x]=-1;
        for(int y: es[x]) if(y!=0) {
            if(vis[y]<0) {
                found=true; return;
            }
            if(vis[y]==0) {
                dfs(y);
                if(found) return;
            }
        }
        vis[x]=1;
    };
    replr(i, 1, sz(es)) if(vis[i]==0) dfs(i);
    return found;
}

bool find_large_circle_with_0(const vector<VI>& es) {
    unordered_set<int> start;
    for(int x: es[0]) for(int y: es[x]) if(y!=0) start.insert(y);
    vector<bool> vis(sz(es));
    queue<int> que;
    for(int x: start) {
        vis[x]=true; que.push(x);
    }
    while(!que.empty()) {
        const int x=que.front();
        que.pop();
        for(int y: es[x]) {
            if(y==0) return true;
            if(!vis[y]) {
                vis[y]=true;
                que.push(y);
            }
        }
    }
    return false;
}

bool check(const VS& ss) {
    unordered_map<Hash, int, Hash::Hasher> id;
    vector<VI> es;
    const auto get_id=[&](const Hash& h) {
        const auto it=id.find(h);
        if(it==id.end()) {
            int i=sz(es);
            es.pb(VI());
            return id[h]=i;
        }
        return it->se;
    };
    get_id(Hash());
    vector<Hash> hashs;
    for(const auto& s: ss) {
        hashs.pb(StringHash(s).value());
    }
    for(const auto& s: ss) {
        const StringHash h(s);
        rep(i, 0, sz(s)) {
            const int a=get_id(h.prefix(i));
            const int b=get_id(h.suffix(sz(s)-i));
            es[a].pb(b);
        }
        repn(i, sz(s)) {
            repn(k, sz(ss)) {
                if(i+sz(ss[k])<=sz(s) && h.substr(i, i+sz(ss[k]))==hashs[k]) {
                    const int a=get_id(h.suffix(sz(s)-i));
                    const int b=get_id(h.suffix(sz(s)-i-sz(ss[k])));
                    es[a].pb(b);
                }
            }
        }
    }
    return !find_circle_without_0(es) && !find_large_circle_with_0(es);
}

int main() {
    //cout<<check({"ab", "b", "bba"})<<endl;

    int n; scanf("%d", &n);
    VS ss;
    repn(i, n) {
        static char s[100010];
        scanf("%s", s);
        ss.pb(string(s));
    }
    int i=0, ans=0;
    repn(j, n) {
        VS tmp;
        irep(k, j, i) tmp.pb(ss[k]);
        while(!check(tmp)) {
            tmp.pop_back();
            ++i;
        }
        //printf("%d %d\n",i,j);
        ans+=j-i+1;
    }
    printf("%d\n", ans);
    return 0;
}