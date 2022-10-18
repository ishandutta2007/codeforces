#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (ll i = 1; i <= n; ++i)
        cout << (i == 1 ? 2 : i * i * (i + 2) + 1) << "\n";

    return 0;
}