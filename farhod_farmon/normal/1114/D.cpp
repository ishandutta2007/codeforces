#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int Q = 250200;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];
int d[N][N][2];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        int aa, b, c, dd;
        for(int i = n; i >= 1; i--){
                for(int j = i + 1; j <= n; j++){
                        aa = d[i][j - 1][0] + (a[j] != a[i]);
                        b = d[i][j - 1][1] + (a[j] != a[j - 1]);
                        c = d[i + 1][j][0] + (a[i] != a[i + 1]);
                        dd = d[i + 1][j][1] + (a[i] != a[j]);
                        d[i][j][0] = min(c, dd);
                        d[i][j][1] = min(aa, b);
                }
        }
        cout << min(d[1][n][0], d[1][n][1]) << "\n";
}