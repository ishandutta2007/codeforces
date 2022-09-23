#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int Q = 1 << 21;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int a[N];
int b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("teleports.in", "r", stdin);
        //freopen("teleports.out", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        if(a[n] > b[1]){
                cout << -1 << "\n";
                return 0;
        }
        long long res = 0;
        for(int i = 1; i <= n; i++){
                res += 1ll * a[i] * m;
        }
        for(int i = 2; i <= m; i++){
                res += b[i] - a[n];
        }
        if(b[1] != a[n]){
                res += b[1] - a[n - 1];
        }
        cout << res << "\n";
}