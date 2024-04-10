#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, dp[9][800][2005];
int a[2005], b[2005];
deque<pair<pii, pii>> v; /// TIME/FLOOR/WHO'S THERE/WHOM TO PICK
int mask[10000], revmask[10000];

int main() {
    ios_base::sync_with_stdio(false);

    int maskidx = 0;
    for (int a = 0; a <= 9; ++a) {
        for (int b = a; b <= 9; ++b) {
            for (int c = b; c <= 9; ++c) {
                for (int d = c; d <= 9; ++d) {
                    int cur = a * 1000 + b * 100 + c * 10 + d;
                    mask[maskidx] = cur;
                    vector<int> p = { a, b, c, d };
                    do {
                        cur = p[0] * 1000 + p[1] * 100 + p[2] * 10 + p[3];
                        revmask[cur] = maskidx;
                    } while (next_permutation(all(p)));
                    ++maskidx;
                }
            }
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 800; ++j)
            for (int z = 0; z < 2005; ++z)
                dp[i][j][z] = 1e9;
    v.push_back({{0, 0}, {0, 0}});
    while (v.size()) {
        auto& x = v.front();
        int i = x.first.first;
        int curfloor = x.first.second;
        int curmask = x.second.first;
        int curnxt = x.second.second;
        v.pop_front();
        if (dp[curfloor][curmask][curnxt] <= i)
            continue;
        dp[curfloor][curmask][curnxt] = i;
        if (curnxt >= n && !curmask)
            continue;
        if (curfloor < 8)
            v.push_back({{i + 1, curfloor + 1}, {curmask, curnxt}});
        if (curfloor > 0)
            v.push_back({{i + 1, curfloor - 1}, {curmask, curnxt}});
        int numbers = mask[curmask];
        int deg10 = 1;
        for (int j = 0; j < 4; ++j) {
            if (numbers / deg10 % 10 - 1 == curfloor)
                numbers -= (curfloor + 1) * deg10;
            deg10 *= 10;
        }
        v.push_front({{i, curfloor}, {revmask[numbers], curnxt}});
        if (a[curnxt] == curfloor + 1) {
            numbers = mask[curmask];
            if (numbers / 1000 % 10 == 0) {
                numbers += b[curnxt] * 1000;
                v.push_front({{i, curfloor}, {revmask[numbers], curnxt + 1}});
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < 9; ++i)
        ans = min(ans, dp[i][0][n]);
    cout << ans + n * 2 << endl;
}