#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int balance = 0;
    vector <int> suff(n + 1);
    suff[n] = 0;
    int s = 0;
    int min_s = 0;
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = max(suff[i + 1] + a[i], a[i]);
        suff[i] = max(suff[i], 0);
    }
    int ans = 0;
    balance = 0;
    for (int i = 0; i < n; ++i) {
        if (balance > d) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] != 0) balance += a[i];
        else {
            if (balance < 0) {
                int add = min(d - balance, d - suff[i] - balance);
                ++ans;
                if (balance + add < 0) {
                    cout << -1 << endl;
                    return 0;
                }
                balance += add;
            }
        }
    }
    if (balance > d) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}