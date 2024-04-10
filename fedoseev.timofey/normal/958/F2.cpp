#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;
vector <int> a, b;

int sum = 0, n, m;

bool check(int x) {
    vector <int> c(m);
    int sz = x + sum;
    for (int i = 0; i < sz; ++i) {
        ++c[a[i]];
    }
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (c[i] < b[i]) ++cnt;
    }
    if (cnt == 0) return true;
    for (int i = sz; i < n; ++i) {
        int f = a[i];
        int s = a[i - sz];
        if (c[f] < b[f]) --cnt;
        if (c[s] < b[s]) --cnt;
        ++c[f];
        --c[s];
        if (c[f] < b[f]) ++cnt;
        if (c[s] < b[s]) ++cnt;
        if (cnt == 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    a.resize(n), b.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sum += b[i];
    }
    int l = -1, r = n + 1 - sum;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    if (r == n + 1 - sum) {
        cout << -1 << "\n";
    }
    else {
        cout << r << "\n";
    }
}