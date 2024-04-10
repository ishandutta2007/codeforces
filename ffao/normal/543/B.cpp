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
vector<int> adj[3100];

void bfs(int v, vector<int>& dists) {
    dists.resize(n, -1);
    dists[v] = 0;

    queue<int> tv;
    tv.push(v);

    while (!tv.empty()) {
        int cur = tv.front();
        tv.pop();

        for (int a : adj[cur]) {
            if (dists[a] == -1) {
                dists[a] = dists[cur] + 1;
                tv.push(a);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a,b;
        scanf("%d %d", &a, &b); a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int s1, t1, l1, s2, t2, l2;
    scanf("%d %d %d %d %d %d", &s1, &t1, &l1, &s2, &t2, &l2);
    s1--; t1--; s2--; t2--;

    vector<int> dists[3100];
    for (int i = 0; i < n; i++) bfs(i, dists[i]);

    if (dists[s1][t1] > l1 || dists[s2][t2] > l2) {
        printf("-1\n");
        return 0;
    }

    int ans = dists[s1][t1] + dists[s2][t2];

    for (int v1 = 0; v1 < n; v1++) {
        for (int v2 = 0; v2 < n; v2++) {
            int s1t1 = min(dists[s1][v1] + dists[v1][v2] + dists[v2][t1],
                           dists[s1][v2] + dists[v1][v2] + dists[v1][t1]);
            int s2t2 = min(dists[s2][v1] + dists[v1][v2] + dists[v2][t2],
                           dists[s2][v2] + dists[v1][v2] + dists[v1][t2]);

            if (s1t1 > l1 || s2t2 > l2) continue;

            ans = min(ans, dists[v1][v2] + min(dists[s1][v1] + dists[v2][t1], dists[s1][v2] + dists[v1][t1]) +
                                           min(dists[s2][v1] + dists[v2][t2], dists[s2][v2] + dists[v1][t2]));
        }
    }

    printf("%d\n", m - ans);
}