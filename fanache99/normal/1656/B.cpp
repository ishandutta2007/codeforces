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
        long long k;
        cin >> n >> k;
        map<long long, int> f;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            f[v[i]]++;
        }
        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (f[v[i] - k] > 0) {
                found = true;
            }
        }
        cout << (found ? "YES" : "NO") << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}