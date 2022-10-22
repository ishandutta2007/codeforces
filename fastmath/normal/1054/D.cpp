#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, k;
int a[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

const int INF = 1e18 + 7;

int form(int n) {
    if ((1 << (k - 1)) <= n) return n ^ ((1 << k) - 1);
    else return n;
}

int ans = 0;
void solve() {
    map <int, int> cnt;
    cnt[0] = 1;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr ^= a[i];
        ++cnt[form(curr)];
    }
    ans = n * (n + 1) / 2;
    for (auto e : cnt) {
        int sum = e.second;
        int add = INF;
        for (int t = 0; t <= sum; ++t) {
            int a = t;
            int b = sum - t;
            add = min(add, a * (a - 1) / 2 + b * (b - 1) / 2);
        }   
        ans -= add;
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    read();
    solve();
    print();

    return 0;
}