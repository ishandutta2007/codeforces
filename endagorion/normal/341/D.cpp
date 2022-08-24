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

long long f[2][2][1500][1500];
int N;

void sset(int i, int j, int x, int y, long long v) {
    for (int xx = x; xx <= N + 1; xx = xx | (xx + 1)) {
        for (int yy = y; yy <= N + 1; yy = yy | (yy + 1)) {
            f[i][j][xx][yy] ^= v;
        }
    }
}

long long get(int i, int j, int x, int y) {
    long long r = 0;
    for (int xx = x; xx > 0; xx = (xx & (xx + 1)) - 1) {
        for (int yy = y; yy > 0; yy = (yy & (yy + 1)) - 1) {
            r ^= f[i][j][xx][yy];
        }
    }
    return r;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            --x1; --y1;
            long long v = 0;
            v ^= get(x1 % 2, y1 % 2, x1, y1);
            v ^= get(x1 % 2, y2 % 2, x1, y2);
            v ^= get(x2 % 2, y1 % 2, x2, y1);
            v ^= get(x2 % 2, y2 % 2, x2, y2);
            cout << v << '\n';
        } else {
            int x1, y1, x2, y2;
            long long v;
            scanf("%d%d%d%d%I64d", &x1, &y1, &x2, &y2, &v);
            ++x2; ++y2;
            sset(x1 % 2, y1 % 2, x1, y1, v);
            sset(x1 % 2, y2 % 2, x1, y2, v);
            sset(x2 % 2, y1 % 2, x2, y1, v);
            sset(x2 % 2, y2 % 2, x2, y2, v);
        }
    }

	return 0;
}