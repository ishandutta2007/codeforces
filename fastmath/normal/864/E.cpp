#include <bits/stdc++.h>

using namespace std;

const int N = 107;
const int MAXN = 2007;

int n;
int td[N], d[N], p[N];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> td[i] >> d[i] >> p[i];
    }   
}

const int INF = 1e9 + 7;

int dp[N][MAXN];
bool gt[N][MAXN];
int per[MAXN];

bool comp(int i, int j) {
    return d[i] < d[j];
}   

void solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            dp[i][j] = -INF;
        }   
    }
    
    for (int i = 0; i < n; ++i) {
        per[i] = i;
    }   
    sort(per, per + n, comp);

    dp[0][0] = 0;
    for (int ii = 0; ii < n; ++ii) {
        int i = per[ii];
        for (int t = 0; t < MAXN; ++t) {
            dp[ii + 1][t] = dp[ii][t];
        }   
        for (int t = 0; t + td[i] < d[i]; ++t) {
            if (dp[ii + 1][t + td[i]] < dp[ii][t] + p[i]) {
                dp[ii + 1][t + td[i]] = dp[ii][t] + p[i];
                gt[ii + 1][t + td[i]] = 1;
            }   
        }   
    }   
}

void print() {
    int ans = -1;
    int t = -1;
    for (int i = 0; i < MAXN; ++i) {
        if (dp[n][i] > ans) {
            ans = dp[n][i];
            t = i;
        }   
    }   

    vector <int> v;
    for (int ii = n; ii >= 1; --ii) {   
        int i = per[ii - 1];
        if (gt[ii][t]) {
            t -= td[i];
            v.push_back(i);
        }   
    }   

    cout << ans << '\n';

    reverse(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int e : v) {
        cout << e + 1 << ' ';
    }   
    cout << '\n';
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}