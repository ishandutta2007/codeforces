#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n, t, k, d;

int main()
{
    cin >> n >> t >> k >> d;
    ll a1 = t * ((n + k - 1) / k);
    ll L = d, R = 1000000;
    while (L < R) {
        ll mid = (L + R) / 2;
        ll cakes = mid / t * k + (mid - d) / t * k;
        if (cakes >= n)
            R = mid;
        else
            L = mid + 1;
    }
    if (a1 <= L)
        cout << "NO";
    else
        cout << "YES";
    cout << endl;

    return 0;
}