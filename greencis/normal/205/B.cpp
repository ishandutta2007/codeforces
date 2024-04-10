#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[100005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = n-1; i >= 1; --i) {
        if (a[i-1] > a[i]) ans += ll(a[i-1] - a[i]);
    }
    cout << ans;

    return 0;
}