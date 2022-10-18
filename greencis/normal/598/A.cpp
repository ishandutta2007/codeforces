#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

ll t,n,x;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        x = n * (n + 1ll) / 2ll;
        for (ll i = 1; i <= n; i <<= 1ll)
            x -= i + i;
        cout << x << endl;
    }

    return 0;
}