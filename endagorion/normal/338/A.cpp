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

const long long P = 1000000000 + 9;

long long deg(long long d) {
    if (d == 0) {
        return 1;
    }
    long long y = deg(d / 2);
    y = (y * y) % P;
    if (d % 2) {
        y = (y + y) % P;
    }
    return y;
}

long long score(long long c, long long k) {
    long long p = c / k;
    long long y = (2 * k * (deg(p) + P - 1)) % P;
    return (y + c % k) % P;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    long long N, M, K;
    cin >> N >> M >> K;
    long long x = N - M;

    if (K * x <= N) {
        long long sc = score(N - K * x, K);
        cout << (sc + (K - 1) * x) % P << '\n';
    } else {
        cout << M << '\n';
    }

	return 0;
}