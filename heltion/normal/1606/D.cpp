#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        [](){
            int n, m;
            cin >> n >> m;
            vector a(n, vector<int>(m));
            for (auto& v : a) for (int& x : v) cin >> x;
            vector pmn(a), pmx(a), smn(a), smx(a);
            for (int i = 0; i < n; i += 1) {
                for (int j = 1; j < m; j += 1) {
                    pmn[i][j] = min(pmn[i][j - 1], pmn[i][j]);
                    pmx[i][j] = max(pmx[i][j - 1], pmx[i][j]);
                }
                for (int j = m - 2; j >= 0; j -= 1) {
                    smn[i][j] = min(smn[i][j + 1], smn[i][j]);
                    smx[i][j] = max(smx[i][j + 1], smx[i][j]);
                }
            }
            for (int k = 0; k + 1 < m; k += 1) {
                vector<int> p(n);
                for (int i = 0; i < n; i += 1) p[i] = i;
                sort(p.begin(), p.end(), [&](int x, int y){
                    return pmx[x][k] < pmx[y][k];
                });
                vector<int> ppmx(n), spmn(n), psmn(n), ssmx(n);
                for (int i = 0; i < n; i += 1) {
                    ppmx[i] = pmx[p[i]][k];
                    if (i) ppmx[i] = max(ppmx[i], ppmx[i - 1]);
                    psmn[i] = smn[p[i]][k + 1];
                    if (i) psmn[i] = min(psmn[i], psmn[i - 1]);
                }
                for (int i = n - 1; i >= 0; i -= 1) {
                    spmn[i] = pmn[p[i]][k];
                    if (i + 1 < n) spmn[i] = min(spmn[i], spmn[i + 1]);
                    ssmx[i] = smx[p[i]][k + 1];
                    if (i + 1 < n) ssmx[i] = max(ssmx[i], ssmx[i + 1]);
                }
                for (int i = 0; i + 1 < n; i += 1)
                    if (ppmx[i] < spmn[i + 1] and psmn[i] > ssmx[i + 1]) {
                        cout << "YES\n";
                        string s(n, 'R');
                        for (int j = 0; j <= i; j += 1) s[p[j]] = 'B';
                        cout << s << " " << k + 1 << "\n"; 
                        return;
                    }
            }
            cout << "NO\n";
        }();
    }
    return 0;
}