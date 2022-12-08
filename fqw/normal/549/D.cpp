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

int a[110][110], s[110][110];
int n, m;

int main() {
    scanf("%d%d", &n,&m);
    forint(i, 1, n) {
        char buf[110]; scanf("%s", buf+1);
        forint(j, 1, m) a[i][j]=(buf[j]=='W'?1:-1);
    }
    fillchar(s, 0);
    int ans=0;
    forintdown(i, n, 1) forintdown(j, m, 1) {
        s[i][j]=s[i+1][j]+s[i][j+1]-s[i+1][j+1];
        int d=a[i][j]-s[i][j];
        if(d!=0) {
            ans++;
            s[i][j]+=d;
        }
    }
    printf("%d\n", ans);
    return 0;
}