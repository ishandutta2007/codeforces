#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a[100005],sum,mn,mx,mnc,mxc;
ll ans,balance;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n == 0) {
        mn = mx = sum / n;
        mnc = 0, mxc = n;
    } else {
        mxc = sum % n, mnc = n - sum % n;
        mx = (sum + n - 1) / n, mn = sum / n;
    }
    sort(a, a + n);
    for (int i = n-1; i >= 0; --i) {
        if (mxc) {
            if (a[i] >= mx) {
                balance += a[i] - mx;
                ans += a[i] - mx;
            } else {
                balance -= mx - a[i];
                a[i] = mx;
            }
            --mxc;
        } else {
            if (a[i] >= mn) {
                balance += a[i] - mn;
                ans += a[i] - mn;
            } else {
                balance -= mn - a[i];
                a[i] = mn;
            }
            --mnc;
        }
    }
    cout << ans;

    return 0;
}