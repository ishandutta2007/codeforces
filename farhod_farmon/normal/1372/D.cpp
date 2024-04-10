#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n, a[N];
long long d[N][2];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        d[1][0] = a[1];
        for(int i = 2; i <= n; i++){
                d[i][1] = d[i - 2][1] + a[i];
                d[i][0] = d[i - 2][0] + a[i];
                d[i][1] = max(d[i][1], d[i - 1][0] + a[i]);
        }

        long long res = 0;
        res = max(res, d[n][0]);
        res = max(res, d[n][1]);
        res = max(res, d[n - 1][0]);
        res = max(res, d[n - 1][1]);

        cout << res << "\n";
}