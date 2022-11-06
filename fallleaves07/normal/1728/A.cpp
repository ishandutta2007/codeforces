#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = i + 1;
    }
    for (int i = 1; i < n; i++) {
        int val = min(a[i - 1], a[i]);
        a[i - 1] -= val, a[i] -= val;
        if (a[i - 1] > a[i]) {
            swap(a[i - 1], a[i]);
            swap(c[i - 1], c[i]);
        }
    }
    printf("%d\n", c[n - 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}