#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int n, m;
        cin >> n >> m;
        if (m == 1) {
                cout << n - 1 << "\n";
        } else {
                cout << 1ll * n * (m - 1) << "\n";
        }
}