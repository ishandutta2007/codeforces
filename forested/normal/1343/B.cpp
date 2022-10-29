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
    if (n % 4 == 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        REP(i, n / 2) cout << 2 * (i + 1) << " ";
        REP(i, n / 2 - 1) cout << 2 * i + 1 << " ";
        cout << 2 * (n / 2 - 1) + 1 + n / 2 << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    REP(_, t) solve();
}