// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <array>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

long long cnt(long long a, long long c) {
    return min(a % c, c - a % c);
}

void solve() {
    long long a, b;
    cin >> a >> b;
    long long c = abs(a - b);
    if (!c) {
        cout << "0 0\n";
    } else {
        cout << c << ' ' << min(cnt(a, c), cnt(b, c)) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}