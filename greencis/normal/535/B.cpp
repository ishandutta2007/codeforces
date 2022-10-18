#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,ans,a,k=1,z;

int main()
{
    cin >> n;
    a = n;
    while (a >= 10) {
        ans += (1 << k);
        ++k;
        a /= 10;
    }
    a = 0;
    for (int i = 0; i < k; ++i) {
        a <<= 1;
        if (n % 10 == 7) a |= 1;
        n /= 10;
    }
    for (int i = 0; i < k; ++i) {
        z <<= 1;
        z |= (a & 1);
        a >>= 1;
    }
    cout << ans + z + 1;

    return 0;
}