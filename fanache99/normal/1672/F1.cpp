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

int a[1 + MAXN], b[1 + MAXN], ord[1 + MAXN];
vector<int> where[1 + MAXN];

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
            cin >> a[i];
            where[a[i]].push_back(i);
            ord[i] = i;
        }
        sort(ord + 1, ord + n + 1, [](int a, int b) {
            return where[a].size() < where[b].size();
        });
        int rounds = where[ord[n]].size();
        for (int step = 1; step <= rounds; step++) {
            vector<int> x;
            int i = n;
            while (i > 0 && !where[ord[i]].empty()) {
                x.push_back(ord[i]);
                i--;
            }
            for (int j = 0; j < x.size(); j++) {
                b[where[x[j]].back()] = x[(j + 1) % x.size()];
                where[x[j]].pop_back();
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << b[i] << " ";
            assert(where[i].empty());
        }
        cout << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}