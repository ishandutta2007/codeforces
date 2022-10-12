#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
    ll t; fin >> t;
    while (t--) {
        ll n, m ; fin >> n >> m;
        string s; fin >> s;
        vector<ll> p(m); for (auto& x : p) fin >> x;
        vector<ll> out(26, 0);
        sort(all(p));
        vector<ll> f(26, 0);
        int r = 0;
        // debug(t);
        p.push_back(n);
        for (auto& x : p) {
            while (r < x) {
                f[s[r++]-'a']++;
            }
            // debug(f);
            for (int i = 0; i < 26; i++)
                out[i] += f[i];
        }
        for (auto& x : out) cout << x << " ";
        cout << "\n";
    }
}