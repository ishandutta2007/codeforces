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

int a[1 + MAXN], b[1 + MAXN], wa[1 + MAXN], wb[1 + MAXN];
bool seen[1 + MAXN];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            wa[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            wb[b[i]] = i;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                int l = 0, j = i;
                while (!seen[j]) {
                    l++;
                    seen[j] = true;
                    j = wb[a[j]];
                }
                sum += l / 2;
            }
        }
        assert(2 * sum <= n);
        long long ans = 0;
        for (int i = 1; i <= sum; i++) {
            ans += 2 * (n - i + 1) - 2 * i;
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) {
            seen[i] = false;
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}