#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[200105], ans[200105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans[i] = 1e9;
    }

    int last_zero = -1e9;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0)
            last_zero = i;
        ans[i] = min(ans[i], i - last_zero);
    }

    last_zero = 1e9;
    for (int i = n; i >= 1; --i) {
        if (a[i] == 0)
            last_zero = i;
        ans[i] = min(ans[i], last_zero - i);
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}