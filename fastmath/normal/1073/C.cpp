#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9 + 7;
const int MAXN = 2e5 + 7;

int n;
string s;
int x, y;
void read() {
    cin >> n >> s >> x >> y;
}

int pr[MAXN][4];
bool check(int l, int r) {
    int hu = pr[n][0] - (pr[r + 1][0] - pr[l][0]);
    int hd = pr[n][1] - (pr[r + 1][1] - pr[l][1]);
    int hl = pr[n][2] - (pr[r + 1][2] - pr[l][2]);
    int hr = pr[n][3] - (pr[r + 1][3] - pr[l][3]);

    int tx = hr - hl;
    int ty = hu - hd;

    int wx = x - tx;
    int wy = y - ty;

    int have = r - l + 1;

    return (abs(wx) + abs(wy) <= have) && (abs(wx + wy) % 2 == have % 2);
}
    
int ans = INF;
void solve() {
    for (int i = 0; i < n; ++i) {
        pr[i + 1][0] = pr[i][0] + (s[i] == 'U');
        pr[i + 1][1] = pr[i][1] + (s[i] == 'D');
        pr[i + 1][2] = pr[i][2] + (s[i] == 'L');
        pr[i + 1][3] = pr[i][3] + (s[i] == 'R');
    }
    int u = -1;
    for (int i = 0; i < n; ++i) {
        u = max(u, i - 1);
        while (u < n && !check(i, u)) ++u;
        //cout << i << ' ' << u << '\n';
        if (u < n) ans = min(ans, u - i + 1);
    }   
}

void print() {
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}