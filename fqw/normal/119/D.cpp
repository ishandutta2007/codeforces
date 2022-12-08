// 7:51
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

struct StringHash {
    static constexpr LL M=LL(1e9)+7;
    static constexpr LL P=LL(911);
    const string s;
    vector<LL> h, pows;

    StringHash(string _s) : s(_s) {
        h.resize(sz(s)+1);
        h[0]=0;
        repn(i, sz(s)) h[i+1]=(h[i]*P+s[i])%M;
        pows.resize(sz(s)+1);
        pows[0]=1;
        repn(i, sz(s)) pows[i+1]=pows[i]*P%M;
    }

    bool equals(int i, int j, int len) {
        const LL hi=((h[i+len]-h[i]*pows[len])%M+M)%M;
        const LL hj=((h[j+len]-h[j]*pows[len])%M+M)%M;
        if(hi==hj) {
            repn(k, len) if(s[i+k]!=s[j+k]) return false;
            return true;
        }
        return false;
    }
};

VI match(string a, string b) {
    VI next(sz(a)+1);
    int j=next[0]=-1;
    repn(i, sz(a)) {
        while(j>=0 && a[j]!=a[i]) j=next[j];
        next[i+1]=++j;
    }
    VI ans(sz(b));
    j=0;
    repn(i, sz(b)) {
        while(j>=0 && a[j]!=b[i]) j=next[j];
        ans[i]=++j;
    }
    return ans;
}

string rev(string a) { reverse(all(a)); return a; }

PII solve() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    if(sz(a)!=sz(b)) {
        return mp(-1, -1);
    }
    const int n=sz(a);

    StringHash hash(a+b);
    VI matches=match(rev(a), b);
    int maxi=0;
    while(maxi+1<n && a[maxi]==b[n-1-maxi]) ++maxi;
    irepn(i, maxi) {
        const int j=n-matches[n-i-2];
        if(j==n) continue;
        if(hash.equals(i+1, n, j-i-1)) {
            return mp(i, j);
        }
    }
    return mp(-1, -1);
}

int main() {
    const auto ans=solve();
    cout<<ans.fi<<" "<<ans.se<<endl;
    return 0;
}