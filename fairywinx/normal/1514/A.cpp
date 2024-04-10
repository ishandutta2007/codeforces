#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>
#include <queue>
#include <set>
#include <random>
#include <ctime>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        bool sq = false;
        for (int j = 1; j * j <= a; ++j) {
            if (j * j == a)
                sq = true;
        }
        if (!sq)
            ans = true;
    }
    cout << (ans ? "YES\n" : "NO\n");
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}