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
    int k; cin>>k;
    string s; cin>>s;
    int n=(int)s.size();
    int p[55];

    bool used[555]; fillchar(used, false);
    int i=0;
    bool ok=true;
    forn(z, k) {
        while(i<n && used[(int)s[i]]) ++i;
        if(i>=n) { ok=false; break; }
        used[(int)s[i]]=true;
        p[z]=i;
        ++i;
    }
    p[k]=n;

    if(ok) {
        printf("YES\n");
        forn(z, k) cout<<(s.substr(p[z], p[z+1]-p[z]))<<endl;
    }
    else printf("NO\n");

    return 0;
}