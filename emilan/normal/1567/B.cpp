#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int pre[N];

void solve() {
    int a, b;
    cin >> a >> b;

    int req = pre[a - 1] ^ b;
    if (req == 0) cout << a;
    else if (req != a) cout << a + 1;
    else cout << a + 2;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        pre[i] = pre[i - 1] ^ i;
    }

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}