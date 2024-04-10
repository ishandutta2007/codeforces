#include "bits/stdc++.h"

using namespace std;

const int N = 200200;
const int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                zeros += 1;
            } else {
                v.push_back(x);
            }
        }
        for (int i = 0; i < min(3, zeros); i++) {
            v.push_back(0);
        }
        if (v.size() > 9) {
            cout << "NO\n";
            continue;
        }
        string res = "YES";
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                for (int h = j + 1; h < v.size(); h++) {
                    if (find(v.begin(), v.end(), v[i] + v[j] + v[h]) == v.end()) {
                        res = "NO";
                    }
                }
            }
        }
        cout << res << "\n";
    }
}