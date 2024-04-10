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
#include <unordered_map>

using namespace std; 

int n;
double choose;
double ans;

double C(int n) {
    return n * 1.0 * (n-1) * (n-2) / 6.0;
}

struct road {
    int a, b;
    int len;
};

road roads[110000];
double contr[110000];
vector<int> adj[110000];
int sz[110000];
int a, b, c, q;

void dfs(int v, int p) {
    sz[v] = 1;
    for (int road_idx : adj[v]) {
        if (roads[road_idx].a == p) continue;

        if (roads[road_idx].a != v) {
            swap(roads[road_idx].a, roads[road_idx].b);
        }

        int ot = roads[road_idx].b;
        dfs(ot, v);
        sz[v] += sz[ot];
    }
}

void update(int idx, int new_sz) {
    ans -= contr[idx];

    double prob = 0;
    prob += C( sz[roads[idx].b] );
    prob += C( n - sz[roads[idx].b] );

    prob = 1 - prob / choose;

    ans += 2 * prob * new_sz;
    contr[idx] = 2 * prob * new_sz;
}

int main() {
    scanf("%d", &n);
    choose = C(n);

    for (int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        adj[a].push_back(i);
        adj[b].push_back(i);
        roads[i].a = a; roads[i].b = b; roads[i].len = c;
    }

    dfs(0, -1);

    for (int i = 0; i < n-1; i++) {
        update(i, roads[i].len);
    }

    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b); a--;
        update(a, b);
        printf("%.15f\n", ans);
    }   
}