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

vector<int> adj[330000];
int parent[330000];
int dia[330000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void link(int a, int b){ 
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;

    parent[pb] = pa;
    dia[pa] = max(dia[pb], max(dia[pa], (dia[pb]+1)/2 + 1 + (dia[pa]+1)/2) );
}

int n,m,q;
int op, t1, t2;

int big, big_ind;

int dfs(int v, int p=-1, int delta=0) {
    if (delta > big) {
        big = delta;
        big_ind = v;
    }

    for (int i = 0; i < adj[v].size(); i++) if (adj[v][i] != p) {
        dfs(adj[v][i], v, delta+1);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &t1, &t2);
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        link(t1,t2);
    }

    for (int i = 1; i <= n; i++) if (parent[i] == i) {
        big = 0; big_ind = i;
        dfs(i);
        big = 0;
        dfs(big_ind);
        dia[i] = big;
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &op, &t1);
        if (op == 1) printf("%d\n", dia[find(t1)]);
        else {
            scanf("%d", &t2);
            link(t1, t2);
        }
    }
}