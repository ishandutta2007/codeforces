#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 200200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int f[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int res = 0, mx = 0;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                f[a[x]] -= 1;
                a[x] += 1;
                f[a[x]] += 1;
                mx = max(mx, a[x]);
                if(f[mx] * mx == i - 1 || f[mx - 1] * (mx - 1) + mx - 1 == i - 1 || mx == 1){
                        res = i;
                }
        }
        cout << res << "\n";
}