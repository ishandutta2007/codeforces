#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    long long n, m, x;
    cin >> n >> m >> x;
    int j = (x - 1 + n) % n;
    int i = (x - j - 1) / n;
    cout << j * m + i + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}