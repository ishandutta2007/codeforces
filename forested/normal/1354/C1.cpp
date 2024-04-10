#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

#define PI acos(-1)

void solve() {
    int n;
    cin >> n;
    cout << fixed << setprecision(10) << 1 / tan(PI / n / 2) << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}