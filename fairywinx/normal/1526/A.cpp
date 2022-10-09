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
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n / 2; ++i) {
        cout << a[i] << ' ' << a[i + n / 2] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}