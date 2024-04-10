#include <bits/stdc++.h>
using namespace std;

vector<int> diag, H, V;

int main() {
    auto ask = [&](int x, int y) {
        cout << "0 " << x << " " << y << endl;
        int z; cin >> z; return z;
    };
    function<void(int, int)> solve = [&](int l, int r) {
        if (l > r) return;
        int mid = (l + r) / 2, d = ask(mid, mid);
        if (!d) diag.push_back(mid), d++;
        solve(l, mid - d), solve(mid + d, r);
    };
    solve(-1e8, 1e8), sort(diag.begin(), diag.end());
    int z = 0;
    while (binary_search(diag.begin(), diag.end(), z)) z++;
    for (int x : diag) {
        if (!ask(x, z)) H.push_back(x);
        if (!ask(z, x)) V.push_back(x);
    }
    cout << "1 " << H.size() << " " << V.size() << endl;
    for (int x : H) cout << x << " "; cout << endl;
    for (int x : V) cout << x << " "; cout << endl;
    return 0;
}