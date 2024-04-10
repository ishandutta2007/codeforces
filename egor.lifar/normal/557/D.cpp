#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>


using namespace std;


int n, m;
vector<int> v[100000];
int used[100000];
vector<int> vv;
vector<vector<int> > s;


void dfs(int u, int t) {
    used[u] = t;
    vv.push_back(u);
    for (int i = 0; i < (int)v[u].size(); i++) {
        int h = v[u][i];
        if (!used[h]) {
            dfs(h, 3 - t);
        } else {
            if (used[h] == used[u]) {
                cout << 0 << ' ' << 1 << endl;
                exit(0);
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (m == 0) {
        cout << 3 << ' ' << (1LL * n * (n - 1) * (n - 2)) / 6 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            vv.clear();
            dfs(i, 1);
            s.push_back(vv);
        }
    }
    long long ans = 0;
  //  cout << (int)s.size() << endl;
    for (int i = 0; i < (int)s.size(); i++) {
        if ((int)s[i].size() >= 2) {
            int g = 0, g1 = 0;
            for (int j = 0; j < (int)s[i].size(); j++) {
                if (used[s[i][j]] == 1) {
                    g++;
                } else {
                    g1++;
                }
            }
            ans += (1LL * g * (g - 1)) / 2LL;
            ans += (1LL * g1 * (g1 - 1)) / 2LL;
        }
    }
    if (ans > 0LL) {
        cout << 1 << ' ' << ans << endl;
        return 0;
    }
    cout << 2 << ' ' << 1LL * m * (n - 2LL) << endl;
    return 0;   
}