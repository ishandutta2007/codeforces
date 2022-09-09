#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> c(26);
        for (char ch : s) c[ch - 'a'] += 1;
        int e = 0;
        for (int ci : c)
            e += ci / 2;
        for (int i = n / k; i >= 1; i -= 1)
            if (i / 2 * k <= e) {
                cout << i << "\n";
                break;
            }
    }
}