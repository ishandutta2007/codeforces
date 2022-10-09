#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <assert.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 111; ++i) {
        if (n >= i * 11 && (n - i * 11) % 111 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}