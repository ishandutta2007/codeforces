//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int MAXNODES = 262144;
const long long INF = 1000000000000000000LL;

vector<pair<int, int> > g[1 + MAXN + 2 * MAXNODES];
long long best[1 + MAXN + 2 * MAXNODES];
bool seen[1 + MAXN + 2 * MAXNODES];
int n, nodes;

void BuildTree(int node, int left, int right) {
    best[node + n] = best[node + nodes + n] = INF;
    g[node + n].push_back(make_pair(node + nodes + n, 0));
    if (left == right) {
        g[node + n].push_back(make_pair(left, 0));
        g[left].push_back(make_pair(node + nodes + n, 0));
        return;
    }
    g[node + n].push_back(make_pair(2 * node + n, 0));
    g[node + n].push_back(make_pair(2 * node + n + 1, 0));
    g[2 * node + nodes + n].push_back(make_pair(node + nodes + n, 0));
    g[2 * node + 1 + nodes + n].push_back(make_pair(node + nodes + n, 0));
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
}

int from, to, type, where, cost;

void Update(int node, int left, int right) {
    if (from <= left && right <= to) {
        if (type == 2)
            g[where].push_back(make_pair(node + n, cost));
        else
            g[node + nodes + n].push_back(make_pair(where, cost));
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle)
        Update(2 * node, left, middle);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right);
}

priority_queue<pair<long long, int> > Heap;

void Dijkstra(int start) {
    for (int i = 1; i <= n; i++)
        best[i] = INF;
    best[start] = 0;
    Heap.push(make_pair(0, start));
    while (!Heap.empty()) {
        int node = Heap.top().second;
        Heap.pop();
        if (seen[node])
            continue;
        seen[node] = true;
        for (auto &it : g[node])
            if (best[node] + it.second < best[it.first]) {
                best[it.first] = best[node] + it.second;
                Heap.push(make_pair(-best[it.first], it.first));
            }
    }
}

int main() {
    int m, start;
    cin >> n >> m >> start;
    nodes = 1;
    while (nodes < n)
        nodes *= 2;
    nodes *= 2;
    BuildTree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        cin >> type;
        if (type == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back(make_pair(b, c));
        }
        else {
            cin >> where >> from >> to >> cost;
            Update(1, 1, n);
        }
    }
    Dijkstra(start);
    for (int i = 1; i <= n; i++) {
        if (best[i] == INF)
            best[i] = -1;
        cout << best[i] << " ";
    }
    return 0;
}