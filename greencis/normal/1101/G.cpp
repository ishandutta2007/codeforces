#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[200105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum ^= a[i];
    }
    if (sum == 0) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int bit = 29; bit >= 0; --bit) {
        int idx = -1;
        for (int i = 0; i < n; ++i)
            if ((a[i] >> bit) & 1)
                idx = i;
        if (idx != -1) {
            ++ans;
            int cur = a[idx];
            for (int i = 0; i < n; ++i) {
                if ((a[i] >> bit) & 1)
                    a[i] ^= cur;
            }
        }
    }
    cout << ans;
}