#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = (1 << 5);
const int N = 2e5 + 7;

int t[M][2 * N];
const int Inf = 1e9;

int n;
 
void modify(int m, int x, int val) {
    for (t[m][x += n] = val; x > 1; x >>= 1) {
        t[m][x >> 1] = max(t[m][x], t[m][x ^ 1]);
    }
}
 
int get(int m, int l, int r) {
    ++r;
    int res = -Inf;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, t[m][l++]);
        if (r & 1) res = max(res, t[m][--r]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < 2 * N; ++j) {
            t[i][j] = -Inf;
        }
    }
    int k;
    cin >> n >> k;
    int anti = (1 << k) - 1;
    for (int i = 0; i < n; ++i) {
        vector <int> cur(k);
        for (int j = 0; j < k; ++j) {
            cin >> cur[j];
        }
        for (int mask = 0; mask < (1 << k); ++mask) {
            int sum = 0;
            for (int j = 0; j < k; ++j) {
                if (mask & (1 << j)) {
                    sum += cur[j];
                }
                else {
                    sum -= cur[j];
                }
            }
            modify(mask, i, sum);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            --x;
            vector <int> cur(k);
            for (int j = 0; j < k; ++j) {
                cin >> cur[j];
            }
            for (int mask = 0; mask < (1 << k); ++mask) {
                int sum = 0;
                for (int j = 0; j < k; ++j) {
                    if (mask & (1 << j)) {
                        sum += cur[j];
                    }
                    else {
                        sum -= cur[j];
                    }
                }
                modify(mask, x, sum);
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int res = -Inf;
            for (int mask = 0; mask < (1 << k); ++mask) {
                res = max(res, get(mask, l, r) + get(mask ^ anti, l, r));
            }
            cout << res << '\n';
        }
    }
}