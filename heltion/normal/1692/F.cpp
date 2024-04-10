#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        map<int, int> count;
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            a %= 10;
            if (count[a] == 3) continue;
            count[a] += 1;
            v.push_back(a);
        }
        int ok = 0;
        for (int i = 0; i < v.size(); i += 1)
            for (int j = i + 1; j < v.size(); j += 1)
                for (int k = j + 1; k < v.size(); k += 1)
                    if ((v[i] + v[j] + v[k]) % 10 == 3)
                        ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
}