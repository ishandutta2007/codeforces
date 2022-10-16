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

const int MAXN = 50;

char a[1 + MAXN + 1], b[1 + MAXN + 1];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
//        string a, b;
        cin >> n >> m >> (a + 1) >> (b + 1);
        if (n < m) {
            cout << "NO\n";
            continue;
        }
        bool good = false;
        for (int i = 1; i <= n - m + 1; i++) {
            good |= (a[i] == b[1]);
        }
        for (int i = 2; i <= m; i++) {
            good &= (b[i] == a[i + n - m]);
        }
        cout << (good ? "YES" : "NO") << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}