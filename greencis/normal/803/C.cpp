#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n, k;
vector<ll> divrs, divrs2;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    if (k >= 1000000LL || k * (k + 1LL) / 2LL > n) {
        cout << -1 << endl;
        return 0;
    }

    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divrs.push_back(i);
            if (i * i < n)
                divrs2.push_back(n / i);
        }
    }

    divrs.insert(divrs.end(), divrs2.rbegin(), divrs2.rend());

    int i = (int)divrs.size() - 1;
    while (k * (k + 1LL) / 2LL > n / divrs[i])
        --i;

    ll curnum = 0;
    ll cursum = 0;
    for (ll j = k; j--; ) {
        if (j == 0)
            cout << n - cursum << endl;
        else {
            curnum += divrs[i];
            cursum += curnum;
            cout << curnum << " ";
        }
    }

    return 0;
}