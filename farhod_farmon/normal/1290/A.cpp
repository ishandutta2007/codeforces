#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 3550;
const int mod = 998244353;

using namespace std;

int n;
int m;
int k;
int a[N];

int solve(int l, int r)
{
        int res = 1e9;
        int g = (r - l + 1) - (m - 1);
        for(int i = l; i + g - 1 <= r; i++){
                res = min(res, max(a[i], a[i + g - 1]));
        }
        return res;
}

void solve()
{
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        k = min(k, m - 1);
        m -= k;

        int res = 0;
        for(int a = 0; a <= k; a++){
                res = max(res, solve(a + 1, n - (k - a)));
        }
        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}