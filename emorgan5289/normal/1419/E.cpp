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

// returns a sorted list of all unique prime factors of n in O(sqrt(n)) time.
template<typename T>
vector<T> uniqueprimefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            while (n%i == 0) n /= i;
        }
    }
    return out;
}

// returns a sorted list of all divisors of n in O(sqrt(n)) time.
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        auto p = uniqueprimefactors(n);
        set<ll> d;
        for (auto& x : divisors(n))
            if (x != 1) d.insert(x);
        if (p.size() == 1) {
            for (auto& x : d) cout << x << " ";
            cout << "\n0\n";
        } else if (d.size() == 3) {
            for (auto& x : d) cout << x << " ";
            cout << "\n1\n";
        } else if (p.size() == 2) {
            cout << p[0] << " ";
            for (auto& x : d)
                if (x%p[0] == 0 && x != p[0]*p[1] && x != n && x != p[0] && x != p[1])
                    cout << x << " ";
            cout << p[0]*p[1] << " ";
            for (auto& x : d)
                if (x%p[0] != 0 && x != p[0]*p[1] && x != n && x != p[0] && x != p[1])
                    cout << x << " ";
            cout << p[1] << " ";
            cout << n << " ";
            cout << "\n0\n";
        } else {
            cout << p[0]*p[p.size()-1] << " ";
            d.erase(d.find(p[0]*p[p.size()-1]));
            map<ll, vector<ll>> b;
            for (auto& x : d)
                for (auto& y : p)
                    if (x%y == 0) {
                        b[y].pb(x); break;
                    }
            for (ll i = 0; i < p.size(); i++) {
                for (auto& x : b[p[i]])
                    if (x != p[i]*p[(i+1)%p.size()] && d.count(x)) {
                        cout << x << " ";
                        d.erase(d.find(x));
                    }
                if (i != p.size()-1) {
                    cout << p[i]*p[(i+1)%p.size()] << " ";
                    d.erase(d.find(p[i]*p[(i+1)%p.size()]));
                }
            }
            cout << "\n0\n";
        }
    }
}