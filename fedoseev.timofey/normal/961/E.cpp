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

const int N = 2e5 + 7;

int t[4 * N];

void modify(int ind, int l, int r, int v) {
    if (ind < l || r < ind) return;
    if (l == r) {
        ++t[v];
    }
    else {
        int m = (l + r) >> 1;
        modify(ind, l, m, 2 * v + 1);
        modify(ind, m + 1, r, 2 * v + 2);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

int get(int ql, int qr, int l, int r, int v) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[v];
    int m = (l + r) >> 1;
    return get(ql, qr, l, m, 2 * v + 1) + get(ql, qr, m + 1, r, 2 * v + 2);
}

struct event {
    int x, a, type;
    event(int x, int a, int type) : x(x), a(a), type(type){}
    bool operator<(const event &other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return type < other.type;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = min(a[i], n);
        --a[i];
    }
    ll ans = 0;
    vector <event> events;
    for (int i = 0; i < n; ++i) {
        events.emplace_back(i, a[i], -1);
        events.emplace_back(a[i], i, 1);
    }
    sort(events.begin(), events.end());
    for (auto e : events) {
        if (e.type == -1) {
            modify(e.a, 0, N - 1, 0);
        }
        else {
            ans += get(e.a, N - 1, 0, N - 1, 0);
            if (a[e.a] >= e.a) --ans;
        }
    }
    ans /= 2;
    cout << ans << "\n";
}