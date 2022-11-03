#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 200 + 13;
const int K = 10;

/*
2 1 9
1 2 1
*/

li dp[N][N][N];
int a1[N], a2[N], a3[N];

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    for(int i = 0; i < n1; i++) {
        cin >> a1[i];
    }

    for(int i = 0; i < n2; i++) {
        cin >> a2[i];
    }

    for(int i = 0; i < n3; i++) {
        cin >> a3[i];
    }

    sort(a1, a1 + n1);
    sort(a2, a2 + n2);
    sort(a3, a3 + n3);

    reverse(a1, a1 + n1);
    reverse(a2, a2 + n2);
    reverse(a3, a3 + n3);

    dp[0][0][0] = 0;

    for(int i1 = 0; i1 <= n1; i1++) {
        for(int i2 = 0; i2 <= n2; i2++) {
            for(int i3 = 0; i3 <= n3; i3++) {
//                cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << dp[i1][i2][i3] << endl;
//                if(i1 == 2 && i2 == 0 && i3 == 2) {
//                    cout << dp[i1][i2 + 1][i3 + 1] << ' ' << dp[i1][i2][i3] + a3[i3] * a2[i2] << endl;
//                }
                if(n1 - i1 >= 1 && n2 - i2 >= 1)
                    dp[i1 + 1][i2 + 1][i3] = max(dp[i1 + 1][i2 + 1][i3], dp[i1][i2][i3] + a1[i1] * a2[i2]);

                if(n1 - i1 >= 1 && n3 - i3 >= 1)
                    dp[i1 + 1][i2][i3 + 1] = max(dp[i1 + 1][i2][i3 + 1], dp[i1][i2][i3] + a1[i1] * a3[i3]);

                if(n3 - i3 >= 1 && n2 - i2 >= 1)
                    dp[i1][i2 + 1][i3 + 1] = max(dp[i1][i2 + 1][i3 + 1], dp[i1][i2][i3] + a3[i3] * a2[i2]);

//                cout << dp[n1][n2][n3] << endl;

                if(n1 - i1 >= 1)
                    dp[i1 + 1][i2][i3] = max(dp[i1 + 1][i2][i3], dp[i1][i2][i3]);
                if(n2 - i2 >= 1)
                    dp[i1][i2 + 1][i3] = max(dp[i1][i2 + 1][i3], dp[i1][i2][i3]);
                if(n3 - i3 >= 1)
                    dp[i1][i2][i3 + 1] = max(dp[i1][i2][i3 + 1], dp[i1][i2][i3]);

            }
        }
    }

    cout << dp[n1][n2][n3] << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}