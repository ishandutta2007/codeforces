#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 998244353;

using namespace std;

int n;
int a[N];
char s[N];
string bad = "hard";
long long d[N][5];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> s[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                for(int j = 0; j < 4; j++){
                        d[i][j] = 1e18;
                }
                for(int j = 0; j < 4; j++){
                        int nj = j + (s[i] == bad[j]);
                        d[i][nj] = min(d[i][nj], d[i - 1][j]);
                        d[i][j] = min(d[i][j], d[i - 1][j] + a[i]);
                }
        }
        long long res = 1e18;
        for(int i = 0; i < 4; i++){
                res = min(res, d[n][i]);
        }
        cout << res << "\n";
}