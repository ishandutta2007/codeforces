#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n,a[29],sum,prv=9e18;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = n-1; i >= 0; --i) {
        prv = max(0ll, min(prv - 1, a[i]));
        sum += prv;
    }
    cout << sum;

    return 0;
}