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

typedef pair<int, int> pii;

const int M = 1e6;
int dp[2 * M + 11];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, K;
    scanf("%d%d", &N, &K);
    //vector<pii> segs;
    for (int i = 0; i <= 2 * M; ++i) {
        dp[i] = 1e9;
    }
    for (int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);
        //segs.pb(mp(max(1, x - K), x));
        int b = max(1, x - K);
        dp[b - 1] = min(dp[b - 1], x);
    }
    for (int i = M; i >= 0; --i) {
        dp[i] = min(dp[i], dp[i + 1]);
    }
    for (int c = M; c >= 1; --c) {
        bool ok = true;
        for (int i = 0; dp[i] < 1e8; i += c) {
            if (dp[i] < i + c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << c << '\n';
            break;
        }
    }

	return 0;
}