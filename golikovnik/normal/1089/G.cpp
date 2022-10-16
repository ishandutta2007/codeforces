#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#else
    //    freopen("cnf.in", "r", stdin);
    //    freopen("cnf.out", "w", stdout);
#endif
    int test;
    cin >> test;
    while (test--) {
        long long need;
        cin >> need;
        vector<long long> a(7);
        long long sum = 0;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            sum += a[i];
        }
        long long ans = LLONG_MAX;
        for (int start = 0; start < 7; start++) {
            long long bl = 1;
            long long br = 8 * need;
            long long curAns = br;
            while (bl <= br) {
                long long mid = (bl + br) / 2;
                long long cnt = mid / 7 * sum;
                for (int it = 0, i = start; it < mid % 7; it++, i = (i + 1) % 7) {
                    cnt += a[i];
                }
                if (cnt >= need) {
                    curAns = mid;
                    br = mid - 1;
                } else {
                    bl = mid + 1;
                }
            }
            ans = min(ans, curAns);
        }
        cout << ans << '\n';
    }
//    vector<vector<vector<int>>> dp(5, vector<vector<int>>(201, vector<int>(201, INT_MIN)));
//    for (int i = 0; i <= 13; i++) {
//        dp[0][15][i] = 1;
//        dp[0][i][15] = -1;
//    }
//    for (int i = 16; i <= 200; i++) {
//        dp[0][i][i - 2] = 1;
//        dp[0][i - 2][i] = -1;
//    }
//    for (int gamesAfter = 1; gamesAfter <= 4; gamesAfter++) {
//        for (int i = 25; i <= 200; i++) {
//            for (int j = 0; j <= 200; j++) {
//                for (int they = 0; they <= min(23, j); they++) {
//                    if (dp[gamesAfter - 1][])
//                }
//            }
//        }
//    }
//    int test;
//    cin >> test;
//    while (test--) {
//
//    }
}
// dp [    ] [   ] [   ]
//   -    ,    ()