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

int f[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, X;

bool stop(int x, int y) {
    return x < 0 || x >= N || y < 0 || y >= N || f[x][y] != 0;
}

int count(int x, int y) {
    int c = 0;
    int p = 0;
    while (p < 10000000) {
        if (x < 0 || x >= N || y < 0 || y >= N) {
            return c;
        }
        if (f[x][y] == 0) {
            return c;
        }
        ++p;
        int dd = f[x][y] - 1;
        //cout << dd << '\n';
        int xx = x + dx[dd], yy = y + dy[dd];
        if (stop(xx, yy)) {
            //return count(xx, yy);
            x = xx;
            y = yy;
            continue;
        }
        while (!stop(xx + dx[dd], yy + dy[dd])) {
            xx += dx[dd];
            yy += dy[dd];
        }
        f[xx][yy] = f[x][y];
        f[x][y] = 0;
        //return 1 + count(xx + dx[dd], yy + dy[dd]);
        ++c;
        x = xx + dx[dd];
        y = yy + dy[dd];
    }
    return c;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            f[i][j] = 0;
        }
    }
    /*for (int i = 0; i < (N - 1) / 2; ++i) {
        for (int j = i; j < N - i - 1; ++j) {
            f[i][j] = 1;
            f[j][N - i - 1] = 2;
            f[N - i - 1][N - j - 1] = 3;
            f[N - j - 1][i] = 4;
        }
        for (int j = 0; j < (N - 2 * i) / 3; ++j) {
            f[i][N - i - 2 - 2 * j] = 0;
            f[N - i - 2 - 2 * j][N - i - 1] = 0;
            f[N - i - 1][i + 1 + 2 * j] = 0;
            f[i + 1 + 2 * j][i] = 0;
        }
    }*/
    for (int l = 0; l < max(N / 4, 1); ++l) {
        for (int j = 0; j < N; ++j) {
            f[4 * l][j] = f[4 * l + 3][j] = 1;
            f[4 * l + 1][j] = f[4 * l + 2][j] = 3;
        }
        //f[4 * l + 1][N - 2] = 0;
        f[4 * l][N - 1] = f[4 * l + 2][0] = 2;
        f[4 * l + 1][0] = f[4 * l + 3][N - 1] = 4;
        for (int j = 0; j < (N - 1) / 3; ++j) {
            f[4 * l][N - 2 - 2 * j] = f[4 * l + 2][1 + 2 * j] = 0;
        }
        for (int j = 0; j < (N - 1) / 3 + 1; ++j) {
            f[4 * l + 1][1 + 2 * j] = f[4 * l + 3][N - 2 - 2 * j] = 0;
        }
    }
    //cout << count(0, 0) << '\n';
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ".>v<^"[f[i][j]];
        }
        cout << '\n';
    }
    cout << "1 1\n";
    //cout << (N - 1) / 2 << ' ' << (N - 1) / 2 << '\n';

    
    

	return 0;
}