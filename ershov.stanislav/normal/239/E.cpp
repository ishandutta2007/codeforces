#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge { bool is_edge; int i; };
vector<vector<edge> > tree;
int countWrong;

int dfs(int v, int path, int parent) {
    int a=0, path2 = path;
    for (int i=0; i<tree[v].size(); i++) {
        if (tree[v][i].i == parent) continue;
        if (!tree[v][i].is_edge) {
            countWrong++;
            a = dfs(tree[v][i].i, path+1, v);
        } else a = dfs(tree[v][i].i, max(path-1, 0), v);
        if (a > path2) path2 = a;
    }
    return path2;
}

int main()
{
    int n;
    cin >> n;
    tree.resize(n, *(new vector<edge>));
    for (int i=0; i<n-1; i++) {
        edge e1, e2;
        int a, b;
        cin >> a >> b;
        e1.is_edge = true;
        e2.is_edge = false;
        e1.i = b - 1;
        e2.i = a - 1;
        tree[a-1].push_back(e1);
        tree[b-1].push_back(e2);
    }
    int min = n;
    for (int i=0; i<n; i++) {
        countWrong = 0;
        int a = dfs(i, 0, -1);
        if (countWrong - a < min) min = countWrong - a;
    }
    cout << min;
}