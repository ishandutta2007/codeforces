#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const int P = 1e9+7;
const ll lINF = 1e18;

using namespace std;

int n, d, a[100000], dp[61000][610];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d", &j);
        a[j]++;
    }
    int mn = max(1, d-300), mx = min(30000, d+300);
    for (int i = 30000; i>=0; i--) {
        for (int j = mn; j<=mx; j++) {
            dp[i][j-mn] = a[i] + dp[i+j][j-mn];
            dp[i][j-mn] = max(dp[i][j-mn], a[i] + dp[i+j+1][j+1-mn]);
            if (j>1) {
                dp[i][j-mn] = max(dp[i][j-mn], a[i] + dp[i+j-1][j-1-mn]);
            }
        }
    }
    cout << a[0] + dp[d][d-mn] << endl;
    return 0;
}