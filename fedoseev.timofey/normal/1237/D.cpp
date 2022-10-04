#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;

struct SegmentTree {
    int n;
    vector <int> t;
 
    void build(const vector <int> &a) {
        for (int i = 0; i < n; ++i) {
            t[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = min(t[i << 1], t[i << 1 | 1]);
        }
    }
 
    void modify(int x, int val) {
        for (t[x += n] = val; x > 1; x >>= 1) {
            t[x >> 1] = min(t[x], t[x ^ 1]);
        }
    }
 
    int get(int l, int r) {
        ++r;
        int res = Inf;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, t[l++]);
            if (r & 1) res = min(res, t[--r]);
        }
        return res;
    }
 
    SegmentTree(const vector <int> &a) {
        n = a.size();
        t.resize(2 * n, Inf);
        build(a);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> id;
    for (int i = 0; i < n; ++i) id.push_back(i);
    sort(id.begin(), id.end(), [&] (int i, int j) {
        return a[i] > a[j];
    });
    vector <int> b = a;
    for (int i = 0; i < n; ++i) b.push_back(a[i]);
    vector <int> st;
    vector <int> nxt(2 * n);
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!st.empty() && b[st.back()] <= b[i]) st.pop_back();
        if (st.empty()) nxt[i] = -1;
        else nxt[i] = st.back();
        st.push_back(i);
    }
    SegmentTree t(b);
    vector <int> ans(n, -1);
    for (int i : id) {
        int j = nxt[i];
        if (j == -1) {
            int need = (a[i] - 1) / 2;
            if (t.get(i, 2 * n - 1) > need) {
                ans[i] = -1;
                continue;
            }
            int r = 2 * n - 1, l = i;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (t.get(i, m) <= need) r = m;
                else l = m;
            }
            ans[i] = r - i;
            continue;
        }
        int need = (a[i] - 1) / 2;
        if (t.get(i, j) > need) {
            if (ans[j % n] == -1) ans[i] = -1;
            else ans[i] = ans[j % n] + j - i;
        } else {
            int r = j, l = i;
            while (r - l > 1) {
                int m = (l + r) >> 1;
                if (t.get(i, m) <= need) r = m;
                else l = m;
            }
            ans[i] = r - i;
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}