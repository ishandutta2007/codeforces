#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, ka, kb; cin >> n >> m >> ka >> kb;
    vector<int> a(ka), b(kb), d(m+n);
    for (auto& x : a) cin >> x, x--;
    for (auto& x : b) cin >> x, x--;
    while (a.size() < m-1) a.pb(0);
    while (b.size() < n-1) b.pb(n);
    if (a.size() > m-1 || b.size() > n-1)
        return cout << "No\n", 0;
    for (auto& x : a) d[x]++;
    for (auto& x : b) d[x]++;
    reverse(all(a)), reverse(all(b));
    multiset<int> s;
    vector<pair<int, int>> out;
    for (int i = 0; i < n+m; i++)
        if (d[i] == 0) s.insert(i);
    int l = n-1, r = n+m-1;
    for (int t = 0; t < n+m-2; t++) {
        int i = *s.begin(), j; s.erase(s.begin());
        if (i >= n)
            j = a.back(), a.pop_back();
        else
            j = b.back(), b.pop_back();
        debug(s, i, j, a, b);
        if (--d[j] == 0) s.insert(j);
        out.pb({i, j});
    }
    debug(s, out);
    out.pb({*s.begin(), n+m-1});
    cout << "Yes\n";
    for (auto& [i, j] : out)
        cout << i+1 << " " << j+1 << "\n";
}