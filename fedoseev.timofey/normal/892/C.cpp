#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int gm = a[0];
    for (int i = 1; i < n; ++i) gm = gcd(gm, a[i]);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) ++cnt;
    }
    if (cnt != 0) {
        cout << n - cnt << endl;
        return 0;
    }
    if (gm != 1) {
        cout << -1 << endl;
        return 0;
    }
    int best = 1e9;
    for (int i = 0; i < n; ++i) {
        int tmp = a[i];
        for (int j = i + 1; j < n; ++j) {
            tmp = gcd(tmp, a[j]);
            if (tmp == 1) {
                best = min(best, j - i - 1);
                break;
            }
        }
    }
    cout << n + best << endl;
}