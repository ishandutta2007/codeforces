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
typedef long double LD;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

const int N=20;

double p[N]; LD f[1<<N];
int n, k;

int main() {
    scanf("%d%d", &n,&k);
    int m=0;
    repn(i, n) {
        scanf("%lf", &p[i]);
        if(p[i]>0) ++m;
    }
    setmin(k, m);

    fillchar(f, 0); f[0]=1;
    repn(s, (1<<n)-1) {
        LD r=0;
        repn(i, n) if((s&(1<<i))==0) r+=p[i];
        if(r>0) {
            repn(i, n) if((s&(1<<i))==0) {
                f[s|(1<<i)]+=f[s]*(LD)p[i]/r;
            }
        }
    }

    vector<LD> ans(n);
    repn(s, 1<<n) {
        int cnt=0; repn(i, n) if(s&(1<<i)) ++cnt;
        if(cnt==k) {
            repn(i, n) if(s&(1<<i)) ans[i]+=f[s];
        }
    }
    repn(i, n) printf("%.9lf ", (double)ans[i]); printf("\n");

    return 0;
}