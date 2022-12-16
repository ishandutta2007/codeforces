#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int SIZE = 1E5 + 5;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

vii g[SIZE];
int d[SIZE];
priority_queue<ii, vii, greater<ii> > h;
set<int> trav[SIZE];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        g[a].push_back(ii(b, w));
        g[b].push_back(ii(a, w));
    }
    for(int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        while(k--) {
            int t;
            scanf("%d", &t);
            trav[i].insert(t);
        }
    }
    memset(d, 63, sizeof(d));
    d[1] = 0;
    h.push(ii(0, 1));
    while(!h.empty()) {
        int t = h.top().first;
        int v = h.top().second;
        //printf("%d %d\n", v, t);
        h.pop();
        if(v == n) {
            break;
        }
        if(d[v] != t) {
            continue;
        }
        if(trav[v].count(t)) {
            h.push(ii(++d[v], v));
            continue;
        }
        for(ii aresta : g[v]) {
            int a = aresta.first;
            int dis = aresta.second;
            if(d[v] + dis < d[a]) {
                d[a] = d[v] + dis;
                h.push(ii(d[a], a));
            }
        }
    }
    if(d[n] == INF) {
        puts("-1");
    } else {
        printf("%d\n", d[n]);
    }
    return 0;
}