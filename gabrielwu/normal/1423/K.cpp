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
template<int SZ> struct Sieve {
    bitset<SZ> pri;
    vector<int> pr;
    Sieve() {
        pri.set();
        pri[0] = pri[1] = 0;
        for (int i = 4; i < SZ; i += 2) {
            pri[i] = 0;
        }
        for (int i = 3; i * i < SZ; i += 2) {
            if (pri[i]) {
                for (int j = i * i; j < SZ; j += 2 * i) {
                    pri[j] = 0;
                }
            }
        }
        for (int i = 0; i < SZ; i++) {
            if (pri[i]) {
                pr.push_back(i);
            }
        }
    }
};
int main() {
    const int MAX = 1e6 + 5;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Sieve<MAX> S;
    vector<int> pre(MAX);
    for (int i = 1; i < MAX; i++) {
        pre[i] = pre[i - 1] + S.pri[i];
    }
    auto get = [&](int l, int r) -> int {
        return pre[r] - pre[l - 1];
    };
    int tt;
    cin >> tt;
    while (tt--) {
        int n; 
        cin >> n;
        if (sqrt(n) == (int) sqrt(n)) {
            cout << get(ceil(sqrt(n + 1)), n) + 1 << '\n';
        } else {
            cout << get(ceil(sqrt(n)), n) + 1 << '\n';
        }        
    }
}