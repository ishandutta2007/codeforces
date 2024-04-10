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
#define INFLL 1000000000000000000LL
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

long long dist[110000];
bool nt[110000];
bool it[110000];
int cnt;
vector<pii> adj[110000];

int n,m,k,a,b,c;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) dist[i] = INFLL;
    dist[0] = 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c); a--; b--;
        adj[a].push_back(mp(b,c));
        adj[b].push_back(mp(a,c));
    }

    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &c); a--;
        it[a]=true;
        if (dist[a] != INFLL) cnt++;
        dist[a] = min(dist[a], (long long)c);
    }

    set< pair< long long, int > > pq;
    for (int i = 0; i < n; i++) pq.insert(mp(dist[i], i));

    while (!pq.empty()) {
        int cur = pq.begin()->second;
        pq.erase(pq.begin());

        for (int j = 0; j < adj[cur].sz; j++) {
            int v = adj[cur][j].first;
            long long nd = adj[cur][j].second + dist[cur];
            
            if (dist[v] >= nd) nt[v]=true;
            if (dist[v] > nd) {
                pq.erase(mp(dist[v], v));
                dist[v] = nd;
                pq.insert(mp(dist[v],v));
            }
        }
    }

    for (int i = 1; i < n; i++) cnt += nt[i] * it[i];   
    printf("%d\n", cnt);
}