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

set<int> locs[100001];
int a[100001];
int pd[100001][310];
int n,m,s,e,el;

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &e);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < m; i++) {
        scanf("%d", &el);
        locs[el].insert(i);
    }

    int max_moves = s / e;
    int best = 0;

    for (int pos = 0; pos < n; pos++) {
        for (int moves = 1; moves <= max_moves; moves++) {
            if (pos == 0) pd[pos][moves] = m+1;
            else pd[pos][moves] = pd[pos-1][moves];

            int lo;
            if (pos == 0 && moves == 1) lo = 0;
            else if (pos == 0) lo = m;
            else lo = pd[pos-1][moves-1];

            set<int>::iterator it = locs[a[pos]].lower_bound(lo);
            if (it != locs[a[pos]].end()) {
                pd[pos][moves] = min(pd[pos][moves], *it + 1);
            }

            int cost = (pos+1 + pd[pos][moves]);
            if (pd[pos][moves] != m+1 && moves * e + cost <= s) {
                best = max(best, moves);
            }
        }
    }

    printf("%d\n", best);
}