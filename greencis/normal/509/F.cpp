#include <iostream>
#include <fstream>
#include <cmath>
#define MOD 1000000007ll
using namespace std;
typedef long double ld;
typedef long long ll;

int n,b[999],d[999][999];

int solve(int l, int r) {
    if (l > r) return 1;
    if (!d[l][r]) {
        d[l][r] = solve(l + 1, r);
        for (int i = l+1; i <= r; ++i)
            if (b[l] < b[i])
                d[l][r] = (d[l][r] + ll(solve(l+1,i-1)) * ll(solve(i,r))) % MOD;
        ++d[l][r];
    }
    return d[l][r] - 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    cout << solve(2,n);
    return 0;
}