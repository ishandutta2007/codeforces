#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> m(n), k(n);
    for (int i = 0; i < n; i += 1)
        cin >> m[i] >> k[i];
    int maxm = ranges::max(m), maxk = ranges::max(k);
    vector f(maxm + 1, vector<int>(maxk + 1));
    for (int i = 0; i < n; i += 1)
        for (int t = 1; t <= maxk; t += 1)
            f[m[i]][t] += min(t, k[i]);
    vector<int> g(maxm + 1), sum(maxm), p(maxm);
    for (int i = 0; i < maxm; i += 1) p[i] = i + 1;
    for (int i = 1; i <= maxm; i += 1) {
        if (i <= maxk) {
            sort(p.begin(), p.end(), [&](int x, int y){
                return f[x][i] > f[y][i];
            });
            for (int j = 0; j < maxm; j += 1) {
                sum[j] = f[p[j]][i];
                if (j) sum[j] += sum[j - 1];
            }
        }
        g[i] = sum[i - 1];
    }
    int t = 1;
    for (int i = 2; i <= maxm; i += 1)
        if ((LL)g[i] * t > (LL)g[t] * i)
            t = i;
    cout << t << "\n";
    sort(p.begin(), p.end(), [&](int x, int y){
        return f[x][min(t, maxk)] > f[y][min(t, maxk)];
    });
    for (int i = 0; i < t; i += 1) cout << p[i] << " ";
    return 0;
}