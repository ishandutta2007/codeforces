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

const int MAXN = 18;

char s[1 << MAXN], t[(1 << MAXN) + 1];
vector<int> b[1 << MAXN];
pair<pair<int, int>, pair<int, int> > v[1 << MAXN];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();

    int n;
    cin >> n >> s;
    for (int i = 0; i < (1 << n); i++) {
        b[i].resize(1);
        b[i][0] = s[i] - 'a';
    }
    for (int bit = 0; bit < n; bit++) {
        int p = 0;
        for (int mask = 0; mask < (1 << (n - bit - 1)); mask++) {
            int b1 = (mask << (bit + 1)), b2 = ((mask << (bit + 1)) ^ (1 << bit));
            assert(b[b1].size() == (1 << bit) && b[b2].size() == (1 << bit));
            for (int sub = 0; sub < (1 << bit); sub++) {
                v[p] = {{b[b1][sub], b[b2][sub]}, {sub, mask}};
                p++;
                v[p] = {{b[b2][sub], b[b1][sub]}, {sub ^ (1 << bit), mask}};
                p++;
            }
            b[b2].clear();
            b[b1].resize(1 << (bit + 1));
        }
        assert(p == (1 << n));
        sort(v, v + (1 << n));
        int m = 0;
        for (int i = 0; i < (1 << n); i++) {
            if (i > 0 && v[i].first != v[i - 1].first) {
                m++;
            }
            int sub = v[i].second.first, mask = v[i].second.second;
            int b0 = (mask << (bit + 1));
            b[b0][sub] = m;
        }
    }

    assert(b[0].size() == (1 << n));
    int x = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (b[0][i] < b[0][x]) {
            x = i;
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        t[i] = s[i ^ x];
    }
    t[1 << n] = 0;
    cout << t << "\n";

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}