#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105], q, x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    cin >> q;
    while (q--) {
        cin >> x;
        int L = 0, R = n - 1;
        while (L < R) {
            int mid = (L + R + 1) / 2;
            if (a[mid] <= x) L = mid;
            else R = mid - 1;
        }
        if (a[L] > x) cout << 0 << "\n";
        else cout << 1 + L << "\n";
    }

    return 0;
}