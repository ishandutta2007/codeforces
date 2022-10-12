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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, w; cin >> n >> w;
    deque<ll> s;
    vector<tuple<int, ll, bool>> a;
    vector<ll> p(w+1);
    while (n--) {
        int l; cin >> l;
        vector<ll> b(l); for (auto& x : b) cin >> x;
        a.clear();
        for (int i = 0; i < min(l, w-l+1); i++) {
            a.pb({i, b[i], 1});
        }
        for (int i = w-l+1; i < w+1; i++) {
            a.pb({i, b[i-w+l-1], 0});
            if (i < l)
                a.pb({i, b[i], 1});
        }
        int pi = 0;
        for (auto& [i, x, t] : a) {
            if (s.size() > 0) {
                ll k = s.front();
                int x1 = pi, x2 = i;
                if (k < 0) {
                    x1 = max(x1, w-l);
                    x2 = min(x2, l);
                    x2 = max(x1, x2);
                }
                p[x1] += k;
                p[x2] -= k;
            }
            pi = i;
            if (t) {
                while (s.size() > 0 && x > s.back())
                    s.pop_back();
                s.push_back(x);
            } else
                if (s.front() == x)
                    s.pop_front();
        }
    }
    ll x = 0;
    for (int i = 0; i < w; i++) {
        x += p[i]; cout << x << " ";
    }
    cout << "\n";
}