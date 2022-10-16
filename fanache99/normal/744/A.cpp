//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000;

int capital[1 + MAXN];
vector<int> g[1 + MAXN];
int degree[1 + MAXN];
int components = 0, which[1 + MAXN], nodes[1 + MAXN];

void DFS(int node) {
    which[node] = components;
    nodes[components]++;
    for (auto &neighbour : g[node])
        if (!which[neighbour])
            DFS(neighbour);
}

bool seen[1 + MAXN];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> capital[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for (int i = 1; i <= n; i++)
        if (!which[i]) {
            components++;
            DFS(i);
        }
    int answer = 0, biggest = 0;
    for (int i = 1; i <= n; i++)
        answer = answer + nodes[which[i]] - 1 - degree[i];
    answer /= 2;
    for (int i = 1; i <= k; i++) {
        seen[which[capital[i]]] = true;
        biggest = max(biggest, nodes[which[capital[i]]]);
    }
    int outside = 0;
    for (int i = 1; i <= components; i++)
        if (!seen[i]) {
            answer = answer + outside * nodes[i];
            outside += nodes[i];
        }
    answer = answer + outside * biggest;
    cout << answer << "\n";
    return 0;
}