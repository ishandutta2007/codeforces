#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b;
        cin >> a >> b;
        set<int> vk;
        for (int k = 0; k <= a + b; k += 1) {
            int m = (a + b + 1) / 2, n = (a + b) / 2;
            if (n >= k and m >= a - k and k <= a)
                vk.insert(k + m - (a - k));
        }
        swap(a, b);
        for (int k = 0; k <= a + b; k += 1) {
            int m = (a + b + 1) / 2, n = (a + b) / 2;
            if (n >= k and m >= a - k and k <= a)
                vk.insert(k + m - a + k);
        }
        cout << vk.size() << "\n";
        for (int k : vk) cout << k << " ";
        cout << "\n";
    }
    return 0;
}