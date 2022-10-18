#include <bits/stdc++.h>
using namespace std;

int n, m, k, s;
int mxs[10], mxd[10], mns[10], mnd[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= k; ++i)
        mxs[i] = mxd[i] = -1e9, mns[i] = mnd[i] = 1e9;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            mxs[x] = max(mxs[x], j + i);
            mxd[x] = max(mxd[x], j - i);
            mns[x] = min(mns[x], j + i);
            mnd[x] = min(mnd[x], j - i);
        }
    }

    int cur, ans = 0;
    cin >> cur;
    while (--s) {
        int x;
        cin >> x;
        ans = max(ans, max(max(mxs[cur] - mns[x], -mnd[cur] + mxd[x]), max(mxd[cur] - mnd[x], -mns[cur] + mxs[x])));
        cur = x;
    }
    cout << ans << endl;

    return 0;
}