#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    vector<ll> fact(21, 1);
    for (int i = 2; i < 21; i++)
        fact[i] = fact[i-1]*i;
    debug(fact);
    while (t--) {
        ll k; fin >> k;
        vector<ll> a;
        for (ll i = 2; k > 0; i++) {
            a.push_back(k%i); k /= i;
        }
        sort(all(a));
        debug(a);
        vector<ll> count(50, 0);
        for (ll x : a) count[x]++;
        ll out = 0, r, seen;
        for (ll e = a.size()+3; e > 0; e--) {
            if (count[e] == 0) continue;
            r = 1; seen = 0;
            count[e]--;
            debug(e);
            for (ll x = a.size()+3; x >= 0; x--) {
                if (count[x] == 0) continue;
                r *= fact[a.size()-max(1ll, x)-seen] / fact[count[x]] / fact[a.size()-max(1ll, x)-seen-count[x]];
                debug(x, r);
                seen += count[x];
            }
            count[e]++;
            out += r;
        }
        cout << out-1 << " ";
        // no 0 at end
        // a[i] <= i+2
    }
}