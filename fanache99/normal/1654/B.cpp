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
const int SIGMA = 26;

char s[1 + MAXN + 1];

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();



    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        vector<int> f(SIGMA, 0);
        for (int i = 1; i <= n; i++) {
            f[s[i] - 'a']++;
        }
        int p = 1;
        while (f[s[p]  - 'a'] > 1) {
            f[s[p] - 'a']--;
            p++;
        }
        cout << (s + p) << "\n";
    }



    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}