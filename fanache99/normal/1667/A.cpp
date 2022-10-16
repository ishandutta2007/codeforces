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

const int MAXN = 5000;
const long long INF = 1e18;

long long a[1 + MAXN];

long long solve(int p, int n) {
    long long before = 0, ans = 0;
    for (int i = p + 1; i <= n; i++) {
        long long t = before / a[i] + 1;
        ans += t;
        long long x = t * a[i];
        assert(x > before);
        before = x;
    }
    before = 0;
    for (int i = p - 1; i >= 1; i--) {
        long long t = before / a[i] + 1;
        ans += t;
        long long x = t * a[i];
        assert(x > before);
        before = x;
    }
    return ans;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, solve(i, n));
    }
    cout << ans << "\n";

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}