#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

mt19937 rnd(time(nullptr));

vector<int> dsu;
vector<int> sz;

int get(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = get(dsu[v]);
}

int merge(int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) {
        return 1;
    }
    if (rnd() & 1) {
        swap(u, v);
    }
    dsu[u] = v;
    sz[v] += sz[u];
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;
    int x = 0;
    dsu.resize(n);
    sz.resize(n, 1);
    iota(dsu.begin(), dsu.end(), 0);
    while (d--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        x += merge(u, v);
        for (int i = 0; i < n; ++i) {
            sz[i] = sz[get(i)];
        }
        int ans = 0;
        vector<int> arr = sz;
        sort(arr.rbegin(), arr.rend());
        for (int i = 0, j = 0; i <= x && j < n; ++i, j += arr[j]) {
            ans += arr[j];
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}