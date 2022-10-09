#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <numeric>
#include <vector>
#include <array>

#define all(a) a.begin(), a.end()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // SOLVE
    int n;
    cin >> n;
    long long last = 0;
    long long sum = 0;
    long long sum1 = 0;
    vector<int> u(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i)
            ++u[j];
    }
    vector<int> val(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i > 2)
            sum = (sum + val[i - 2]) % mod;
        last = last + sum  + u[i];
        last = (last + mod) % mod;
        val[i] = last;
    }
    cout << last << '\n';
}