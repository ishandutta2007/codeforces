#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 500005;
ll a[N];
map<int, ll> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], m[i] = a[i];
    m[-inf] = m[inf] = 0;
    vector<int> o(n); iota(all(o), 0);
    sort(all(o), [&](int i, int j){return a[i] < a[j];});
    ll out = 0;
    for (auto& i : o) {
        ll l = (++m.find(i))->second;
        ll r = (--m.find(i))->second;
        if (a[i] <= l && a[i] <= r) {
            debug(i);
            out += min(l, r);
            m.erase(m.find(i));
        }
    }
    for (auto& [i, x] : m)
        out += x;
    reverse(all(o));
    int c = 0;
    for (auto& i : o) {
        if (c == 2) break;
        if (m.find(i) != m.end())
            c++, out -= a[i];
    }
    cout << out << "\n";
}