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

int t,n,p;

int g[30][30];

int main() {
    for (scanf("%d", &t); t; t--) {
        scanf("%d %d", &n, &p);

        memset(g,0,sizeof(g));

        for (int i = 0; i < n; i++) {
            g[i][(i+1)%n] = 1;
            g[i][(i+2)%n] = 1;
            g[(i+1)%n][i] = 1;
            g[(i+2)%n][i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) if (!g[i][j] && p) {
                g[i][j] = 1;
                p--;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) if (g[i][j]) {
                printf("%d %d\n", i+1, j+1);
            }
        }
    }    
}