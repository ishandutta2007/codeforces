#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = INF;
        for (int ones = 0; ones <= 5; ++ones) {
            for (int twos = 0; twos <= 5; ++twos) {
                int threes = 0;
                for (int x : a) {
                    int tmp = INF;
                    for (int i = 0; i <= ones; ++i) {
                        for (int j = 0; j <= twos; ++j) {
                            int c = x - i - 2 * j;
                            if (c < 0 || c % 3) {
                                continue;
                            }
                            tmp = min(tmp, c / 3);
                        }
                    }
                    threes = max(threes, tmp);
                }
                ans = min(ans, ones + twos + threes);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
1
5
1 4 7 8 10

 */