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

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

vector<int> adj[310000];
int n, lea;

int force_big(int rt, int target, bool take_max) {
    if (adj[rt].empty()) return 1;

    int ret = n;
    if (take_max) {
        for (int ch : adj[rt]) {
            ret = min(ret, force_big(ch, target, false));
        }
    }
    else {
        ret = 0;
        for (int ch : adj[rt]) {
            ret += force_big(ch, target, true);
        }
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++) if (adj[i].empty()) lea++;

    int st = 1, ed = lea;
    while (st < ed) {
        int m = (st+ed+1)/2;
        if (force_big(0, m, 1) <= (lea-m+1)) {
            st = m;
        }
        else ed = m-1;
    }

    printf("%d ", st);

    st = 1; ed = lea;
    while (st < ed) {
        int m = (st+ed)/2;
        //printf("%d %d\n", m, force_big(1,m,0));
        if (force_big(0, m, 0) <= m) {
            ed = m;
        }
        else st = m+1;
    }

    printf("%d\n", st);
}