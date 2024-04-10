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

ll a[255][255], p[255][255], q[255][255];

inline ll count(vector<ll>& s) {
    ll n = s.size();
    vector<ll> d1(n);
    for (ll i = 0, l = 0, r = -1; i < n; i++) {
        ll k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<ll> d2(n);
    for (ll i = 0, l = 0, r = -1; i < n; i++) {
        ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    ll out = 0;
    for (auto& x : d1) out += x;
    for (auto& x : d2) out += x;
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    srand(time(0));
    int n, m; fin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; fin >> c; a[i][j] = c-'a';
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            p[i][j] = (j == 0 ? 0 : p[i][j-1]) ^ (1ll<<a[i][j]);

    vector<ll> rnd(26);
    for (auto& x : rnd)
        for (int j = 0; j < 4; j++)
            x = rand()+RAND_MAX*x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            q[i][j] = (j == 0 ? 0 : q[i][j-1]) + rnd[a[i][j]];
            debug(i, j, q[i][j]);
        }

    ll out = 0;
    vector<ll> b;
    for (int l = 0; l < m; l++)
        for (int r = l; r < m; r++) {
            for (int i = 0; i < n; i++) {
                if (__builtin_popcount(p[i][r] ^ (l == 0 ? 0 : p[i][l-1])) <= 1) {
                    // debug(l, r, i, (l == 0 ? 0 : q[i][l-1]), q[i][r]);
                    b.push_back(q[i][r] - (l == 0 ? 0 : q[i][l-1]));
                } else {
                    out += count(b); b.clear();
                }
            }
            // debug(l, r, b);
            out += count(b); b.clear();
        }
    cout << out << "\n";
}