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

int v[1 + MAXN];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            ans += v[i];
            v[i] -= n - i;
        }
        sort(v + 1, v + n + 1);
        reverse(v + 1, v + n + 1);
        for (int i = 1; i <= k; i++) {
            ans -= v[i];
        }
        ans -= 1LL * k * (k - 1) / 2;
        cout << ans << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}