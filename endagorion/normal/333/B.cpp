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

int rows[1000], cols[1000];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        rows[x] = 1;
        cols[y] = 1;
    }

    int ans = 0;
    for (int i = 1; i < N / 2; ++i) {
        ans += 4 - rows[i] - rows[N - i - 1] - cols[i] - cols[N - i - 1];
    }

    if (N % 2 == 1) {
        if (rows[N / 2] == 0 || cols[N / 2] == 0) {
            ++ans;
        }
    }

    cout << ans << '\n';

	return 0;
}