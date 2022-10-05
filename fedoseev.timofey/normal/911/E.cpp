#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < k; ++i) cin >> a[i];
    vector <bool> used(n + 1);
    for (int i = 0; i < k; ++i) used[a[i]] = true;
    stack <int> s;
    int need = 1;
    for (int i = 0; i < k; ++i) {
        s.push(a[i]);
        while (!s.empty() && s.top() == need) {
            ++need;
            s.pop();
        }
    }
    int cur = k;
    while (need != n + 1 && cur != n) {
        if (s.empty()) {
            int k = need;
            while (!used[k] && k != n) ++k;
            if (used[k]) --k;
            if (k == need - 1) {
                cout << -1 << endl;
                return 0;
            }
            for (int i = need; i <= k; ++i) used[i] = true;
            for (int i = 0; i <= k - need; ++i) {
                a[cur + i] = k - i;
            }
            cur += k - need + 1;
            need = k + 1;
        }
        int tmp = -1;
        if (!s.empty()) {
            tmp = s.top();
        }
        while (!s.empty() && tmp > need) {
            --tmp;
            if (used[tmp]) {
                cout << "-1" << endl;
                return 0;
            }
            s.push(tmp);
            a[cur] = tmp;
            ++cur;
        }
        while (!s.empty() && s.top() == need) {
            ++need;
            s.pop();
        }
    }
    if (!s.empty()) {
        cout << -1 << endl;
        return 0;
    }
    for (auto e : a) {
        cout << e << " ";
    }
}