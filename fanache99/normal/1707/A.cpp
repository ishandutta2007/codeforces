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
char s[1 + MAXN + 1];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int x = 0;
        for (int i = n; i >= 1; i--) {
            if (v[i] > x && x == q) {
                s[i] = '0';
            } else {
                s[i] = '1';
                if (v[i] > x) {
                    x++;
                }
            }
        }
        s[n + 1] = 0;
        cout << (s + 1) << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}