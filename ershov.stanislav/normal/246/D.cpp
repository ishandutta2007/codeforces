#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n, m, *c;
    cin >> n >> m;
    c = new int[n+1];
    vector<int> used(111111, 0);
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        used[c[i]] = 1;
    }
    vector<set<int> > g(111111);
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if (c[a] != c[b]) {
            g[c[a]].insert(c[b]);
            g[c[b]].insert(c[a]);
        }
    }
    int max = -1, maxi = -1;
    for (int i=0; i<g.size(); i++) if ((int)g[i].size() > max && used[i]) {
        max = g[i].size();
        maxi=i;
    }
    cout << maxi;
    return 0;
}