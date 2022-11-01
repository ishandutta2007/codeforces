#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> adj[200001];
int dista[200001];
int distb[200001];
bool seen[200001];
int special[200001];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", special + i);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> Q;
    Q.push(1);
    seen[1] = true;
    dista[1] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v: adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                dista[v] = dista[u] + 1;
                Q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        seen[i] = false;
    }
    Q.push(n);
    seen[n] = true;
    distb[n] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v: adj[u]) {
            if (!seen[v]) {
                seen[v] = true;
                distb[v] = distb[u] + 1;
                Q.push(v);
            }
        }
    }
    vector<pair<int, int>> a;
    for (int i = 0; i < k; i++) {
        a.push_back({dista[special[i]], distb[special[i]]});
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int lo = 0, mid, hi = n;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        vector<pair<pair<int, int>, int>> q;
        for (int i = 0; i < k; i++) {
            int f = mid - a[i].second;
            int s = mid - a[i].first;
            q.push_back({{f, s}, i});
        }
        sort(q.begin(), q.end());
        bool found = false;
        int max1 = -0x3f3f3f3f, max2 = -0x3f3f3f3f;
        int maxi1 = -1, maxi2 = -1;
        for (int i = k-1; i >= 0; i--) {
            while (!q.empty() && a[i].first < q.back().first.first) {
                if (max1 >= q.back().first.second && maxi1 != q.back().second) {
                    found = true;
                }
                if (max2 >= q.back().first.second && maxi2 != q.back().second) {
                    found = true;
                }
                q.pop_back();
            }
            if (a[i].second >= max1) {
                max2 = max1;
                maxi2 = maxi1;
                max1 = a[i].second;
                maxi1 = i;
            }
            else if (a[i].second > max2) {
                max2 = a[i].second;
                maxi2 = i;
            }
        }
        while (!q.empty()) {
            if (max1 >= q.back().first.second && maxi1 != q.back().second) {
                found = true;
            }
            if (max2 >= q.back().first.second && maxi2 != q.back().second) {
                found = true;
            }
            q.pop_back();
        }
        if (found) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    ans = min(lo + 1, dista[n]);
    printf("%d\n", ans);
    return 0;
}