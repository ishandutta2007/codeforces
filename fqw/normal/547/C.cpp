#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

const int V=500000;
const int MAXV=V+10;
const int MAXN=200010;

LL mu[MAXV], g[MAXV], x[MAXV], ans;
int a[MAXN], n, q;
bool inside[MAXN];

void add(int i, int delta) { // x[i]+=delta
    ans-=g[i]*mu[i];
    x[i]+=delta;
    g[i]=x[i]*(x[i]-1)/2;
    ans+=g[i]*mu[i];
}

int main() {
    ios_base::sync_with_stdio(false);

    fillchar(mu, 0);
    mu[1]=1;
    forint(i, 1, V)
        for(int j=i*2; j<=V; j+=i)
            mu[j]-=mu[i];

    cin>>n>>q;
    forint(i, 1, n) cin>>a[i];
    fillchar(x, 0);
    fillchar(g, 0);
    fillchar(inside, false);
    ans=0;
    while(q--) {
        int i; cin>>i;
        inside[i]=!inside[i];
        int delta=inside[i]?1:-1;

        for(int j=1; j*j<=a[i]; j++)
            if(a[i]%j==0) {
                add(j, delta);
                if(j*j<a[i])
                    add(a[i]/j, delta);
            }
        //forint(i, 1, V) if(g[i]) cout<<"g["<<i<<"]="<<g[i]<<endl;
        cout<<ans<<endl;
    }


    return 0;
}