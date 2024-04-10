#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, *a;
    vector<int> res;
    cin >> n >> m;
    a = new int[n];
    vector<vector<int> > graph(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    queue<int> zeros;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] == 0) zeros.push(i);
    }
    while(!zeros.empty()) {
        int v = zeros.front();
        res.push_back(v);
        zeros.pop();
        for (int i=0; i<graph[v].size(); i++) {
            a[graph[v][i]]--;
            if (a[graph[v][i]] == 0) zeros.push(graph[v][i]);
        }
    }
    cout << res.size() << endl;
    for (int i=0; i<res.size(); i++) cout << res[i] + 1 <<' ';
    return 0;
}