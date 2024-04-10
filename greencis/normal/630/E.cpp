#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ll cnt(ll x, ll y) {
    return ((y + 1) * (x + 1) + (x % 2 == 0 && y % 2 == 0)) / 2;
}

int main()
{
    ll xa,ya,xb,yb;
    cin >> xa >> ya >> xb >> yb;
    if ((xa + ya) % 2) ya += 1, yb += 1;
    xa += 2e9; xb += 2e9;
    ya += 2e9; yb += 2e9;
    cout << cnt(xb, yb) - cnt(xb, ya - 1) - cnt(xa - 1, yb) + cnt(xa - 1, ya - 1);

    return 0;
}