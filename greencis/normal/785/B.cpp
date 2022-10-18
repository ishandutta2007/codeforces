#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n[2], x[2][200005], y[2][200005];

int main()
{
    ios_base::sync_with_stdio(false);

    for (int z = 0; z < 2; ++z) {
        cin >> n[z];
        for (int i = 0; i < n[z]; ++i)
            cin >> x[z][i] >> y[z][i];
    }

    int ans = 0;
    for (int z = 0; z < 2; ++z) {
        int mx = 0;
        for (int i = 0; i < n[z ^ 1]; ++i)
            mx = max(mx, x[z ^ 1][i]);
        for (int i = 0; i < n[z]; ++i)
            ans = max(ans, mx - y[z][i]);
    }
    cout << ans << endl;

    return 0;
}