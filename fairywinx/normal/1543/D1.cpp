// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <array>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int val = 0;
    for (int i = 0; i < n; ++i) {
        cout << (val ^ i) << endl;
        int res;
        cin >> res;
        if (res == 1) {
            return;
        } else {
            val = i;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}