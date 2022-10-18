#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;


int main()
{
    ll n;
    cin >> n;
    n = -n;
    n = (n % 360 + 360) % 360;
    int mx = 999, mxc = -1;
    for (int i = 0; i < 4; ++i) {
        if (min((n + i * 90 + 360) % 360, 360 - (n + i * 90) % 360) < mx)
            mx = min((n + i * 90 + 360) % 360, 360 - (n + i * 90) % 360), mxc = i;
    }
    cout << mxc;

    return 0;
}