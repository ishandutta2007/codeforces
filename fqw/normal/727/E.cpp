#include <algorithm>
#include <set>
#include <map>
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

string read_str() {
    static char buf[2001000];
    scanf("%s", buf);
    return string(buf);
}

VS read_VS() {
    int n; scanf("%d", &n);
    VS a(n);
    for(string& s: a) s=read_str();
    return a;
}

const LL P=911;
const LL P2=127;
const LL M=LL(1e9)+7;

int main() {
    int n, k; scanf("%d%d", &n,&k);
    string s=read_str(); s=s+s;
    VS games=read_VS();

    map<pair<LL,ULL>, int> m;
    repn(i, sz(games)) {
        LL h=0; ULL h2=0;
        for(char c: games[i]) {
            h=(h*P+c)%M;
            h2=h2*P2+c;
        }
        m[mp(h,h2)]=i;
    }
    LL h=0, pk=1;
    ULL h2=0, pk2=1;
    repn(i, k) {
        h=(h*P+s[i])%M; pk=(pk*P)%M;
        h2=h2*P2+s[i]; pk2=pk2*P2;
    }
    VI match(n*k, -1);
    repn(i, n*k) {
        if(m.count(mp(h,h2))) match[i]=m[mp(h,h2)];
        h=((h*P+s[i+k]-LL(s[i])*pk)%M+M)%M;
        h2=h2*P2+s[i+k]-ULL(s[i])*pk2;
    }

    repn(i, k) {
        set<int> used;
        VI r;
        bool ok=true;
        for(int j=i; j<n*k; j+=k) {
            if(match[j]<0 || used.count(match[j])) {
                ok=false; break;
            }
            used.insert(match[j]);
            r.pb(match[j]);
        }
        if(ok) {
            printf("YES\n");
            for(int x: r) printf("%d ", x+1);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}