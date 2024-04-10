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

multiset<array<ll, 3>> a;
multiset<array<ll, 2>> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string t; cin >> t; t += '0';
    ll l = 0, ans = 0;
    for (int i = 0; i <= n; i++)
        if (t[i] == '0') {
            if (l != i) {
                for (int j = 1; j <= i-l-2; j++)
                    ans += j*(i-l-2-j+1);
                for (int j = l; j < i; j++)
                    a.insert({-(j-l+1), l, j});
                for (int j = l+1; j < i; j++)
                    a.insert({-(i-j), j, i-1});
            }
            l = i+1;
        }
    s.insert({-1, -1});
    s.insert({n, n});
    for (auto [p, x, y] : a) {
        p = -p;
        auto it = s.insert({x, y});
        auto it1 = it, it2 = it;
        it1--, it2++;
        ans += p*(x-(*it1)[0])*((*it2)[1]-y);
    }
    cout << ans << "\n";
}