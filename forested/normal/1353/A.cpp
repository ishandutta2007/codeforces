#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1) cout << 0 << "\n";
    else if (n == 2) cout << m << "\n";
    else cout << m * 2 << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}