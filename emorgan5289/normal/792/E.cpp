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
vector<T> divisors(T n) {
    vector<T> s, e;
    for (T i = 1; i <= (T)(sqrt(n)); i++)
        if (n%i == 0) {
            s.push_back(i);
            if (i*i != n) e.push_back(n/i);
        }
    for (int i = e.size()-1; i >= 0; i--)
        s.push_back(e[i]);
    return s;
}

const int N = 505, A = 1e9+5;
ll a[N];
set<ll> temp, q;
vector<ll> s, t;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            for (auto& x : divisors(a[i]))
                if (x > 1) temp.insert(x);
            for (ll k = 1; k < sqrt(a[i])+10; k++) {
                if (k > 1 && a[i]/k != a[i]/(k-1))
                    temp.insert(k);
                ll l = 2, r = a[i];
                while (l < r) {
                    ll m = (l+r)/2;
                    if (a[i]/m >= k)
                        l = m+1;
                    else
                        r = m;
                }
                if (a[i]/l != a[i]/(l-1))
                    temp.insert(l);
            }
            temp.insert(a[i]+1);
            for (auto& x : temp)
                s.pb(x);
        } else {
            if (q.count(a[i])) continue;
            t.clear();
            for (auto& x : s) {
                if (a[i]/x != a[i]/(x-1) || a[i]%x == 0 || x == a[i]+1)
                    t.pb(x);
            }
            swap(s, t);
        }
        q.insert(a[i]);
    }
    ll k = 0, ans = 0;
    for (auto& x : s)
        k = max(k, x);
    for (int i = 0; i < n; i++)
        ans += (a[i]/k + (a[i]%k != 0 ? 1 : 0));
    cout << ans << "\n";
}