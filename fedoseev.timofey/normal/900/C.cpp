#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> need(n + 1);
    set <int> f;
    stack <int> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        while (!p.empty() && p.top() < a[i]) p.pop();
        if (p.empty()) need[a[i]] = -1;
        p.push(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        f.insert(a[i]);
        auto it = f.upper_bound(a[i]);
        if (it == --f.end()) {
            ++need[*it];
        }
    }
    int l = 1;
    int cur = need[1];
    for (int i = 2; i <= n; ++i) {
        if (need[i] > cur) {
            l = i;
            cur = need[i];
        }
    }
    cout << l << endl;
}