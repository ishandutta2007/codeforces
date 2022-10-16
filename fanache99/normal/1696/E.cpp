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
const int MOD = 1e9 + 7;

int v[1 + MAXN];
int a[1000][1000];

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int factorial[1 + 4 * MAXN], inverse[1 + 4 * MAXN];

int RaiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void Precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = RaiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int Combinations(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> v[i];
    }
    while (n >= 0 && v[n] == 0) {
        n--;
    }
    if (n == -1) {
        cout << "0\n";
        return 0;
    }
    int ans = 0;
    Precompute(4 * MAXN);
    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < v[i]; j++) {
//            ans += Combinations(i + j - 1, i - 1);
//        }
        add(ans, Combinations(i + v[i], i + 1));
    }
//    for (int j = 0; j < v[1]; j++) {
//        a[1][j] = 1;
//        ans += 1;
//    }
//    for (int i = 2; i <= n; i++) {
//        a[i][0] = 1;
//        ans += 1;
//        for (int j = 1; j < v[i]; j++) {
//            a[i][j] = a[i - 1][j] + a[i][j - 1];
//            ans += a[i][j];
//        }
//    }
    cout << ans << "\n";
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < v[i]; j++) {
//            if (a[i][j] != Combinations(i + j - 1, j)) {
//                cout << i << " " << j << " " << a[i][j] << " " << Combinations(i + j - 1, i - 1);
//                assert(false);
//            }
//        }
//    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}