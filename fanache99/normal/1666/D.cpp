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

const int SIGMA = 26;

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        string s, t;
        cin >> s >> t;
        vector<vector<int>> pos(SIGMA);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'A'].push_back(i);
        }
        vector<int> f(SIGMA);
        for (int i = 0; i < t.size(); i++) {
            f[t[i] - 'A']++;
        }
        bool bad = false;
        vector<pair<int, char>> sol;
        for (int i = 0; i < SIGMA; i++) {
            if (pos[i].size() < f[i]) {
                bad = true;
                continue;
            }
            for (int j = 0; j < f[i]; j++) {
                sol.push_back({pos[i].back(), i + 'A'});
                pos[i].pop_back();
            }
        }
        if (!bad) {
            assert(sol.size() == t.size());
            sort(sol.begin(), sol.end());
            for (int i = 0; i < t.size(); i++) {
                if (t[i] != sol[i].second) {
                    bad = true;
                }
            }
        }
        cout << (bad ? "NO" : "YES") << "\n";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}