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

const long long P = 1000000000 + 7;
long long fact[10001], tcaf[10001];
long long delta[2001][2001];
long long well[2001][2001], cyl[2001];

long long deg(long long x, int d) {
    if (d == 0) {
        return 1;
    }
    long long y = deg(x, d / 2);
    y *= y; y %= P;
    if (d % 2) {
        y *= x; y %= P;
    }
    return y;
}

long long inv(long long x) {
    return deg(x, P - 2);
}

long long ways(int x, int y) {
    if (y == 1) {
        return 1;
    } else {
        return fact[x + 2 * y - 5] * tcaf[2 * y - 3] % P * tcaf[x - 2] % P;
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, M;
    cin >> N >> M;
    fact[0] = tcaf[0] = 1;
    for (int i = 1; i <= 10000; ++i) {
        fact[i] = (fact[i - 1] * i) % P;
        tcaf[i] = inv(fact[i]);
    }
    for (int x = 2; x <= M; ++x) {
        well[x][1] = 1;
        for (int y = 2; y <= N; ++y) {
            delta[x][y] = delta[x - 1][y] + ways(x, y); delta[x][y] %= P;
            well[x][y] = well[x][y - 1] + delta[x][y];
            well[x][y] %= P;
        }
    }
    for (int x = 2; x <= M; ++x) {
        for (int y = 1; y <= N; ++y) {
            cyl[x] += well[x][y] * (well[x][N - y + 1] - well[x][N - y] + P) % P;
            cyl[x] %= P;
        }
    }
    long long ans = 0;
    for (int x = 2; x <= M; ++x) {
        ans += cyl[x] * (M - x + 1); ans %= P;
    }
    cout << ans << '\n';

	return 0;
}