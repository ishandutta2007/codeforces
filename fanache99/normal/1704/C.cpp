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
        int m, n;
        cin >> m >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v + 1, v + n + 1);
        vector<int> l;
        auto add = [&](int x) {
            l.push_back(x);
        };
        for (int i = 2; i <= n; i++) {
            add(v[i] - v[i - 1] - 1);
        }
        add(m - v[n] + v[1] - 1);
        sort(l.begin(), l.end());
        reverse(l.begin(), l.end());
        int ans = 0, id = 0;
        for (auto x : l) {
            id++;
            x = max(0, x - 4 * (id - 1));
            if (x > 0) {
                ans++;
                x = max(0, x - 2);
                ans += x;
            }
        }
        cout << m - ans << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}