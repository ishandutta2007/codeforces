#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 507;

int a[N][N];

int par[N * N];
int sz[N * N];

int get(int x) {
    return (x == par[x] ? x : par[x] = get(par[x]));
}

int k;

void join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        par[a] = b;
        sz[b] += sz[a];
    }
}

int hv[N * N];

int timer = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            par[i * n + j] = i * n + j;
            if (c == '.') {
                a[i][j] = 0;
                sz[i * n + j] = 1;
            } else {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + 1 < n && a[i][j] == 0 && a[i + 1][j] == 0) join(i * n + j, (i + 1) * n + j);
            if (j + 1 < n && a[i][j] == 0 && a[i][j + 1] == 0) join(i * n + j, i * n + j + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i + k <= n; ++i) {
        for (int dx = 0; dx < k; ++dx) {
            for (int dy = 0; dy < k; ++dy) {
                --sz[get((i + dx) * n + dy)];
            }
        }
        for (int j = 0; j + k <= n; ++j) {
            ++timer;
            if (j > 0) {
                for (int t = i; t < i + k; ++t) {
                    ++sz[get(t * n + j - 1)];
                }
            }
            int cnt = k * k;
            if (i > 0) {
                for (int t = j; t < j + k; ++t) {
                    int c = get((i - 1) * n + t);
                    if (hv[c] != timer) {
                        hv[c] = timer;
                        cnt += sz[c];
                    }
                }
            }
            if (i + k < n) {
                for (int t = j; t < j + k; ++t) {
                    int c = get((i + k) * n + t);
                    if (hv[c] != timer) {
                        hv[c] = timer;
                        cnt += sz[c];
                    }
                }
            }
            if (j > 0) {
                for (int t = i; t < i + k; ++t) {
                    int c = get(t * n + j - 1);
                    if (hv[c] != timer) {
                        hv[c] = timer;
                        cnt += sz[c];
                    }
                }
            }
            if (j + k < n) {
                for (int t = i; t < i + k; ++t) {
                    int c = get(t * n + j + k);
                    if (hv[c] != timer) {
                        hv[c] = timer;
                        cnt += sz[c];
                    }
                }
            }
            ans = max(ans, cnt);
            if (j + k < n) {
                for (int t = i; t < i + k; ++t) {
                    --sz[get(t * n + j + k)];
                }
            }
        }
        for (int dx = 0; dx < k; ++dx) {
            for (int dy = 0; dy < k; ++dy) {
                ++sz[get((i + dx) * n + n - dy - 1)];
            }
        }
    }
    cout << ans << '\n';
}