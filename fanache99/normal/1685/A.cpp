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

int v[1 + MAXN], w[1 + MAXN];

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
        if (n % 2 == 1) {
            cout << "NO\n";
        } else {
            map<int, int> f;
            for (int i = 1; i <= n; i++) {
                f[v[i]]++;
            }
            int biggest = 0;
            for (auto &it : f) {
                biggest = max(biggest, it.second);
            }
            if (biggest <= n / 2) {
                sort(v + 1, v + n + 1);
                for (int i = 1, j = n / 2; i <= n; i += 2) {
                    w[i] = v[j];
                    j--;
                }
                w[n] = v[n];
                for (int i = n - 2, j = n / 2 + 1; i >= 1; i -= 2) {
                    w[i] = v[j];
                    j++;
                }
                bool bad = (v[1] == v[n]);
                for (int i = 1; i < n; i++) {
                    if (w[i] == w[i + 1]) {
                        bad = true;
                    }
                }
                if (bad) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    for (int i = 1; i <= n; i++) {
                        cout << w[i] << " ";
                    }
                    cout << "\n";
                }
            } else {
                cout << "NO\n";
            }
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}