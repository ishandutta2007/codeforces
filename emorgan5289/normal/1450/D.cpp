#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
vector<T> fixedrangermq(vector<T>& A, int width) {

    int n = A.size();
    vector<T> prefix(n, 0), suffix(n, 0);
    for (int i = 0; i < n; i++) {
        prefix[i] = A[i];
        if (i%width != 0)
            prefix[i] = min(prefix[i], prefix[i-1]);
    }
    for (int i = n-1; i >= 0; i--) {
        suffix[i] = A[i];
        if (i%width != width-1 && i != n-1)
            suffix[i] = min(suffix[i], suffix[i+1]);
    }
    vector<T> out(n-width+1);
    for (int i = 0; i <= n-width; i++)
        out[i] = min(suffix[i], prefix[i+width-1]);
    return out;
}

template<typename T>
struct rmq {

    vector<vector<T>> tree;

    // runs in O(nlogn).
    rmq(vector<T>& data) {
        int n = data.size();
        int h = n == 0 ? 0 : ceil(log2(n));
        tree.assign(h+1, vector<T>(n));
        tree[0] = data;
        for (int i = 1; i <= h; i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                tree[i][j] = min(tree[i-1][j], tree[i-1][j+(1<<(i-1))]);
    }

    // returns the minimum of the array on the interval [a..b] in O(1) time.
    T query(int a, int b) {
        int n = floor(log2(b-a+1));
        return min(tree[n][a], tree[n][b-(1<<n)+1]);
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (auto& x : a) cin >> x;
        auto qry = rmq(a);
        map<int, int> m;
        vector<int> ans(n, 0);
        bool v = 1;
        for (auto& x : a) {
            m[x]++;
            v = v && (m[x] <= 1);
        }
        if (v && *max_element(all(a)) == n)
            ans[0] = 1;
        int l = 0, r = n-1;
        while (l <= r) {
            int x = qry.query(l, r);
            if (x == n-(r-l))
                ans[r-l] = 1;
            if (m[x] == 1 && x == n-(r-l)) {
                m[x]--;
                if (a[l] == x)
                    l++;
                else if (a[r] == x)
                    r--;
                else
                    break;
            } else {
                break;
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << "\n";
    }
}