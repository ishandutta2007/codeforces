#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
#include <bitset>


using namespace std;



#define INF 1000000002


struct edge {
    int a, b, cap, flow;
};


int n, s, t, d[2601], ptr[2601], q[2601];
vector<edge> e;
vector<int> g[2601];

 
void add_edge(int a, int b, int cap) {
    edge e1 = {a, b, cap, 0};
    edge e2 = {b, a, 0, 0};
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);
}


bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, sizeof(d));
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (unsigned int i = 0; i < g[v].size(); i++) {
            int id = g[v][i], to = e[id].b;
            if (d[v] != -1 && d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}
 
int dfs(int v, int flow) {
    if (!flow) { 
        return 0;
    }
    if (v == t) { 
        return flow;
    }
    for (; ptr[v] < (int)g[v].size(); ptr[v]++) {
        int id = g[v][ptr[v]], to = e[id].b;
        if (d[to] != d[v] + 1)  {
            continue;
        }
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs()) {
            break;
        }
        memset(ptr, 0, sizeof(ptr));
        while (int pushed = dfs(s, INF)) {
            flow += pushed;
        }
    }
    return flow;
}



int m;
int a[501];
vector<pair<int, int> > even, odd;


bool prime(int a) {
    for (int i = 2; i <= (int)sqrt(a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}


vector<int> c[1001];
vector<int> ans[1001];
bool used[1001];
int cnt = 0;


void dfs(int u) {
    used[u] = 1;
    if (u <= m) {
        ans[cnt].push_back(even[u - 1].second + 1);
    } else {
        ans[cnt].push_back(odd[u - m - 1].second + 1);
    }
    for (int i = 0; i < (int)c[u].size(); i++) {
        int h = c[u][i];
        if (!used[h]) {
            dfs(h);
        }
    }
}


int main() {
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            even.push_back(make_pair(a[i], i));
        } else {
            odd.push_back(make_pair(a[i], i));
        }
    }
    if ((int)even.size() != (int)odd.size()) {
        cout << "Impossible" << endl;
        return 0;
    }
    m /= 2;
    n = 2 * m + 2;
    s = 0;
    t = 2 * m + 1;
    for (int i = 1; i <= m; i++) {
        add_edge(s, i, 2);
    }
    for (int i = m + 1; i <= 2 * m; i++) {
        add_edge(i, t, 2);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (prime(even[i].first + odd[j].first)) {
                add_edge(i + 1, j + m + 1, 1);
            }
        }
    }
    dinic();
    int size = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        if (e[i].a == s && e[i].b >= 1 && e[i].b <= m) {
            size += e[i].flow;
        }
    }
    if (size != 2 * m) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < (int)e.size(); i++) {
        if (e[i].a >= 1 && e[i].a <= m && e[i].b >= m + 1 && e[i].b <= 2 * m) {
            if (e[i].flow == 1) {
                c[e[i].a].push_back(e[i].b);
                c[e[i].b].push_back(e[i].a);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!used[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        printf("%d", (int)ans[i].size());
        for (int j = 0; j < (int)ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}