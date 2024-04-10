//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 5000 + 10;
const ll INF = 2e18;
ll p1, t1, p2, t2, h, s;
ll best[nax];
ll dp[nax];

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
        best[0] = 0;
        for(int i = 1; i <= h; ++i) {
                best[i] = INF;
                dp[i] = INF;
        }
        for(int a = 0; a <= h; ++a) {
                for(int b = 0; b <= h; ++b) {
                        int ind2 = min(h, (p1 - s) * a + (p2 - s) * b);
                        dp[ind2] = min(dp[ind2], max(t1 * a, t2 * b));
                        int ind = min(h, (p1-s) * a + (p2-s) * b + (p1 + p2 - s));
                        best[ind] = min(best[ind], max(t1 * (a + 1), t2 * (b + 1)));
                }
        }
        for(int i = h - 1; i >= 1; --i) {
                best[i] = min(best[i], best[i + 1]);
        }
        for(int i = 1; i <= h; ++i) {
                for(int j = i; j >= 0; --j) {
                        dp[i] = min(dp[i], dp[j] + best[i - j]);
                }
        }
        cout << dp[h];
}