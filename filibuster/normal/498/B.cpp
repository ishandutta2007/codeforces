#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 5000 + 13;
const int M = 6;
const int A = 21;
const int LOGN = 20;
const int B = 3;//300;

/*
5
4 2
6 2
8 3
9 1
14 4
1
1 5
*/


int p[N], t[N];
ld dp1[N], dp2[N];

signed main() {
    int n, T;
    cin >> n >> T;

    for(int i = 0; i < n; i++) {
        cin >> p[i] >> t[i];
    }

    for(int i = 1; i < N; i++)
        dp1[i] = 0;
    dp1[0] = 1;

    ld ans = 0;
    for(int i = 0; i < n; i++) {
        vector<ld> pw1(T + 1, 1);
        for(int j = 1; j < pw1.size(); j++) {
//            pw[j] = pw[j - 1] * ld(p[i]) / 100;
            pw1[j] = pw1[j - 1] * ld(100 - p[i]) / 100;
        }


        ld s = 0;
        for(int j = 1; j <= T; j++) {
            if(j >= t[i])
                dp2[j] = dp1[j - t[i]] * pw1[t[i] - 1];

            if(t[i] > 1) {
                if(j >= t[i]) {
                    s -= dp1[j - t[i]] * pw1[t[i] - 2];
                }

                s = s * ld(100 - p[i]) / 100 + dp1[j - 1];

                dp2[j] += s * p[i] / 100;
            }


//            cout << i + 1 << ' ' << j << ' '<< dp[i + 1][j] << ' ' << s << endl;
            ans += dp2[j];
        }

        for(int j = 0; j <= T; j++) {
            dp1[j] = dp2[j];
            dp2[j] = 0;
        }
    }

    cout << setprecision(20) << fixed << ans << endl;
}