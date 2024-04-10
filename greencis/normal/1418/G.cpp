#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int mod = 998244353;
const ull seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 gen(seed);

ull ha[500500], hb[500500];
ull h[500500];
vector<int> v[500500];
unordered_map<ull, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ha[i] = gen();
        hb[i] = gen();
    }

    ll ans = 0;
    int ptr = 0;
    ++mp[0];
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        v[x].push_back(i);
        h[i] = (v[x].size() % 3 == 1 ? ha[x] : v[x].size() % 3 == 2 ? hb[x] : ha[x] ^ hb[x]);
        h[i] ^= h[i - 1];
        if (v[x].size() > 3) {
            int pos = v[x][v[x].size() - 4];
            while (ptr < pos) {
                --mp[h[ptr]];
                ++ptr;
            }
        }
        ans += mp[h[i]]++;
    }
    cout << ans;
}