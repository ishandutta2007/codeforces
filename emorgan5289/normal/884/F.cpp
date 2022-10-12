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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n), f(26);
    vector<array<int, 3>> p;
    int r = 0;
    for (auto& x : a)
        cin >> x, r += x;
    for (int i = 0; i < n/2; i++) {
        if (s[i] == s[n-1-i])
            f[s[i]-'a']++, r -= min(a[i], a[n-1-i]);
        else
            p.pb({min(a[i], a[n-1-i]), s[i]-'a', s[n-1-i]-'a'});
    }
    sort(all(p));
    int k = 2**max_element(all(f))-accumulate(all(f), 0);
    int b = max_element(all(f))-f.begin();
    for (auto& [c, x, y] : p) {
        if (k <= 0) break;
        if (x != b && y != b)
            k--, r -= c;
    }
    cout << r << "\n";
}