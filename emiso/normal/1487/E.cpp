#include <bits/stdc++.h>
using namespace std;
//codigo autorizado pela lumena
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 600007, WALL1 = MAXN, WALL2 = 5*MAXN;

vector<ii> g[MAXN * 9];
ll dist[MAXN * 9];

void connectSegTrees(int id = 0, int i = 1, int j = MAXN-1) {
    if (i == j) {
        g[i].pb({id+WALL1, 0});
        g[id+WALL2].pb({i, 0});
        return;
    }
    int mid = (i+j)/2;
    g[L(id)+WALL1].pb({id+WALL1, 0});
    g[R(id)+WALL1].pb({id+WALL1, 0});
    g[id+WALL2].pb({L(id)+WALL2, 0});
    g[id+WALL2].pb({R(id)+WALL2, 0});
    connectSegTrees(L(id), i, mid);
    connectSegTrees(R(id), mid+1, j);
}

void addEdge2D(int id0, int id, int i, int j, int l2, int r2, int d) {
    if (i > r2 || j < l2) return;
    if (i >= l2 && j <= r2) {
        g[id0+WALL1].pb({id+WALL2, d});
        return;
    }
    int mid = (i+j)/2;
    addEdge2D(id0, L(id), i, mid, l2, r2, d);
    addEdge2D(id0, R(id), mid+1, j, l2, r2, d);
}

void addEdge(int id, int i, int j, int l1, int r1, int l2, int r2, int d) {
    if (i > r1 || j < l1) return;
    if (i >= l1 && j <= r1) {
        addEdge2D(id, 0, 1, MAXN-1, l2, r2, d);
        return;
    }
    int mid = (i+j)/2;
    addEdge(L(id), i, mid, l1, r1, l2, r2, d);
    addEdge(R(id), mid+1, j, l1, r1, l2, r2, d);
}

typedef pair<ll, int> pli;
priority_queue<pli, vector<pli>, greater<pli> > pq;

int n1, n2, n3, n4, m, l1, r1, l2, r2, d[MAXN], source, m1, m2, m3;
vector<int> out[MAXN];

int main() {
    connectSegTrees();

    for(int i = 0; i < 9*MAXN; i++) dist[i] = INT_MAX;

    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    for(int i = 1; i <= n1; i++) {
        scanf("%d", &d[i]);
    }
    for(int i = 1; i <= n2; i++) {
        scanf("%d", &d[i+n1]);
    }
    for(int i = 1; i <= n3; i++) {
        scanf("%d", &d[i+n1+n2]);
    }
    for(int i = 1; i <= n4; i++) {
        scanf("%d", &d[i+n1+n2+n3]);
    }

    scanf("%d", &m1);
    for(int i = 0; i < m1; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        id2 += n1;
        out[id1].emplace_back(id2);
    }
    scanf("%d", &m2);
    for(int i = 0; i < m2; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        id1 += n1;
        id2 += n1 + n2;
        out[id1].emplace_back(id2);
    }
    scanf("%d", &m3);
    for(int i = 0; i < m3; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        id1 += n1 + n2;
        id2 += n1 + n2 + n3;
        out[id1].emplace_back(id2);
    }


    for(int i = 1; i <= n1; i++) {
        out[i].push_back(n1 + n2 + 1);
        sort(out[i].begin(), out[i].end());
        int last = n1, id1 = i;
        for(int id2 : out[i]) {
            int l1 = id1, r1 = id1, l2 = last + 1, r2 = id2 - 1;
            if(l2 <= r2) addEdge(0, 1, MAXN-1, l1, r1, l2, r2, d[id1]);
            last = id2;
        }
    }
    for(int i = n1 + 1; i <= n1 + n2; i++) {
        out[i].push_back(n1 + n2 + n3 + 1);
        sort(out[i].begin(), out[i].end());
        int last = n1 + n2, id1 = i;
        for(int id2 : out[i]) {
            int l1 = id1, r1 = id1, l2 = last + 1, r2 = id2 - 1;
            if(l2 <= r2) addEdge(0, 1, MAXN-1, l1, r1, l2, r2, d[id1]);
            last = id2;
        }
    }
    for(int i = n1 + n2 + 1; i <= n1 + n2 + n3; i++) {
        out[i].push_back(n1 + n2 + n3 + n4 + 1);
        sort(out[i].begin(), out[i].end());
        int last = n1 + n2 + n3, id1 = i;
        for(int id2 : out[i]) {
            int l1 = id1, r1 = id1, l2 = last + 1, r2 = id2 - 1;
            if(l2 <= r2) addEdge(0, 1, MAXN-1, l1, r1, l2, r2, d[id1]);
            last = id2;
        }
    }

    for(int i = 1; i <= n1; i++) {
        source = i;
        dist[source] = 0;
        pq.push({0, source});
    }

    while(!pq.empty()) {
        auto top = pq.top();pq.pop();
        if (top.first > dist[top.second]) continue;
        for(ii e : g[top.second]) {
            if (dist[e.first] > top.first + e.second) {
                dist[e.first] = top.first + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }

    ll ans = INT_MAX;
    for(int i = n1+n2+n3+1; i <= n1+n2+n3+n4; i++) {
        ans = min(ans, dist[i] + d[i]);

    }

    if(ans == INT_MAX) puts("-1");
    else printf("%d\n", ans);

    return 0;
}