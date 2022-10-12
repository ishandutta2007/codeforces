#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1005;
bool a[maxn][maxn] = {}, v[maxn][maxn] = {};
pair<int, int> d[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

#define inrange(i, j) (i >= 0 && j >= 0 && i < n && j < m)

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c == '#';
            v[i][j] = 0;
        }

    bool erow = 0, ecol = 0;

    for (int i = 0; i < n; i++) {
        int r = 0;
        for (int j = 0; j < m; j++) {
            if (r == 0 && a[i][j]) r = 1;
            else if (r == 1 && !a[i][j]) r = 2;
            else if (r == 2 && a[i][j]) {
                cout << "-1\n"; return 0;
            }
        }
        if (r == 0) {
            erow = 1;
        }
    }

    for (int j = 0; j < m; j++) {
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r == 0 && a[i][j]) r = 1;
            else if (r == 1 && !a[i][j]) r = 2;
            else if (r == 2 && a[i][j]) {
                cout << "-1\n"; return 0;
            }
        }
        if (r == 0) {
            ecol = 1;
        }
    }

    if (erow != ecol) {
        cout << "-1\n"; return 0;
    }

    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (v[i][j] || !a[i][j]) continue;
            k++;
            vector<pair<int, int>> s = {{i, j}};
            v[i][j] = 1;
            while (!s.empty()) {
                int x, y; tie(x, y) = s.back(); s.pop_back();
                for (auto& [dx, dy] : d) {
                    if (inrange(dx+x, dy+y) && !v[dx+x][dy+y] && a[dx+x][dy+y]) {
                        s.pb({dx+x, dy+y});
                        v[dx+x][dy+y] = 1;
                    }
                }
            }
        }
    cout << k << "\n";
}