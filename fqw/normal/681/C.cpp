#include <set>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

struct Op {
    int type; // 1=insert, 2=get, 3=remove
    int val;
    Op(int t=0, int v=0) : type(t), val(v) {}
    void read() {
        static char buf[9];
        scanf("%s", buf);
        if(buf[0]=='i') type=1;
        if(buf[0]=='g') type=2;
        if(buf[0]=='r') type=3;
        if(type<3) scanf("%d", &val);
    }
    void println() const {
        if(type==1) printf("insert");
        if(type==2) printf("getMin");
        if(type==3) printf("removeMin");
        if(type<3) printf(" %d", val);
        printf("\n");
    }
};

int main() {
    int n; scanf("%d", &n);
    vector<Op> r;
    multiset<int> s;
    repn(i, n) {
        Op op; op.read();
        if(op.type==1) {
            r.pb(op);
            s.insert(op.val);
        } else if(op.type==2) {
            while(!s.empty() && *s.begin()<op.val) {
                r.pb(Op(3));
                s.erase(s.begin());
            }
            if(s.empty() || *s.begin()!=op.val) {
                r.pb(Op(1, op.val));
                s.insert(op.val);
            }
            r.pb(op);
        } else if(op.type==3) {
            if(s.empty()) {
                r.pb(Op(1, 0));
                s.insert(0);
            }
            r.pb(op);
            s.erase(s.begin());
        }
    }
    printf("%d\n", sz(r));
    for(const auto& op: r) op.println();
    return 0;
}