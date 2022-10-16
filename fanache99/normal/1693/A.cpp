#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;

int v[1 + MAXN];

int main() {
    // ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        long long sum = 0, first0 = 0;
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            sum += v[i];
            if (sum < 0) {
                bad = true;
            }
            if (sum == 0 && first0 == 0) {
                first0 = i;
            }
        }
        if (sum != 0) {
            bad = true;
        }
        for (int j = first0 + 1; j <= n; j++) {
            if (v[j] != 0) {
                bad = true;
            }
        }
        cout << (bad ? "No" : "Yes") << "\n";
    }
    return 0;
}