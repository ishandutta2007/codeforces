#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a[200105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    int mn = 2e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    ll ans = 0;
    int curmni = 0;
    for (int i = 0; i < n; ++i) {
        while (a[curmni] != mn) ++curmni %= n;
        ans = max(ans, mn * ll(n) + (curmni >= i ? curmni - i : curmni - i + n));
        if (curmni == i) ++curmni;
    }
    cout << ans;

    return 0;
}