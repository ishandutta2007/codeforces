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

        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        sort(a.begin(), a.end());
        int got = 0, res = 0;
        for (int i = n - 1; i >= 0; i--) {
                int x = d / a[i] + 1;
                if (x <= n - got) {
                        got += x;
                        res += 1;
                }
        }
        cout << res << "\n";
}