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

const int MAXN = 200000;
const int MAXT = 10000000;
const long long INF = 1e18;

int v[1 + MAXN];

long long compute(long long prod, long long sum, int l, int r) {
    long long a = prod + sum * l, b = prod + sum * r;
    return max(a, b);
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        sort(v + 1, v + n + 1);
        if (v[1] == 0 && v[n] == 0) {
            cout << "0\n";
            continue;
        }
        if (1LL * (n - 1) * v[1] + (sum - v[1]) > 0) {
            cout << "INF\n";
            continue;
        }
        if (1LL * (n - 1) * v[n] + (sum - v[n]) < 0) {
            cout << "INF\n";
            continue;
        }
        if (n == 2) {
            cout << 1LL * v[1] * v[2] << "\n";
            continue;
        }
        long long ans = -INF;
        long long prod = 0;
        sum = 0;
        for (int i = 2; i <= n; i++) {
            prod += 1LL * v[1] * v[i];
            sum += v[1] + v[i];
        }
        ans = max(ans, compute(prod, sum, -v[2], -v[1]));
        for (int i = 2; i < n; i++) {
            prod -= 1LL * v[i] * v[1];
            prod += 1LL * v[i] * v[n];
            sum -= v[i] + v[1];
            sum += v[i] + v[n];
            ans = max(ans, compute(prod, sum, -v[i + 1], -v[i]));
        }
        cout << ans << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}