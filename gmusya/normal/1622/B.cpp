#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), s(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            char ch;
            cin >> ch;
            s[i] = ch - '0';
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
           if (s[i] != s[j]) {
               return s[i] < s[j];
           }
           return a[i] < a[j];
        });
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[p[i]] = i + 1;
        }
        for (int x : b) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}