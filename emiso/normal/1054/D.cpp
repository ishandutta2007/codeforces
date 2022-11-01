#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, k, a, mx, xo;
map<int, int> f;
ll tot, fz;

int main() {
    scanf("%d %d", &n, &k);
    mx = (1 << k) - 1;
    tot = 1LL * n * (n + 1) / 2;

    f[0]++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        xo ^= a;

        int f0 = f[xo];
        int fm = f[xo ^ mx];

        if(f0 > fm) xo ^= mx;
        fz += f[xo];

        f[xo]++;
    }

    //cerr << f0 << " - " << fm << endl;
    printf("%lld\n", tot - fz);
    return 0;
}