#include "bits/stdc++.h"

using namespace std;

const int N = 200200;
const int mod = 998244353;

int n;
int a[N];
int b[N];
int f[N];

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        f[n + 1] = n + 1;
        for (int i = n; i >= 1; i--) {
            if (a[i] <= b[i - 1]) {
                f[i] = f[i + 1];
            } else {
                f[i] = i;
            }
        }
        for (int i = 1, j = 1; i <= n; i++) {
            while (a[i] > b[j]) {
                j += 1;
            }
            cout << b[j] - a[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << b[f[i + 1] - 1] - a[i] << " ";
        }
        cout << "\n";
    }
}