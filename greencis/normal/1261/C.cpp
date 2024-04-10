#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<string> transpose(const vector<string>& v) {
    int n = (int)v.size();
    int m = (int)v[0].size();
    vector<string> res(m, string(n, '0'));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res[j][i] = v[i][j];
    return res;
}

int t[1 << 11];

inline void push(int v, int tl, int tr) {
    if (tl != tr && t[v]) {
        t[v << 1] += t[v];
        t[(v << 1) ^ 1] += t[v];
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (tl == l && tr == r) {
        t[v] += val;
    } else {
        int tm = (tl + tr) >> 1;
        if (l <= tm)
            update(v << 1, tl, tm, l, min(r, tm), val);
        if (r > tm)
            update((v << 1) ^ 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}

int get(int v, int tl, int tr, int idx) {
    while (tl != tr) {
        push(v, tl, tr);
        int tm = (tl + tr) >> 1;
        v <<= 1;
        if (idx <= tm)
            tr = tm;
        else {
            v ^= 1;
            tl = tm + 1;
        }
    }
    return t[v];
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    bool transposed = false;
    if (m > n) {
        transposed = true;
        swap(m, n);
        s = transpose(s);
    }

    vector<vector<int>> sum(n, vector<int>(m)); /// m <= n
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] = (s[i][j] == 'X') + (i > 0 ? sum[i - 1][j] : 0) + (j > 0 ? sum[i][j - 1] : 0)
                        - (i > 0 && j > 0 ? sum[i - 1][j - 1] : 0);
        }
    }

    int L = 0, R = (m - 1) / 2;
    vector<string> ans;
    while (L <= R) {
        int mid = (L + R + 1) >> 1;
        int len = 2 * mid + 1;
        ans = vector<string>(n, string(m, '.'));
        vector<vector<pii>> events(n + 1);
        memset(t, 0, sizeof t);
        bool fail = false;
        for (int i = 0; !fail && i < n; ++i) {
            for (const auto& p : events[i])
                update(1, 0, m - 1, p.first, p.second, -1);

            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.') continue;
                if (i + len <= n && j + len <= m) {
                    int curcnt = sum[i + len - 1][j + len - 1];
                    if (i > 0) {
                        curcnt -= sum[i - 1][j + len - 1];
                        if (j > 0)
                            curcnt += sum[i - 1][j - 1];
                    }
                    if (j > 0)
                        curcnt -= sum[i + len - 1][j - 1];
                    if (curcnt == len * len) { /// SET FIRE HERE
                        ans[i + mid][j + mid] = 'X';
                        update(1, 0, m - 1, j, j + len - 1, 1);
                        events[i + len].emplace_back(j, j + len - 1);
                    }
                }
                if (!get(1, 0, m - 1, j)) {
                    fail = true;
                    break;
                }
            }
        }
        if (L == R) break;
        if (fail)
            R = mid - 1;
        else
            L = mid;
    }

    if (transposed) {
        swap(n, m);
        ans = transpose(ans);
    }
    cout << L << "\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
}