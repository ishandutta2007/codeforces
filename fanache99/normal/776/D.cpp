//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

int state[1 + MAXN];
vector<pair<int, int> > g[1 + MAXN];
pair<int, int> which[1 + MAXN];
int seen[1 + MAXN];
vector<int> nodes;

void DFS(int node) {
    nodes.push_back(node);
    for (auto &it : g[node])
        if (!seen[it.first])
            if (it.second) {
                seen[it.first] = seen[node];
                DFS(it.first);
            }
            else {
                seen[it.first] = 3 - seen[node];
                DFS(it.first);
            }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> state[i];
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            int y;
            cin >> y;
            if (!which[y].first)
                which[y].first = i;
            else
                which[y].second = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        int a = which[i].first, b = which[i].second;
        if (state[i]) {
            g[a].push_back(make_pair(b, 1));
            g[b].push_back(make_pair(a, 1));
        }
        else {
            g[b].push_back(make_pair(a, 0));
            g[a].push_back(make_pair(b, 0));
        }
    }
    for (int i = 1; i <= m; i++)
        if (!seen[i]) {
            seen[i] = 1;
            nodes.clear();
            DFS(i);
            for (auto &j : nodes)
                for (auto &k : g[j]) {
                    if (k.second && seen[j] != seen[k.first]) {
                        cout << "NO\n";
                        return 0;
                    }
                    if (!k.second && seen[j] == seen[k.first]) {
                        cout << "NO\n";
                        return 0;
                    }
                }
        }
    cout << "YES\n";
    return 0;
}