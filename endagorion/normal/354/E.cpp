#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<long long> dp[20][10];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int T;
    cin >> T;
    while (T-->0) {
        long long N;
        cin >> N;
        for (int i = 0; i < 20; ++i) {
            for (int s = 0; s < 10; ++s) {
                dp[i][s].clear();
            }
        }
        dp[0][0].assign(6, 0);
        long long M = N;
        long long d10 = 1;
        for (int i = 0; i < 20; ++i) {
            for (int s = 0; s < 10; ++s) {
                if (dp[i][s].empty()) {
                    continue;
                }
                if (s > M) {
                    continue;
                }
                int d = M % 10;
                for (int q0 = 0; q0 <= 6; ++q0) {
                    for (int q4 = 0; q0 + q4 <= 6; ++q4) {
                        int q7 = 6 - q0 - q4;
                        if ((4 * q4 + 7 * q7 + s) % 10 == d) {
                            int ss = (4 * q4 + 7 * q7 + s) / 10;
                            dp[i + 1][ss] = dp[i][s];
                            for (int k = 0; k < 6; ++k) {
                                int a = (k < q0 ? 0 : (k < q0 + q4 ? 4 : 7));
                                dp[i + 1][ss][k] += d10 * a;
                            }
                        }
                    }
                }
            }
            M /= 10;
            d10 *= 10;
        }
        if (dp[19][0].empty()) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < 6; ++i) {
                cout << dp[19][0][i] << ' ';
            }
            cout << '\n';
        }
    }

	return 0;
}