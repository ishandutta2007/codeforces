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

int n, m;
char horiz[100], vert[100];
int cnt;
int seen[100][100];

int dfs(int y, int x) {
    if (seen[x][y]) return 0;
    
    seen[x][y] = 1;
    int ret = 1;

    if (horiz[y] == '<' && x > 0) {
        ret += dfs(y, x-1);
    }
    if (horiz[y] == '>' && x+1 < m) {
        ret += dfs(y, x+1);
    }
    if (vert[x] == '^' && y > 0) {
        ret += dfs(y-1, x);
    } 
    if (vert[x] == 'v' && y+1 < n) {
        ret += dfs(y+1, x);
    }

    return ret;
}

int main() {
    scanf("%d %d", &n, &m);

    scanf("%s %s", horiz, vert);
    bool ok = true;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            memset(seen,0,sizeof(seen));
            if (dfs(x, y) != n*m) {
                ok = false;
                break;
            } 
        }
    }

    printf("%s\n", ok ? "YES" : "NO");
}