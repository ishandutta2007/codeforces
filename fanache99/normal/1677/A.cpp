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

int v[1 + MAXN], s[1 + MAXN];

int get(int x, int y) {
    if (x > y) {
        return 0;
    }
    return s[y] - s[x - 1];
}

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
            cin >> v[i];
        }

        long long ans = 0;
        for (int c = 1; c <= n; c++) {
            for (int i = 0; i <= n; i++) {
                s[i] = 0;
            }
            for (int d = c + 1; d <= n; d++) {
                s[v[d]]++;
            }
            for (int i = 1; i <= n; i++) {
                s[i] += s[i - 1];
            }
            long long curr = 0;
            for (int b = 1; b < c; b++) {
                curr += s[v[b] - 1];
            }
            for (int a = 1; a < c; a++) {
                curr -= s[v[a] - 1];
                if (v[a] < v[c]) {
                    ans += curr;
                }
            }
        }
        cout << ans << "\n";

        for (int i = 0; i <= n; i++) {
            s[i] = 0;
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}