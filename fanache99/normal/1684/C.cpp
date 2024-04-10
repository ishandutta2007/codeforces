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
        cin >> n >> m;
        vector<vector<int>> v(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> v[i][j];
            }
        }
        bool allGood = true, bad = false;
        int a, b;
        for (int i = 1; i <= n; i++) {
            vector<int> w = v[i];
            sort(w.begin() + 1, w.begin() + m + 1);
            vector<int> wrong;
            for (int j = 1; j <= m; j++) {
                if (v[i][j] != w[j]) {
                    wrong.push_back(j);
                }
            }
            if (!wrong.empty()) {
                allGood = false;
                assert(wrong.size() > 1);
                if (wrong.size() > 2) {
                    bad = true;
                } else {
                    a = wrong[0];
                    b = wrong[1];
                    break;
                }
            }
        }
        if (allGood) {
            cout << "1 1\n";
        } else if (bad) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                swap(v[i][a], v[i][b]);
                for (int j = 2; j <= m; j++) {
                    if (v[i][j] < v[i][j - 1]) {
                        bad = true;
                    }
                }
            }
            if (bad) {
                cout << "-1\n";
            } else {
                cout << a << " " << b << "\n";
            }
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}