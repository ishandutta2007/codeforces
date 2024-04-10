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

const int MAXN = 500000;
const int INF = 1e9;

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
        long long sum = 0, ans;
        map<long long, int> equal, pos, neg;
        equal[0] = pos[0] = neg[0];
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i];
            int best = -INF;
            if (equal.count(sum) != 0) {
                best = max(best, equal[sum]);
            }

            {
                auto it = pos.lower_bound(sum);
                if (it != pos.begin()) {
                    it = prev(it);
                    assert(it->first < sum);
                    best = max(best, i + it->second);
                }
            }

            {
                auto it = neg.lower_bound(sum + 1);
                if (it != neg.end()) {
                    assert(it->first > sum);
                    best = max(best, -i + it->second);
                }
            }

            ans = best;

            {
                long long c = best - i;
                if (pos.count(sum) == 0 || pos[sum] < c) {
                    auto it = pos.lower_bound(sum);
                    if (it == pos.begin() || prev(it)->second < c) {
                        pos[sum] = c;
                        while (true) {
                            it = pos.upper_bound(sum);
                            if (it == pos.end() || it->second > c) {
                                break;
                            }
                            pos.erase(it);
                        }
                    }
                }
            }

            {
                long long c = best + i;
                if (neg.count(sum) == 0 || neg[sum] < c) {
                    auto it = neg.upper_bound(sum);
                    if (it == neg.end() || it->second < c) {
                        neg[sum] = c;
                        while (true) {
                            it = neg.lower_bound(sum);
                            if (it == neg.begin() || prev(it)->second > c) {
                                break;
                            }
                            neg.erase(prev(it));
                        }
                    }
                }
            }

            if (equal.count(sum) == 0) {
                equal[sum] = best;
            } else {
                equal[sum] = max(equal[sum], best);
            }
        }
        cout << ans << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}