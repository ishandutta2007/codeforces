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

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, m, a, b;

int g[500][500];

int main() {
    scanf("%d %d", &n, &m);

    REP(i, n) REP(j, n) g[i][j] = 1000000000;
    for (int i = 0; i < n; i++) g[i][i] = 0;

    bool road = false;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); a--; b--;
        if (a > b) swap(a,b);
        g[a][b] = g[b][a] = 1;

        if (a == 0 && b == n-1) road = true;
    }

    if (road) {
        REP(i, n) REP(j,n) {
            if (g[i][j] == 1) g[i][j] = 1000000000;
            else if (g[i][j] == 1000000000) g[i][j] = 1;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            REP(j, n) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    if (g[0][n-1] == 1000000000) printf("-1\n");
    else printf("%d\n", g[0][n-1]);
}