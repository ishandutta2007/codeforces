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

const int N=2000010;

bool is_prime[N];
VI ans;

void update(const vector<int>& r) {
    if(sz(r)>sz(ans)) ans=r;
}

int main() {
    fillchar(is_prime, true);
    rep(i, 2, N-1) if(is_prime[i]) {
        for(int j=i*2; j<N; j+=i) is_prime[j]=false;
    }
    int n; cin>>n;
    VI a(n); for(int& x: a) cin>>x;

    update({a[0]});
    repn(i, n) rep(j, i+1, n-1) if(is_prime[a[i]+a[j]]) {
        update({a[i], a[j]});
    }

    VI r;
    for(int x: a) if(x==1) r.pb(x);
    for(int x: a) if(x>1 && is_prime[x+1]) { r.pb(x); break; }
    update(r);

    cout<<sz(ans)<<endl;
    for(int x: ans) cout<<x<<" "; cout<<endl;


    return 0;
}