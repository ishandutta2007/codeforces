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

long long v[1 + MAXN];

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
        queue<long long> f1, f2, f3;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        sort(v + 1, v + n + 1);
        for (int i = n; i >= 1; i--) {
            f1.push(v[i]);
        }
        f2.push(sum);
        bool bad = false;
        int steps = 0;
        while (!f1.empty()) {
            assert(!f2.empty() || !f3.empty());
            steps++;
            if (steps > 10 * n) {
                bad = true;
                break;
            }
            long long x;
            if (!f2.empty() && (f3.empty() || f2.front() > f3.front())) {
                x = f2.front();
                f2.pop();
            } else {
                x = f3.front();
                f3.pop();
            }
            if (f1.front() > x) {
                bad = true;
                break;
            }
            if (f1.front() == x) {
                f1.pop();
                continue;
            }
            long long x1 = x / 2, x2 = x - x1;
            f2.push(x2);
            f3.push(x1);
        }
        cout << (bad ? "NO" : "YES") << "\n";
    }



    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}