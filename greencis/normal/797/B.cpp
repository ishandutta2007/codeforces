#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, u[20005];
ll ans;

int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        if (x > 0)
            ans += x;
        ++u[x + 10000];
    }
    if (ans % 2LL == 0LL) {
        int dec = 1e9;
        for (int i = -1; i >= -9999; i -= 2) {
            if (u[i + 10000]) {
                dec = min(dec, -i);
                break;
            }
        }
        for (int i = 1; i <= 9999; i += 2) {
            if (u[i + 10000]) {
                dec = min(dec, i);
                break;
            }
        }
        ans -= dec;
    }
    cout << ans << endl;

    return 0;
}