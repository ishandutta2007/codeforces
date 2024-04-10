#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

static const int kMaxN = 500;
bitset<kMaxN> P[64][kMaxN], B[64][kMaxN], BT[kMaxN], PT[kMaxN];

int main() {
    ios::sync_with_stdio(false);
    int N, M; cin >> N >> M;

    while (M--) {
        int x, y, t; cin >> x >> y >> t;
        --x; --y;
        if (t == 0)
            P[0][x][y] = true;
        else
            B[0][x][y] = true;
    }
    for (int i = 1; i < 64; ++i) {
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k) {
                BT[j][k] = B[i - 1][k][j];
                PT[j][k] = P[i - 1][k][j];
            }

        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k) {
                P[i][j][k] = ((P[i - 1][j] & BT[k]).count() > 0);
                B[i][j][k] = ((B[i - 1][j] & PT[k]).count() > 0);
            }
    }

    vector<int64_t> answer0(N, -1), answer1(N, -1), oldanswer0 = answer0, oldanswer1 = answer1;
    answer0[0] = 0;
    for (int i = 60; i >= 0; --i) {
        oldanswer0 = answer0;
        oldanswer1 = answer1;
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k) {
                if (oldanswer0[j] != -1 && P[i][j][k])
                    answer1[k] = max(answer1[k], oldanswer0[j] + (1LL << i));
                if (oldanswer1[j] != -1 && B[i][j][k])
                    answer0[k] = max(answer0[k], oldanswer1[j] + (1LL << i));
            }
    }

    int64_t best = max(*max_element(answer0.begin(), answer0.end()),
                       *max_element(answer1.begin(), answer1.end()));;
    if (best > 1000LL * 1000 * 1000 * 1000 * 1000 * 1000)
        cout << "-1\n";
    else
        cout << best << "\n";
}