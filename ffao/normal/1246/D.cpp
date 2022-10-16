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


vector<int> g[110000];
int n;
int p[110000];
int h[110000];

vector<int> order;
vector<int> ops;
int lh;

void dfsd(int v) {
    for (int c : g[v]) {
        dfsd(c);
        h[v] = max(h[v], h[c] + 1);
    }
}

void dfs(int v, int h) {
    order.push_back(v);
    while (lh >= h) {
        lh--;
        ops.push_back(v);
    }
    lh++;

    for (int c : g[v]) {
        dfs(c, h+1);
    }
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
    }

    dfsd(0);
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), [](int a, int b) { return h[a] < h[b]; });
    }

    dfs(0, 1);

    for (int x : order) {
        printf("%d ", x);
    }
    printf("\n");
    
    printf("%d\n", ops.size());
    for (int x : ops) {
        printf("%d ", x);
    }
    printf("\n");
}


#include <fstream>


int main() {


    solve();
}