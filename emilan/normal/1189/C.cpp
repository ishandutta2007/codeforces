#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> p(n + 1);
    partial_sum(a.begin(), a.end(), p.begin() + 1);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        cout << (p[r] - p[--l]) / 10 << '\n';
    }
}