#include <bits/stdc++.h>

using namespace std;

#define int long long

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

    int ans = 0;
    set <int> ms;
    for (int i = 0; i < n; ++i) {
        if (ms.find(a[i]) == ms.end()) {
            ++ans;
            ms.insert(a[i] * k);
        }   
    }   

    cout << ans << '\n';
    return 0;
}