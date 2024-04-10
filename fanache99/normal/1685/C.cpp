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

char s[1 + 2 * MAXN + 1];
int sum[1 + 2 * MAXN];

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
        cin >> n >> (s + 1);
        vector<vector<int>> where(n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
            if (sum[i] >= 0) {
                where[sum[i]].push_back(i);
            }
        }
        for (int i = 0; i <= n; i++) {
            reverse(where[i].begin(), where[i].end());
        }
        vector<pair<int, int>> sol;

        int p = 0, big = n;
        while (p <= 2 * n) {
            assert(sum[p] >= 0);
            int biggest = -1, pos;
            while (p <= 2 * n && sum[p] >= 0) {
                if (sum[p] > biggest) {
                    biggest = sum[p];
                    pos = p;
                }
                p++;
            }
            if (p <= 2 * n) {
                assert(sum[p] < 0 && biggest != -1);
                while (true) {
                    if (where[big].empty()) {
                        big--;
                    } else if (where[big].back() <= p) {
                        where[big].pop_back();
                    } else {
                        break;
                    }
                }
                assert(big >= 0 && !where[big].empty() && where[big].back() > p);
                int nxt = max(0, big - biggest);
                while (where[nxt].size() > 1) {
                    where[nxt].pop_back();
                }
                assert(where[nxt].size() == 1);
                sol.push_back({pos + 1, where[nxt].back()});
                p = where[nxt].back() + 1;
            }
        }

        cout << sol.size() << "\n";
        for (auto it : sol) {
            cout << it.first << " " << it.second << "\n";
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}