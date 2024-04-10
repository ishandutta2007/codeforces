#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[150005], k, mni, mn = 1e9, cur;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
        cur += a[i];
    for (int i = 0; i <= n - k; ++i) {
        if (cur < mn)
            mn = cur, mni = i + 1;
        cur -= a[i];
        cur += a[i + k];
    }
    cout << mni << endl;

    return 0;
}