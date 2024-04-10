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

vector <int> p, sz;

map <int, int> cnt;

int get(int a) {
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        --cnt[sz[a]];
        if (cnt[sz[a]] == 0) {
            cnt.erase(sz[a]);
        }
        --cnt[sz[b]];
        if (cnt[sz[b]] == 0) {
            cnt.erase(sz[b]);
        }
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        ++cnt[sz[a]];
    }
}

void make(int a) {
    p[a] = a;
    sz[a] = 1;
    ++cnt[1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    p.resize(n);
    sz.resize(n);
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <pair <int, int>> b(n);
    int ans = 1, res = -1;
    for (int i = 0; i < n; ++i) {
        res = max(res, a[i] + 1);
    }
    for (int i = 0; i < n; ++i) {
        b[i] = make_pair(a[i], i);
    }
    sort(b.begin(), b.end());
    for (int i = 1; i < n; ++i) {
        int j = b[i].first;
        int cur = b[i - 1].second;
        make(cur);
        if (cur != 0) {
            if (a[cur - 1] < j) {
                merge(cur, cur - 1);
            }
        }
        if (cur != n - 1) {
            if (a[cur + 1] < j) {
                merge(cur, cur + 1);
            }
        }
        if (cnt.size() == 1) {
            int k = b[i - 1].first + 1;
            if (cnt.begin() -> second > ans || (cnt.begin() -> second == ans && k < res)) {
                ans = cnt.begin() -> second;
                res = k;
            }
        }
    }
    cout << res << ' ';
}