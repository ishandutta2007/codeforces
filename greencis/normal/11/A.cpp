#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n,d,a[2005],ans;

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n-1; ++i) {
        if (a[i] >= a[i+1]) {
            ll cnt = (a[i] - a[i+1]) / d + 1;
            ans += cnt;
            a[i+1] += cnt * d;
        }
    }
    cout << ans;

    return 0;
}