#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll n;

int main()
{
    cin >> n;
    if (n % 2 == 1 || n <= 3) cout << 0;
    else {
        ll ans = n / 4;
        if (n % 4 == 0) --ans;
        cout << ans;
    }

    return 0;
}