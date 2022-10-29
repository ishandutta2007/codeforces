#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

void solve() {
    int n;
    cin >> n;
    for (int k = 2; k <= 30; ++k) {
        if (n % ((1 << k) - 1) == 0) {
            cout << n / ((1 << k) - 1) << "\n";
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    REP(_, t) solve();
}