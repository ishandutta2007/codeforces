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

char a[110][110];
int guess[110], s[110], x[110];
int n;

void go(int i) {
    assert(x[i]==0);
    x[i]=1;
    forint(j, 1, n) if(a[i][j]=='1')
        ++s[j];
}

int main() {
    scanf("%d", &n);
    forint(i, 1, n) scanf("%s", a[i]+1);
    forint(i, 1, n) scanf("%d", &guess[i]);

    fillchar(s, 0);
    fillchar(x, 0);

    while(1) {
        bool found=false;
        forint(i, 1, n) if(s[i]==guess[i]) {
            go(i);
            found=true;
        }
        if(!found) break;
    }
    int cnt=0;
    forint(i, 1, n) cnt+=x[i];
    printf("%d\n",cnt);
    forint(i, 1, n) if(x[i]) printf("%d ", i); printf("\n");

    return 0;
}