#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 400200;

using namespace std;

int n;
long long d[N * 2];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        long long res = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                long long cur = d[i - x + N];
                cur += x;
                res = max(res, cur);
                d[i - x + N] = max(d[i - x + N], cur);
        }
        cout << res << "\n";
}