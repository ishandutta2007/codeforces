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


// ------------------------ template ends here ------------------------ //

int main() {
    int k, n; scanf("%d%d", &n,&k);
    int x=0, y=0;
    while(n--) {
        int a; scanf("%d", &a);
        if(a%2==1) ++x; else ++y;
    }
    bool ans=false;
    if(x+y==k) ans=(x%2==1);
    else {
        if(x-y>=k) ans=(k%2==1);
        else if(y-x>=k) ans=false;
        else {
            ans=((x-y+k)%2==1);
        }
    }
    printf("%s\n", ans?"Stannis":"Daenerys");
    /*
    int n=15, k=3;
    int f[99][99], g[99][99];
    fillchar(f, 0); fillchar(g, 0);
    forint(i, 0, n+1) f[i][0]=f[0][i]=1;
    forint(i, 0, n+1) g[i][0]=g[0][i]=1;
    forint(i, 0, n) forint(j, 0, n) {
        if(i+j<k) continue;
        if(i+j==k) {
            f[i+1][j+1]=(i%2==1);
            g[i+1][j+1]=(i%2==0);
            continue;
        }
        f[i+1][j+1]=(!g[i][j+1] || !g[i+1][j]);
        g[i+1][j+1]=(!f[i][j+1] || !f[i+1][j]);
    }
    forint(i, 0, n) { forint(j, 0, n) {
        if(i+j==k) printf("# ");
        else printf("%d ", f[i+1][j+1]);
    }
        printf("\n");
    }


    fillchar(g, 0);
    forint(i, 0, n) forint(j, 0, n) {
        int &ans=g[i+1][j+1];
        if(i+j<=k) continue;

        if(i-j>=k) {
            ans=(k%2==1?1:0);
            continue;
        }
        if(j-i>=k) {
            ans=0;
            continue;
        }
        ans=((i-j+k)%2==1);
    }

        printf("\n");

    forint(i, 0, n) { forint(j, 0, n) {
        if(i+j>k) assert(g[i+1][j+1]==f[i+1][j+1]);
        if(i+j==k) printf("# ");
        else printf("%d ", g[i+1][j+1]);
    }
        printf("\n");
    }
    */

    return 0;
}