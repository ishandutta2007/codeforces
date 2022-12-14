#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n * 2);
    iota(a.begin(), a.end(), 1);
    for (int i = 0; i < n * 2; i += 2) {
        if (k) {
            swap(a[i], a[i + 1]);
            k--;
        }
    }

    for (int x : a) cout << x << ' ';
}