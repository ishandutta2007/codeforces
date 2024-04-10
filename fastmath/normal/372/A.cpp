#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

int n;
int a[MAXN];

bool check(int k) {
    for (int i = 0; i < k; ++i) {
        if (a[n - k + i] < a[i] * 2) return 0;
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    int l = 0;
    int r = n / 2 + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m)) l = m;
        else r = m;
    }    

    cout << n - l << '\n';
    return 0;
}