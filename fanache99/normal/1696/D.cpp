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

const int MAXN = 250000;

int v[1 + MAXN];
int stDesc[1 + MAXN], stInc[1 + MAXN], dp[1 + MAXN];

int binSearch(int v[], int n, int x) {
    int left = 1, right = n, ans = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] < x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return v[ans];
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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        int topDesc = 1, topInc = 1;
        stDesc[0] = stInc[0] = n + 1;
        stDesc[topDesc] = stInc[topInc] = n;
        dp[n] = 0;

        for (int i = n - 1; i >= 1; i--) {
            while (topDesc > 0 && v[i] > v[stDesc[topDesc]]) {
                topDesc--;
            }
            while (topInc > 0 && v[i] < v[stInc[topInc]]) {
                topInc--;
            }
            int nxt;
            if (stDesc[topDesc] > stInc[topInc]) {
                nxt = binSearch(stInc, topInc, stDesc[topDesc]);
            } else {
                nxt = binSearch(stDesc, topDesc, stInc[topInc]);
            }
            dp[i] = 1 + dp[nxt];
            topDesc++;
            stDesc[topDesc] = i;
            topInc++;
            stInc[topInc] = i;
        }

        cout << dp[1] << "\n";
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}