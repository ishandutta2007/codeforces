#include <algorithm>
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


int main() {
    int n, m, b, MOD;
    int a[510];
    cin>>n>>m>>b>>MOD;
    forint(i, 1, n) cin>>a[i];

    int f[510][510];
    fillchar(f, 0);
    f[0][0]=1;
    forint(i, 1, n) {
        forint(j, 0, m) forint(k, 0, b) {
            if(j+1<=m && k+a[i]<=b)
                (f[j+1][k+a[i]]+=f[j][k])%=MOD;
        }
    }
    int ans=0;
    forint(k, 0, b) (ans+=f[m][k])%=MOD;

    cout<<ans<<endl;

    return 0;
}