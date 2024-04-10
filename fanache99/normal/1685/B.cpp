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
        int a, b, c, d;
        cin >> a >> b >> c >> d >> (s + 1);
        int n = a + b + 2 * c + 2 * d;
        assert(n == strlen(s + 1));
        int cnt[2] = {0, 0};
        for (int i = 1; i <= n; i++) {
            cnt[s[i] - 'A']++;
        }
        int reqA = a + c + d, reqB = b + c + d;
        if (cnt[0] == reqA) {
            assert(cnt[1] == reqB);
            vector<int> ls[2][2];
            for (int i = 1; i <= n;) {
                int j = i;
                while (j < n && s[j + 1] != s[j]) {
                    j++;
                }
                if (j != i) {
                    ls[s[i] - 'A'][s[j] - 'A'].push_back(j - i + 1);
                }
                i = j + 1;
            }

            // Match AB with ABAB...AB
            sort(ls[0][1].begin(), ls[0][1].end());
            reverse(ls[0][1].begin(), ls[0][1].end());
            while (c > 0 && !ls[0][1].empty()) {
                c--;
                ls[0][1].back() -= 2;
                if (ls[0][1].back() == 0) {
                    ls[0][1].pop_back();
                }
            }

            // Match BA with BABA...BA
            sort(ls[1][0].begin(), ls[1][0].end());
            reverse(ls[1][0].begin(), ls[1][0].end());
            while (d > 0 && !ls[1][0].empty()) {
                d--;
                ls[1][0].back() -= 2;
                if (ls[1][0].back() == 0) {
                    ls[1][0].pop_back();
                }
            }

            int sum = 0;
            for (auto l : ls[0][0]) {
                sum += (l - 1) / 2;
            }
            for (auto l : ls[1][1]) {
                sum += (l - 1) / 2;
            }
            for (auto l : ls[0][1]) {
                sum += (l - 1) / 2;
            }
            for (auto l : ls[1][0]) {
                sum += (l - 1) / 2;
            }
            if (sum >= c + d) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}