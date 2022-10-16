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

int a[1 + MAXN], b[1 + MAXN + 1], need[1 + MAXN];
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
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        b[n + 1] = 0;
        bool bad = false;
        for (int i = n, j = n; j >= 1; j--) {
            if (b[j] == b[j + 1]) {
                need[b[j]]++;
                continue;
            }
            while (a[i] != b[j] && need[a[i]] > 0) {
                need[a[i]]--;
                i--;
            }
            if (a[i] != b[j]) {
                bad = true;
            } else {
                i--;
            }
        }
        cout << (bad ? "NO" : "YES") << "\n";
        for (int i = 1; i <= n; i++) {
            where[i].clear();
            need[i] = 0;
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}