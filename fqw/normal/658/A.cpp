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

const int N=55;

int p[N], t[N], n, c;

int main() {
    cin>>n>>c;
    rep(i, 1, n) cin>>p[i];
    rep(i, 1, n) cin>>t[i];
    auto score=[&](int i, int x) { return max(0, p[i]-c*x); };

    int s1=0, x1=0;
    rep(i, 1, n) {
        x1+=t[i]; s1+=score(i, x1);
    }
    int s2=0, x2=0;
    irep(i, n, 1) {
        x2+=t[i]; s2+=score(i, x2);
    }
    //cout<<s1<<" "<<s2<<endl;
    if(s1>s2) printf("Limak\n");
    else if(s1<s2) printf("Radewoosh\n");
    else printf("Tie\n");

    return 0;
}