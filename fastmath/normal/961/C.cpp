#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

const int MAXN = 107;

char a[4][MAXN][MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> a[i][j][k];
            }
        }
    }
    
    vector <int> p(4);
    for (int i = 0; i < 4; ++i) p[i] = i;
                                                               
    int ans = 1000000;
    for (int it = 0; it < 24; ++it) {
        
        int np1 = 0, np2 = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    int num = p[i];

                    int x = j;
                    int y = k;
                    if (i == 1 || i == 3) x += n;
                    if (i == 2 || i == 3) y += n;

                    np1 += ((x + y) % 2 != a[num][j][k] - '0');
                    np2 += ((x + y) != a[num][j][k] - '0');
                }
            }
        }
        ans = min(ans, min(np1, np2));

        next_permutation(p.begin(), p.end());
    }

    cout << ans << '\n';
    return 0;
}