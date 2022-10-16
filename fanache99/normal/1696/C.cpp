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

const int MAXN = 50000;

int a[1 + MAXN], b[1 + MAXN];

vector<pair<int, long long> > process(int v[], int n, int k) {
    vector<pair<int, long long> > vs;
    for (int i = 1; i <= n; i++) {
        int x = v[i], t = 1;
        while (x % k == 0) {
            x /= k;
            t *= k;
        }
        if (!vs.empty() && vs.back().first == x) {
            vs.back().second += t;
        } else {
            vs.push_back({x, t});
        }
    }
    return vs;
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
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        vector<pair<int, long long> > as = process(a, n, k), bs = process(b, m, k);
        if (as == bs) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}