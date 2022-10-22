#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int a[MAXN], r[MAXN];

int n;
void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int ans = 0;

void solve() {
    for (int i = 0; i < n - 1; ++i) r[i] = abs(a[i] - a[i + 1]);
    
    int sum0 = 0, sum1 = 0;
    int best0 = 0, best1 = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (i % 2 == 0) {
            sum0 += r[i];
            ans = max(ans, (sum0 - sum1) - best0);
        }
        else {
            sum1 += r[i];
            ans = max(ans, (sum1 - sum0) - best1);
        }   
        best0 = min(best0, sum0 - sum1);
        best1 = min(best1, sum1 - sum0);
    }
}

void print() {
    cout << ans << '\n';
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