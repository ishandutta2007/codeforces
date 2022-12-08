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

const int MAXN=300010;
const int MAXV=1000010;

int a[MAXN], sum[MAXN]; PII ca[MAXN];
int n, k;

vector<PII> queries[MAXV];
vector<int> inds[MAXV];

LL tot(const VPI &q, const VI &is) {
    if(q.empty() || is.empty())
        return 0;
    VI nums;
    for(PII x: q) nums.PB(x.fi), nums.PB(x.se);
    for(int x: is) nums.PB(x);
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    VI s(nums.size(), 0);
    for(int x: is) {
        int i=int(lower_bound(all(nums), x)-nums.begin());
        s[i]++;
    }
    forn(i, s.size()-1) s[i+1]+=s[i];
    LL ans=0;
    for(PII x: q) {
        int i=int(lower_bound(all(nums), x.fi)-nums.begin());
        int j=int(lower_bound(all(nums), x.se)-nums.begin());
        ans+=s[j];
        if(i>0) ans-=s[i-1];
    }
    return ans;
}

int main() {
    scanf("%d%d", &n,&k); 
    sum[0]=a[0]=0;
    forint(i, 1, n) {
        scanf("%d", &ca[i].fi), ca[i].se=i;
        a[i]=ca[i].fi%k; sum[i]=(sum[i-1]+a[i])%k;
    }
    sort(ca+1, ca+n+1);

    forn(v, k) {
        queries[v].clear();
        inds[v].clear();
    }
    forint(i, 0, n)
        inds[sum[i]].PB(i);
    static int le[MAXN], ri[MAXN];
    static bool vis[MAXN]; 
    fillchar(vis, false);
    forint(z, 1, n) {
        int i=ca[z].se;
        int l=vis[i-1]?le[i-1]:i;
        int r=vis[i+1]?ri[i+1]:i;
        le[r]=l, ri[l]=r;
        vis[i]=true;
        if(vis[i-1]) {
            queries[sum[i-1]].PB(MP(l-1, i-2));
        }
        if(vis[i+1]) {
            queries[sum[i]].PB(MP(i+1, r));
        }
        if(vis[i-1] && vis[i+1]) {
            int x1=l-1, y1=i-2;
            int x2=i+1, y2=r;
            if(y1-x1<y2-x2) {
                forint(j, x1, y1) {
                    int want=(sum[j]+a[i])%k;
                    queries[want].PB(MP(x2, y2));
                }
            }
            else {
                forint(j, x2, y2) {
                    int want=(sum[j]-a[i]+k)%k;
                    queries[want].PB(MP(x1, y1));
                }
            }
        }
    }

    LL ans=0;
    forn(v, k) {
        //for(PII x: queries[v]) printf("query [%d,%d] %d\n", x.fi,x.se,v);
        ans+=tot(queries[v], inds[v]);
    }
    cout<<ans<<endl;

    return 0;
}