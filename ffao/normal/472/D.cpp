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

int n;
vector< pair<int, int> > adj[2100];
int mat[2100][2100], d[2100][2100];
pair<int, int> tt[2100];
int order[2100];

void dfs(int v, int p, int orig, int dist) {
    mat[orig][v] = dist;

    for (int j = 0; j < adj[v].size(); j++) {
        int newv = adj[v][j].first;
        int cost = adj[v][j].second;

        if (newv == p) continue;
        dfs(newv, v, orig, dist+cost);
    }
}

int main() {
    scanf("%d", &n);
    bool ok = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d[i][j]);
        }

        if (d[i][i] != 0) ok = false;
    }

    for (int i = 0; i < n; i++) {
        tt[i].first = d[0][i];
        tt[i].second = i;
    }
    sort(tt,tt+n);
    for (int i = 0; i < n; i++) order[i] = tt[i].second;

    for (int j = 1; j < n; j++) {
        int best = 1000000010;
        int best_ind = -1;
        int v1 = order[j];

        for (int i = 0; i < j; i++) {
            int v2 = order[i];

            if (d[v1][v2] < best) {
                best = d[v1][v2];
                best_ind = v2;
            }
        }

        if (best == 0) ok = false;
        adj[best_ind].push_back( make_pair(v1, best) );
        adj[v1].push_back( make_pair(best_ind, best) );
    }

    for (int i = 0; i < n; i++) {
        dfs(i, -1, i, 0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != d[i][j]) ok = false;
        }
    }

    printf("%s\n", ok ? "YES" : "NO");

}