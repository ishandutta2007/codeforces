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

int f[200010], s[200010];
int gf(int x) {
    return f[x]==0?x:(f[x]=gf(f[x]));
}

bool vis[200010];
int a[200010], ans[200010];
int n, maxs;

void unite(int i, int j) {
    i=gf(i), j=gf(j);
    assert(i!=j);
    s[i]+=s[j]; f[j]=i;
    setmax(maxs, s[i]);
}

int main() {
    cin>>n; forint(i, 1, n) cin>>a[i];
    VPI es; forint(i, 1, n) es.PB(MP(a[i], i));
    sort(all(es), greater<PII>());

    fillchar(f, 0);
    fillchar(vis, false);
    int cur=0; maxs=1;
    for(auto e: es) {
        int i=e.se, val=e.fi;
        s[i]=1; vis[i]=true;
        if(vis[i-1]) unite(i, i-1);
        if(vis[i+1]) unite(i, i+1);
        while(cur<=maxs) {
            ans[cur]=val;
            ++cur;
        }
    }
    forint(i, 1, n) cout<<ans[i]<<" "; cout<<endl;

    return 0;
}