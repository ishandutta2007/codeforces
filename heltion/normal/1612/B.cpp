#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v;
        v.push_back(a);
        for (int i = n; i >= 1; i -= 1)
            if (i != a and i != b)
                v.push_back(i);
        v.push_back(b);
        if (*min_element(v.begin(), v.begin() + n / 2) == a and *max_element(v.begin() + n / 2, v.end()) == b)
            for (int x : v) cout << x << " ";
        else cout << -1;
        cout << "\n";
    }
    return 0;
}