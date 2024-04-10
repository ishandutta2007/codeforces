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
        int n;
        cin >> n;
        bool all0 = true;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (v[i] != 0) {
                all0 = false;
            }
        }
        if (all0) {
            cout << "0\n";
        } else {
            int i = 1;
            while (i <= n && v[i] == 0) {
                i++;
            }
            while (i <= n && v[i] != 0) {
                i++;
            }
            while (i <= n && v[i] == 0) {
                i++;
            }
            if (i <= n) {
                assert(v[i] != 0);
                cout << "2\n";
            } else {
                cout << "1\n";
            }
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}