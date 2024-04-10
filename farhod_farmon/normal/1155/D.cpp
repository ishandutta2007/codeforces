#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
long long d[N][3];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        long long k;
        cin >> n >> k;

        long long res = 0;
        for(int i = 1; i <= n; i++){
                long long x;
                cin >> x;

                d[i][0] = d[i - 1][0] + x;
                d[i][1] = max(d[i - 1][0], d[i - 1][1]) + x * k;
                d[i][2] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2])) + x;

                d[i][1] = max(d[i][1], d[i][0]);
                d[i][2] = max(d[i][2], d[i][1]);

                d[i][0] = max(d[i][0], 0ll);
                d[i][1] = max(d[i][1], 0ll);
                d[i][2] = max(d[i][2], 0ll);

                res = max(res, d[i][2]);
        }

        cout << res << "\n";
}