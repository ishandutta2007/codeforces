#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int n, r;
int x[N], y[N], t[N], d[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> r >> n;
        x[0] = y[0] = 1;
        r *= 4;
        int res = 0;
        for(int i = 1; i <= n; i++){
                d[i] = - n - 1;
                cin >> t[i] >> x[i] >> y[i];
                for(int j = max(i - r, 0); j < i; j++){
                        if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]){
                                d[i] = max(d[i], d[j] + 1);
                        }
                }
                res = max(res, d[i]);
        }
        cout << res << "\n";
}