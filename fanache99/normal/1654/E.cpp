#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int MAXN = 100000;
const int SQRT = 400;

int v[1 + MAXN];
int f[1 + 2 * MAXN * SQRT + 10 * MAXN];

int aSmall(int n, int a) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int b = v[i] - i * a;
        f[b + MAXN * SQRT]++;
        ans = max(ans, f[b + MAXN * SQRT]);
    }
    for (int i = 1; i <= n; i++) {
        int b = v[i] - i * a;
        f[b + MAXN * SQRT]--;
    }
    return ans;
}

int aBig(int n, int p) {
    int ans = 0;
    int l = max(1, p - SQRT), r = min(n, p + SQRT);
    for (int i = l; i <= r; i++) {
        if (i != p && (v[p] - v[i]) % (p - i) == 0) {
            int a = (v[p] - v[i]) / (p - i);
            f[a + MAXN * SQRT]++;
            ans = max(ans, f[a + MAXN * SQRT]);
        }
    }
    for (int i = l; i <= r; i++) {
        if (i != p && (v[p] - v[i]) % (p - i) == 0) {
            int a = (v[p] - v[i]) / (p - i);
            f[a + MAXN * SQRT]--;
        }
    }
    return ans + 1;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    int ans = 0;

    for (int a = -SQRT; a <= SQRT; a++) {
        ans = max(ans, aSmall(n, a));
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, aBig(n, i));
    }

    cout << n - ans << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}