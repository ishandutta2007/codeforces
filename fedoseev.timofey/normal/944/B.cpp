#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

typedef long long ll;

int cnt[3];

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    int mn = 1e9;
    int mx = -1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (mx == mn || mn + 1 == mx) {
        cout << n << endl;
        for (auto e : a) {
            cout << e << " ";
        }
        return 0;
    }
    int md = mx - 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) ++cnt[2];
        else if (a[i] == mn) ++cnt[0];
        else {
            ++cnt[1];
        }
    }
    int can1 = cnt[1] + cnt[2] + cnt[0] - 2 * min(cnt[2], cnt[0]);
    int can2 = cnt[0] + cnt[2] + cnt[1] % 2;
    if (can1 < can2) {
        cout << can1 << endl;
        int cur = min(cnt[2], cnt[0]);
        cnt[0] -= cur;
        cnt[2] -= cur;
        cnt[1] += 2 * cur;
        for (int i = 0; i < cnt[0]; ++i) {
            cout << mn << " ";
        }
        for (int i = 0; i < cnt[1]; ++i) {
            cout << md << " ";
        }
        for (int i = 0; i < cnt[2]; ++i) {
            cout << mx << " ";
        }
    }
    else {
        cout << can2 << endl;
        int cur = cnt[1] - cnt[1] % 2;
        cnt[0] += cur / 2;
        cnt[1] -= cur;
        cnt[2] += cur / 2;
        for (int i = 0; i < cnt[0]; ++i) {
            cout << mn << " ";
        }
        for (int i = 0; i < cnt[1]; ++i) {
            cout << md << " ";
        }
        for (int i = 0; i < cnt[2]; ++i) {
            cout << mx << " ";
        }
    }
}