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


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    long long X, Y, M;
    cin >> X >> Y >> M;

    if (X >= M || Y >= M) {
        cout << 0 << '\n';
        return 0;
    }

    if (X <= 0 && Y <= 0) {
        cout << -1 << '\n';
        return 0;
    }

    long long ans = 0;
    if (X < Y) {
        swap(X, Y);
    }
    while (X < M && Y < M) {
        long long k = (X - Y) / X + 1;
        Y += k * X;
        ans += k;
        swap(X, Y);
    }

    cout << ans << '\n';

	return 0;
}