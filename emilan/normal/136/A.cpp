#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> out(n);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;

        out[j - 1] = i;
    }

    for (auto& i : out)
        cout << i + 1 << ' ';

    return 0;
}