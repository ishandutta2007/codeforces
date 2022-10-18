#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll n, k, ans;

int main()
{
    cin >> n >> k;
    for (int i = 1; i + i <= n && i <= k; ++i) {
        ans += 2 * (n - 2 * i + 2) - 3;
    }
    cout << ans;

    return 0;
}