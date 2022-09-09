#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) {
            cin >> ai;
            ai -= 1;
        }
        vector<int> d(n);
        for (int i = n - 1; i >= 0; i -= 1) {
            int j = find(a.begin(), a.end(), i) - a.begin();
            if (j != i) d[i] = j + 1;
            rotate(a.begin(), a.begin() + j + 1, a.end());
            a.pop_back();
        }
        for (int di : d) cout << di << " ";
        cout << "\n";
    }
    return 0;
}