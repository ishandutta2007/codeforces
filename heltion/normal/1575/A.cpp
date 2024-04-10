#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    vector<int> p(n);
    for (auto& s : vs) cin >> s;
    for (int i = 0; i < n; i += 1) p[i] = i;
    sort(p.begin(), p.end(), [&](int x, int y){
        for (int i = 0; i < m; i += 1)
            if (vs[x][i] != vs[y][i]) {
                if (i & 1) return vs[x][i] > vs[y][i];
                return vs[x][i] < vs[y][i];
            }
        return false;
    });
    for (int x : p) cout << x + 1 << " ";
    return 0;
}