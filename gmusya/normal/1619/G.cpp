#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 1e9;

void DFS(int v, int col, vector<bool>& used, vector<int>& comp, vector<vector<int>>& g) {
    used[v] = true;
    comp[v] = col;
    for (int u : g[v]) {
        if (!used[u]) {
            DFS(u, col, used, comp, g);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases;
    cin >> cases;
    for (int case_number = 0; case_number < cases; ++case_number) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> x(n), y(n), t(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i] >> t[i];
        }
        map<int, vector<int>> hor, ver;
        for (int i = 0; i < n; ++i) {
            hor[x[i]].push_back(i);
            ver[y[i]].push_back(i);
        }
        vector<vector<int>> g(n);
        for (auto& now : hor) {
            auto& arr = now.second;
            sort(arr.begin(), arr.end(), [&](int i, int j) {
                return y[i] < y[j];
            });
            for (int i = 0; i + 1 < (int) arr.size(); ++i) {
                int ind1 = arr[i];
                int ind2 = arr[i + 1];
                if (y[ind2] - y[ind1] <= k) {
                    g[ind1].push_back(ind2);
                    g[ind2].push_back(ind1);
                }
            }
        }
        for (auto& now : ver) {
            auto& arr = now.second;
            sort(arr.begin(), arr.end(), [&](int i, int j) {
                return x[i] < x[j];
            });
            for (int i = 0; i + 1 < (int) arr.size(); ++i) {
                int ind1 = arr[i];
                int ind2 = arr[i + 1];
                if (x[ind2] - x[ind1] <= k) {
                    g[ind1].push_back(ind2);
                    g[ind2].push_back(ind1);
                }
            }
        }
        vector<bool> used(n);
        vector<int> comp(n);
        int col = 0;
        for (int v = 0; v < n; ++v) {
            if (!used[v]) {
                DFS(v, col, used, comp, g);
                ++col;
            }
        }
        vector<int> boom(col, INF);
        for (int v = 0; v < n; ++v) {
            boom[comp[v]] = min(boom[comp[v]], t[v]);
        }
        int sz = (int) boom.size();
        sort(boom.begin(), boom.end());
        int ans = sz - 1;
        for (int cnt = 1; cnt < sz; ++cnt) {
            int t1 = boom[sz - cnt - 1];
            ans = min(ans, max(cnt - 1, t1));
        }
        cout << ans << '\n';
    }
    return 0;
}