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

const int MAXC = 1000000;

int f[1 + MAXC];

int getF(int x, int y) {
    return f[y] - f[x - 1];
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, c;
        cin >> n >> c;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            f[x]++;
        }
        for (int i = 1; i <= c; i++) {
            f[i] += f[i - 1];
        }
        bool bad = false;
        for (int z = 1; z <= c; z++) {
            if (getF(z, z) == 0) {
                for (int y = 1; y * z <= c; y++) {
                    if (getF(y, y) != 0) {
                        int a = y * z, b = min(c, y * (z + 1) - 1);
                        if (getF(a, b) != 0) {
                            bad = true;
                        }
                    }
                }
            }
        }
        cout << (bad ? "No" : "Yes") << "\n";
        for (int i = 1; i <= c; i++) {
            f[i] = 0;
        }
    }
    return 0;
}