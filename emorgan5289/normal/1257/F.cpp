#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

inline ll twist(ll h) {
    h += 0x9e3779b97f4a7c15;
    h = (h ^ (h >> 30)) * 0xbf58476d1ce4e5b9;
    h = (h ^ (h >> 27)) * 0x94d049bb133111eb;
    return h ^ (h >> 31);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    map<int, int> s;
    for (int x = 0; x < 1<<15; x++) {
        ll t = 0;
        for (int i = 0; i < n; i++)
            t = twist(t)^__builtin_popcount(((a[i]>>15)&((1<<15)-1))^x);
        s[t] = x;
    }
    int out = -1;
    for (int x = 0; x < 1<<15; x++) {
        int b[100], l = inf, r = -1;
        for (int i = 0; i < n; i++) {
            b[i] = __builtin_popcount((a[i]&((1<<15)-1))^x);
            l = min(l, b[i]); r = max(r, b[i]);
        }
        for (int j = r; j < l+16; j++) {
            ll t = 0;
            for (int i = 0; i < n; i++)
                t = twist(t)^(j-b[i]);
            if (s.find(t) != s.end()) {
                int guess = (s[t]<<15)|x;
                int check = __builtin_popcount(a[0]^guess);
                bool v = 1;
                for (int k = 1; k < n; k++)
                    v &= __builtin_popcount(a[k]^guess) == check;
                if (v) {
                    out = guess; goto done;
                }
            }
        }
    }
    done:;
    cout << out << "\n";
}