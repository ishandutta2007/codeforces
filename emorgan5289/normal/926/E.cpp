#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

template<typename T>
T inc(T x) { return ++x; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    list<ll> a(n);
    for (auto& x : a)
        cin >> x;
    auto it = a.begin();
    while (inc(it) != a.end()) {
        if (*it == *inc(it)) {
            a.erase(inc(it));
            (*it)++;
            if (it != a.begin()) it--;
        } else {
            it++;
        }
    }
    cout << a.size() << "\n";
    for (auto& x : a)
        cout << x << " ";
    cout << "\n";
}