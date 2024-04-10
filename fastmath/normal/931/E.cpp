#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <queue>

using namespace std;

const int MAXN = 7007;

#define double long double

vector <string> a[26];
int counter[26][MAXN][26];
int cnt[26];

signed main() {
    ios_base::sync_with_stdio(false);
    cout.precision(30);
        
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        string t = s.substr(i, n - i) + s.substr(0, i);
        int num = t[0] - 'a';
        ++cnt[num];

        for (int j = 0; j < n; ++j) {
            ++counter[num][j][t[j] - 'a'];
        }
    }

    double ans = 0;
    for (int num = 0; num < 26; ++num) {
        double best = 0;
        for (int i = 0; i < n; ++i) {
            int x = 0;
            int y = 0;
            for (int c = 0; c < 26; ++c) {
                if (counter[num][i][c] == 1) x += 1;
                y += counter[num][i][c];
            }

            best = max(best, (double) x / (double) y);
        }

        ans += ((double) (cnt[num]) / (double) (n)) * best;
    }

    cout << ans << '\n';

    return 0;
}