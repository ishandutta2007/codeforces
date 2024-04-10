#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& ai : a) cin >> ai;
    cout << accumulate(a.begin(), a.end(), 0);
    return 0;
}