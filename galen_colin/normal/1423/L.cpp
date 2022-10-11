#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

int main() {
    const int MAX = 1000;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, d;
    cin >> n >> s >> d;
    vector<bitset<MAX>> use(s);
    for (int i = 0; i < s; i++) { 
        int ci; 
        cin >> ci;
        for (int j = 0; j < ci; j++) {
            int x;
            cin >> x;
            use[i][x] = 1;
        }
    }
    const int INF = 100;
    int top = 2 * s / 3;
    unordered_map<bitset<MAX>, int> dp1;
    unordered_map<bitset<MAX>, int> dp2;
    for (int mask = 0; mask < (1 << top); mask++) {
        bitset<MAX> res;
        for (int j = 0; j < top; j++) {
            if ((1 << j) & mask) {
                res ^= use[j];
            }
        }
        if (dp1.find(res) == dp1.end()) {
            dp1[res] = __builtin_popcount(mask);
        } else {
            dp1[res] = min(dp1[res], __builtin_popcount(mask));
        }
    }
    int bot = s - top;
    for (int mask = 0; mask < (1 << bot); mask++) {
        bitset<MAX> res;
        for (int j = 0; j < bot; j++) {
            if ((1 << j) & mask) {
                res ^= use[j + top];
            }
        }
        if (dp2.find(res) == dp1.end()) {
            dp2[res] = __builtin_popcount(mask);
        } else {
            dp2[res] = min(dp2[res], __builtin_popcount(mask));
        }
    }
    while (d--) {
        bitset<MAX> q;
        int ti; 
        cin >> ti;
        for (int i = 0; i < ti; i++) {
            int x;
            cin >> x;
            q[x] = 1;
        }
        int ans = INF;
        for (auto& check : dp2) {
            bitset<MAX> store = check.first;
            store ^= q;
            if (dp1.find(store) != dp1.end()) {
                ans = min(ans, dp1[store] + check.second);
            }
        }
        if (ans == INF) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}