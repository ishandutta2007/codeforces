#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1007;
const int MOD = 998244353;
const int MAXV = 1e6 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int fp(int a, int b) {
    if (b == 0) return 1;
    int t = fp(a, b / 2);
    if (b % 2 == 0) return mod(t * t);
    else return mod(mod(t * t) * a);
}

int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}

int a[MAXN][MAXN];

bool comp(pair <int, int> x, pair <int, int> y) {
    return a[x.first][x.second] < a[y.first][y.second];
}

int dp[MAXN][MAXN];
vector <pair <int, int> > l[MAXV];

int cnt = 0;
int curr = 0;
int isum = 0, pisum = 0, jsum = 0, pjsum = 0;

void add(int x) {
    for (auto p : l[x]) {
        ++cnt;
        curr += dp[p.first][p.second];
        curr = mod(curr);

        isum += p.first;
        pisum += p.first * p.first;

        jsum += p.second;
        pjsum += p.second * p.second;
    }
}

int n, m;
void compress() {
    vector <int> v;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) v.push_back(a[i][j]);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

    compress();

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) l[a[i][j]].push_back({i, j});

    vector <pair <int, int> > v;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) v.push_back({i, j});
    sort(v.begin(), v.end(), comp);

    for (int t = 0; t < n * m; ++t) {
        if (t && a[v[t - 1].first][v[t - 1].second] < a[v[t].first][v[t].second]) {
            add(a[v[t - 1].first][v[t - 1].second]);
        }
        int i = v[t].first, j = v[t].second;
        if (cnt == 0) {
            dp[i][j] = 0;
        }
        else {
            int sum = curr;

            sum += cnt * i * i;
            sum += pisum;
            sum -= 2 * isum * i;

            sum += cnt * j * j;
            sum += pjsum;
            sum -= 2 * jsum * j;

            sum = mod(sum);

            dp[i][j] = mdiv(sum, cnt);
        }
    }

    int x, y;
    cin >> x >> y;
    cout << dp[x - 1][y - 1] << '\n';

    return 0;
}