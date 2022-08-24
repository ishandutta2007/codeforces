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

const int M = 70;
int f[2 * M + 1][2 * M + 1];
int tx[10000], ty[10000];
int tc;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, T;
    cin >> N >> T;
    f[M][M] = N;
    bool proceed = true;
    while (proceed) {
        bool changed = false;
        tc = 0;
        for (int i = 1; i < 2 * M; ++i) {
            for (int j = 1; j < 2 * M; ++j) {
                if (f[i][j] >= 4) {
                    tx[tc] = i;
                    ty[tc] = j;
                    ++tc;
                }
            }
        }
        for (size_t i = 0; i < tc; ++i) {
            int x = tx[i], y = ty[i];
            f[x][y] -= 4;
            ++f[x + 1][y];
            ++f[x - 1][y];
            ++f[x][y + 1];
            ++f[x][y - 1];
        }

        proceed = tc > 0;
    }
    for (int i = 0; i < T; ++i) {
        int x, y;
        cin >> x >> y;
        if (x >= -M && x <= M && y >= -M && y <= M) {
            cout << f[x + M][y + M] << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

	return 0;
}