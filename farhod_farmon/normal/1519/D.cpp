#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int N = 5050;

int n;
long long a[N], b[N];
long long d[N][N];
long long s[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
                cin >> b[i];
                s[i] = s[i - 1] + a[i] * b[i];
        }
        long long res = 0;
        for(int i = n; i >= 1; i--){
                d[i][i] = a[i] * b[i];
                for(int j = i + 1; j <= n; j++){
                        d[i][j] = d[i + 1][j - 1] + a[i] * b[j] + a[j] * b[i];
                }
                for(int j = i; j <= n; j++){
                        res = max(res, d[i][j] - (s[j] - s[i - 1]));
                }
        }

        cout << s[n] + res << "\n";
}