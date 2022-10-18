#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n, k, a[300005], dv[300005], sum[300005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n + 1; ++i)
        cin >> a[i];
    int cur = 0;
    for (int i = 0; i < 300005; ++i) {
        cur += a[i];
        dv[i] = !!(cur % 2);
        if (cur % 2) --cur;
        cur /= 2;
    }
    bool inv = false;
    if (dv[300004] == 1) {
        inv = true;
        for (int i = 0; i < 300005; ++i)
            dv[i] ^= 1;
        int d = 1;
        for (int i = 0; i < 300005; ++i) {
            dv[i] += d;
            d = dv[i] / 2;
            dv[i] %= 2;
        }
    }

    for (int i = 300000; i >= 0; --i)
        sum[i] = sum[i+1] + dv[i];

    int ans = 0;
    for (int i = 0; i <= n && i < 290005; ++i) {
        if (sum[i + 40] > 0) continue;
        ll cur = 0;
        for (int j = 40; j >= 0; --j)
            cur = cur * 2LL + dv[i + j];
        if (inv) cur = -cur;
        cur = a[i] - cur;
        //for (int j = 0; j < i; ++j) cur *= 2;
        //cerr << i << " " << cur << endl;
        if (cur >= -k && cur <= k && (i < n || cur != 0)) ++ans;
        if (dv[i]) break;
    }
    cout << ans;


    return 0;
}