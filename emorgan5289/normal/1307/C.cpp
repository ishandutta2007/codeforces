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
    string s; fin >> s; ll n = s.size();
    vector<vector<ll>> suf(26, vector<ll>(n, 0));
    suf[s[n-1]-'a'][n-1] = 1;
    for (ll i = n-2; i >= 0; i--) {
        for (ll j = 0; j < 26; j++)
            suf[j][i] = suf[j][i+1];
        suf[s[i]-'a'][i]++;
    }
    vector<vector<ll>> p(26);
    for (ll i = 0; i < n; i++)
        p[s[i]-'a'].pb(i);
    ll out = 0;
    for (ll i = 0; i < 26; i++)
        for (ll j = 0; j < 26; j++) {
            ll q = 0;
            for (ll k : p[i])
                if (k < n-1) q += suf[j][k+1];
            out = max(out, q);
        }
    debug(p);
    for (auto& r : p) out = max(out, (ll)r.size());
    cout << out << "\n";
}