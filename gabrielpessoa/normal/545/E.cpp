#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 3E5 + 5;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

viii g[SIZE];
priority_queue<ii, vii, greater<ii>> h;
ll d[SIZE];
int peso[SIZE];
int anterior[SIZE];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(iii(v, ii(w, i)));
        g[v].push_back(iii(u, ii(w, i)));
        peso[i] = w;
    }
    int s;
    memset(d, 63, sizeof(d));
    scanf("%d", &s);
    d[s] = 0;
    h.push(ii(0, s));
    ll total = 0;
    while(!h.empty()) {
        int v = h.top().second;
        int dist = h.top().first;
        h.pop();
        //printf("extraindo %d com distancia %d\n", v, dist);
        if(dist > d[v]) {
            continue;
        }
        for(iii aresta : g[v]) {
            int a = aresta.first;
            int w = aresta.second.first;
            int i = aresta.second.second;
            if(d[v] + w < d[a] || (d[v] + w == d[a] && peso[i] < peso[anterior[a]])) {
                d[a] = d[v] + w;
                total += peso[i] - peso[anterior[a]];
                anterior[a] = i;
                h.push(ii(d[a], a));
            }
        }
    }
    printf("%I64d\n", total);
    for(int i = 1; i <= n; i++) {
        if(i != s) {
            printf("%d ", anterior[i]);
        }
    }
    return 0;
}