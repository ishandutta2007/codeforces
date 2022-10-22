#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int n;
int a[MAXN];
void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int pos[MAXN];
bool dp[MAXN];
void solve() {
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = i;
    }
    for (int i = n; i >= 1; --i) {
        int p = pos[i];
        int len = i;
        for (int j = p - len; j >= 0; j -= len) {
            if (i < a[j]) dp[p] |= !dp[j];
        }
        for (int j = p + len; j < n; j += len) {
            if (i < a[j]) dp[p] |= !dp[j];
        }   
    }
}

void print() {
    for (int i = 0; i < n; ++i) {
        if (dp[i]) cout << 'A';
        else cout << 'B';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}