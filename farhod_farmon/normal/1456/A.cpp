#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n, p, k;
int s[N];
char c[N];

void solve()
{
        cin >> n >> p >> k;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                s[i] = 0;
        }
        s[n + 1] = 0;
        for(int i = n; i >= 1; i--){
                s[i] = c[i] - '0';
                s[i] ^= 1;
                if(i + k <= n){
                        s[i] += s[i + k];
                }
        }
        int x, y;
        cin >> x >> y;
        int res = 2e9;
        for(int i = p; i <= n; i++){
                res = min(res, (i - p) * y + x * s[i]);
        }
        cout << res << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}