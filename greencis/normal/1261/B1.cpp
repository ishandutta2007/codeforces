#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int t[200200];

inline int get(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        ans += t[x];
    return ans;
}

inline void upd(int x, int val) {
    for (; x < 200200; x |= x + 1)
        t[x] += val;
}

bool comp(const pair<pii, pii>& a, const pair<pii, pii>& b) {
    return a.second.first < b.second.first;
}

int a[200200];

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.emplace_back(a[i], -i);
    }
    sort(all(v), greater<>());

    vector<pair<pii, pii>> queries;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        queries.emplace_back(make_pair(x, y), make_pair(i, -1));
    }
    sort(all(queries));

    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        v[i].second *= -1;
        upd(v[i].second, 1);
        while (ptr < m && queries[ptr].first.first == i + 1) {
            int L = 0, R = n - 1;
            int need_pos = queries[ptr].first.second;
            while (L < R) {
                int mid = (L + R) >> 1;
                if (get(mid) >= need_pos)
                    R = mid;
                else
                    L = mid + 1;
            }
            queries[ptr++].second.second = a[L];
        }
    }

    sort(all(queries), comp);
    for (int i = 0; i < m; ++i)
        cout << queries[i].second.second << "\n";
}