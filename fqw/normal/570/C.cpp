// 20:23
// 20:26 - 
#include <cassert>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

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
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
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

char s[300010];
int n, m; 
int ans;
set<PII> p;

PII take(int i) {
    auto it=--p.lower_bound(mp(i+1, 0));
    PII r=*it; p.erase(it);
    ans-=r.se-r.fi;
    return r;
}

void put(PII r) {
    ans+=r.se-r.fi;
    p.insert(r);
}

void change(int i, char ch) {
    if(s[i]=='.' && ch=='.') return;
    if(s[i]!='.' && ch!='.') return;
    s[i]=ch;
    if(ch=='.') {
        PII cur=mp(i, i);
        if(i>1 && s[i-1]=='.') {
            cur.fi=take(i-1).fi;
        }
        if(i<n && s[i+1]=='.') {
            cur.se=take(i+1).se;
        }
        put(cur);
    } else {
        PII cur=take(i);
        if(i>cur.fi) put(mp(cur.fi, i-1));
        if(i<cur.se) put(mp(i+1, cur.se));
    }
}

int main() {
    scanf("%d%d", &n,&m);
    scanf("%s", s+1);

    int la=0;
    ans=0; p.clear();
    rep(i, 1, n+1) {
        if(i>n || s[i]!='.') {
            if(la>0) {
                put(mp(i-la, i-1));
                la=0;
            }
        } else
            ++la;
    }

    repn(k, m) {
        int i; char b[9];
        scanf("%d%s", &i,b);
        change(i, b[0]);
        printf("%d\n", ans);
    }
    return 0;
}