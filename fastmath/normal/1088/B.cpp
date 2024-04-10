#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n, k;
int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    sort(a, a + n);

    int l = 0;
    int curr = 0;
    for (int i = 0; i < k; ++i) {
        if (l == n) {
            cout << "0\n";
            continue;
        }   

        int u = l;
        while (u < n && a[u] == a[l]) {
            ++u;
        }

        cout << a[l] - curr << '\n';
        curr = a[l];
        l = u;
    }   

    return 0;
}