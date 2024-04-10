#include <bits/stdc++.h>

using namespace std;

int get(int n, int k) {
    return (n + k - 1) / k;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << get(n * 2, k) + get(n * 5, k) + get(n * 8, k) << '\n';

    return 0;
}