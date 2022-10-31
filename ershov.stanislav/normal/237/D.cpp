#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int> > res;
vector<pair<int, int> > res_x;
vector<vector<int> > tree;

void dfs(int v1, int v2, int edge) {
    for (int i=0; i<tree[v2].size(); i++) {
        if (tree[v2][i] != v1) {
            res_x.push_back(*(new pair<int, int>));
            res_x[res_x.size()-1].first = v2;
            res_x[res_x.size()-1].second = tree[v2][i];
            res.push_back(*(new pair<int, int>(edge, res_x.size()-1)));
            dfs(v2, tree[v2][i], res_x.size()-1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    tree.resize(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    res_x.push_back(*(new pair<int, int>));
    res_x[0].first = 0;
    res_x[0].second = tree[0][0];
    dfs(0, tree[0][0], 0);
    dfs(tree[0][0], 0, 0);
    cout << n-1 << endl;
    for (int i=0; i<n-1; i++) {
        cout << "2 " << res_x[i].first + 1 << ' ' << res_x[i].second + 1 << endl;
    }
    for (int i=0; i<n-2; i++) cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
    return 0;
}