#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, p, x, a[400105];
map<int, int> mp2, mp;
vector<int> ans;

inline int delta(int x, int inc) {
    if (!inc)
        return 0;
    if (mp2[x] == mp[x]) {
        mp[x] += inc;
        return -1;
    }
    mp[x] += inc;
    return (mp2[x] == mp[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int sz = 0;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        sz += !(mp2[x]++);
    }

    for (int i = 0; i < p; ++i) {
        ll L = i, R = i + (m - 1) * 1ll * p;
        if (R >= n)
            break;
        mp.clear();
        int eq = 0;
        for (int j = L; j <= R; j += p)
            eq += delta(a[j], 1);
        while (R < n) {
            if (eq == sz)
                ans.push_back(L);
            eq += delta(a[L], -1);
            L += p;
            R += p;
            if (R >= n)
                break;
            eq += delta(a[R], 1);
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << " ";
    cout << endl;

    return 0;
}