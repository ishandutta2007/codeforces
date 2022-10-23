#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

struct S {
    vector<vector<int>> sp;
    vector<int> pw;
    S(vector<int> a) {
        int n = a.size();
        int k = 0;
        while ((1 << (k - 1)) < n)
            ++k;
        sp.resize(k, vector<int> (n));
        sp[0] = a;
        for (int j = 1; j < k; ++j) {
            for (int i = 0; i + (1 << (j - 1)) < n; ++i)
                sp[j][i] = __gcd(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
        }
        pw.resize(n + 1);
        for (int i = 2; i <= n; ++i)
            pw[i] = pw[i / 2] + 1;
    }
    int get(int l, int r) {
        // cout << l << ' ' << r << ' ' << sp[0].size() << '\n';
        int k = pw[r - l];
        return __gcd(sp[k][l], sp[k][r - (1 << k)]);
    }
};

struct dsu {
    vector<int> p;
    vector<pair<int, int>> A;
    dsu(int n) {
        p.resize(n);
        iota(all(p), 0);
        for (int i = 0; i < n; ++i)
            A.emplace_back(i, i);
    }
    int get(int a) {
        if (a == p[a])
            return a;
        return p[a] = get(p[a]);
    }
    void merge(int a, int b) {
        a = get(a), b = get(b);
        if (a == b)
            return;
        p[b] = a;
        A[a].first = min(A[a].first, A[b].first);
        A[a].second = max(A[a].second, A[b].second);
    }
};

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    S t(a);
    vector<pair<int, int>> c;
    for (int i = 0; i < n; ++i)
        c.emplace_back(a[i], i);
    sort(all(c));
    dsu d(n);
    long long ans = 0;
    for (auto i : c) {
        int L, R;
        int ind = i.second;
        if (i.first >= p)
            continue;
        {
            int l = ind, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (t.get(ind, mid + 1) >= i.first)
                    l = mid;
                else
                    r = mid;
            }
            R = l;
        }
        {
            int l = -1, r = ind;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (t.get(mid, ind + 1) >= i.first)
                    r = mid;
                else
                    l = mid;
            }
            // cout << "! " << t.get(0, ind) << '\n';
            L = r;
        }
        // cout << L << ' ' << R << ' ' << i.first << '\n';
        for (int j = ind; j <= R; j = d.A[d.get(j)].second + 1) {
            // cout << j << '\n';
            ans += i.first;
            d.merge(ind, j);
        }
        for (int j = ind; j >= L; j = d.A[d.get(j)].first - 1) {
            ans += i.first;
            d.merge(ind, j);
        }
        ans -= 2 * i.first;
    }
    for (int i = 0; i < n; i = d.A[d.get(i)].second + 1)
        ans += p;
    ans -= p;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}