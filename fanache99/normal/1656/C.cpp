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
    auto start = high_resolution_clock::now();


    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        bool haveOne = false;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            haveOne |= (v[i] == 1);
        }
        sort(v + 1, v + n + 1);
        bool consecutive = false;
        for (int i = 1; i < n; i++) {
            consecutive |= (v[i] + 1 == v[i + 1]);
        }
        if (haveOne && consecutive) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}