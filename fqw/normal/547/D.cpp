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

const int N=200000;
const int MAXN=N*2+10;

set<PII> es[MAXN];
set<PII> es2[MAXN];
int ans[MAXN];

void del(int x, int y) {
    es[x].erase(es[x].lower_bound(MP(y,0)));
    es[y].erase(es[y].lower_bound(MP(x,0)));
}

int main() {
    //ios_base::sync_with_stdio(false);
    forint(i, 1, N*2) es[i].clear();
    int n; //cin>>n;
    scanf("%d",&n);
    forint(i, 1, n) {
        int x, y; 
        //cin>>x>>y;
        scanf("%d%d",&x,&y);
        es[x].insert(MP(N+y,i));
        es[N+y].insert(MP(x,i));
    }

    set<int> os;
    forint(i, 1, N*2)
        if(es[i].size()%2!=0)
            os.insert(i);
    while(os.size()>0) {
        int x=*os.begin();
        int b=0;
        while(es[x].size()%2!=0) {
            os.erase(x);
            int y=es[x].begin()->fi;
            int i=es[x].begin()->se;

            ans[i]=b, b^=1;
            es2[x].insert(MP(y,i));
            es2[y].insert(MP(x,i));
            del(x, y);
            if(es[y].size()%2==0)
                os.erase(y);
            else
                os.insert(y);
            x=y;
        }
        //cout<<"x="<<x<<" y="<<y<<endl;
    }

    // go es
    forint(x0, 1, N*2) while(es[x0].size()>0) {
        int x=x0, cur=0;
        while(1) {
            int y=es[x].begin()->fi;
            int i=es[x].begin()->se;
        //cout<<"! x="<<x<<" y="<<y<<endl;
            ans[i]=cur, cur^=1;
            del(x, y);
            x=y; if(x==x0) break;
        }
    }

    //forint(i, 1, n) cout<<(ans[i]?'r':'b'); cout<<endl;
    forint(i, 1, n) printf("%c",ans[i]?'r':'b'); printf("\n");

    return 0;
}