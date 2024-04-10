
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    vector <vector <char>> f(n, vector <char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> f[i][j];
            if (f[i][j] == '.') ++cnt;
        }
    }
    if (k == 1) {
        cout << cnt << endl;
        return 0;
    }
    long long ans = 0;
    vector <int> tmp;
    for (int i = 0; i < n; ++i) {
        tmp.push_back(0);
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == '.') ++tmp.back();
            else if (tmp.back() != 0) tmp.push_back(0);
        }
        for (auto e : tmp) {
            if (e >= k) ans += e - k + 1;
        }
        tmp.clear();
    }
    for (int j = 0; j < m; ++j) {
        tmp.push_back(0);
        for (int i = 0; i < n; ++i) {
            if (f[i][j] == '.') ++tmp.back();
            else if (tmp.back() != 0) tmp.push_back(0);
        }
        for (auto e : tmp) {
            if (e >= k) ans += e - k + 1;
        }
        tmp.clear();
    }
    cout << ans << endl;
}