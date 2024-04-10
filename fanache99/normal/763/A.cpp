//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

int color[1 + MAXN], need;
vector<int> g[1 + MAXN];
vector<pair<int, int> > edges;
bool ok;

void DFS(int node, int father) {
    if (color[node] != need)
        ok = false;
    for (auto &son : g[node])
        if (son != father)
            DFS(son, node);
}

bool Check(int root) {
    ok = true;
    for (auto &son : g[root]) {
        need = color[son];
        DFS(son, root);
    }
    return ok;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    pair<int, int> temp = make_pair(-1, -1);
    for (auto &edge : edges)
        if (color[edge.first] != color[edge.second]) {
            temp = edge;
            break;
        }
    if (temp.first == -1) {
        cout << "YES\n1\n";
        return 0;
    }
    if (Check(temp.first)) {
        cout << "YES\n" << temp.first << "\n";
        return 0;
    }
    if (Check(temp.second)) {
        cout <<  "YES\n" << temp.second << "\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}