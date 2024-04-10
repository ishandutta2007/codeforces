#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int mod = 998244353;

unordered_map<ll, pair<ll, int>> mp;
vector<ll> divrs;
vector<int> cnts;

inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

void calc(ll x, vector<int> v) {
    if (mp.find(x) == mp.end()) {
        auto& rf = mp[x];
        rf = {9e18, -1};
        for (int i = 0; i < cnts.size(); ++i) {
            if (v[i] == 0) continue;
            --v[i];
            calc(x / divrs[i], v);
            ++v[i];
            ll addon = 1;
            for (int j = 0; j < cnts.size(); ++j) {
                if (i != j)
                    addon *= v[j] + 1;
            }
            pair<ll, int> qqq = mp[x / divrs[i]];
            qqq.first += addon;
            if (qqq.first == rf.first)
                add(rf.second, qqq.second);
            else if (qqq.first < rf.first)
                rf = qqq;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    mp[1] = {0, 1};

    ll x, a;
    cin >> x;
    a = x;

    for (int i = 2; (ll)i * i <= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            ++cnt;
        }
        if (cnt > 0) {
            divrs.push_back(i);
            cnts.push_back(cnt);
        }
    }
    if (x > 1) {
        divrs.push_back(x);
        cnts.push_back(1);
    }

    calc(a, cnts);

    int q;
    cin >> q;
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll g = __gcd(a, b);
        a /= g;
        b /= g;
        int ans = mp[a].second * (ll)mp[b].second % mod;
        cout << ans << "\n";
        /*
        int sum = 0;
        for (ll d : divrs) {
            int cur = 0;
            while (a % d == 0) {
                a /= d;
                ++cur;
            }
            while (b % d == 0) {
                b /= d;
                --cur;
            }
            cur = abs(cur);
            ans = ans * invfact[cur] % mod;
            sum += cur;
        }
        ans *= fact[sum];
        cout << ans << "\n";*/
    }
}