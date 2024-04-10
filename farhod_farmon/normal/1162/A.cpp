#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 110;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int q;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
                a[i] = m;
        }
        for(int i = 1; i <= q; i++){
                int l, r, x;
                cin >> l >> r >> x;
                while(l++ <= r){
                        a[l - 1] = min(a[l - 1], x);
                }
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
                res += a[i] * a[i];
        }
        cout << res << "\n";
}