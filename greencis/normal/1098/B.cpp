#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long double ld;
typedef long long ll;

int n, m;
vector<string> v, ans, cur;
int ansc = 1e9;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    v.resize(n);
    for (auto& s : v)
        cin >> s;

    string pattern = "ACGT";
    do {
        cur = v;
        int curcnt = 0;
        for (int i = 0; i < n; ++i) {
            int tmp1 = 0;
            for (int j = 0; j < m; ++j)
                tmp1 += (v[i][j] != pattern[i % 2 * 2 + (j + 0) % 2]);
            int tmp2 = 0;
            for (int j = 0; j < m; ++j)
                tmp2 += (v[i][j] != pattern[i % 2 * 2 + (j + 1) % 2]);
            if (tmp1 < tmp2) {
                curcnt += tmp1;
                for (int j = 0; j < m; ++j)
                    cur[i][j] = pattern[i % 2 * 2 + (j + 0) % 2];
            } else {
                curcnt += tmp2;
                for (int j = 0; j < m; ++j)
                    cur[i][j] = pattern[i % 2 * 2 + (j + 1) % 2];
            }
        }
        if (curcnt < ansc) {
            ansc = curcnt;
            ans = cur;
        }

        curcnt = 0;
        cur = v;
        for (int j = 0; j < m; ++j) {
            int tmp1 = 0;
            for (int i = 0; i < n; ++i)
                tmp1 += (v[i][j] != pattern[j % 2 * 2 + (i + 0) % 2]);
            int tmp2 = 0;
            for (int i = 0; i < n; ++i)
                tmp2 += (v[i][j] != pattern[j % 2 * 2 + (i + 1) % 2]);
            if (tmp1 < tmp2) {
                curcnt += tmp1;
                for (int i = 0; i < n; ++i)
                    cur[i][j] = pattern[j % 2 * 2 + (i + 0) % 2];
            } else {
                curcnt += tmp2;
                for (int i = 0; i < n; ++i)
                    cur[i][j] = pattern[j % 2 * 2 + (i + 1) % 2];
            }
        }
        if (curcnt < ansc) {
            ansc = curcnt;
            ans = cur;
        }
    } while (next_permutation(all(pattern)));

    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
}