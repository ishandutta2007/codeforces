#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, m;

int next_elev(int s, int t) {
    int mod = t % (2 * (m - 1)), full = t - mod;
    int board;
    if (mod <= s) {
        board = full + s;
    } else {
        if (mod <= 2 * (m - 1) - s) {
            board = full + 2 * (m - 1) - s;
        } else {
            board = full + 2 * (m - 1) + s;
        }
    }
    return board;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int s, f, t;
        cin >> s >> f >> t;
        --s; --f;
        int t1 = next_elev(s, t);
        int t2 = next_elev(f, t1);
        if (s == f) {
            t2 = t;
        }
        cout << t2 << '\n';
    }

    return 0;
}