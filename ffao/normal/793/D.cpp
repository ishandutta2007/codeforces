#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rep(i, a) for(int i = 0; i < (a); ++i)

vector< pair<int, int> > g[110];
int n, m, k;
int pd[110][110][110][2];

int rec(int l, int r, int need, bool at) {
    if (need == 0) return 0;
    int can = r-l-1;
    if (can < need) return 100000;

    int &ret = pd[l][r][need][at];
    if (ret == -1) {
        ret = 100000;

        int curv = l;
        if (at) curv = r;

        for (pii p : g[curv]) {
            int x = p.first;
            int c = p.second;

            if (l < x && x < r) {
                ret = min(ret, c + rec(l, x, need-1, true));
                ret = min(ret, c + rec(x, r, need-1, false));
            }
        }
    }
    
    return ret;
}

int main() {
    memset(pd,-1,sizeof(pd));
    scanf("%d %d", &n, &k);
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c);
        g[u].push_back({v,c});
    }

    int ans = 100000;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, rec(i, n+1, k-1, false));
        ans = min(ans, rec(0, i, k-1, true));
    }

    if (ans == 100000) printf("-1\n");
    else printf("%d\n", ans);
}