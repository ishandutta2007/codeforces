#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7, MOD = 1000 * 1000 * 1000 + 7, BASE = 129;
int h[N], pw[N], pref[N];
inline int mod(int n) { 
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    pw[0] = 1;
    for (int i = 1; i < N; ++i) pw[i] = mod(pw[i - 1] * BASE);
    int n; cin >> n;
    string ans;
    while (n--) {
        string s; cin >> s;
        for (int i = 0; i < s.size(); ++i) pref[i + 1] = mod(pref[i] * BASE + s[i]);
        for (int i = min(s.size(), ans.size()); ; --i) {
            if (mod(h[ans.size()] - h[ans.size() - i] * pw[i]) == pref[i]) {
                for (int j = i; j < s.size(); ++j) {
                    h[ans.size() + 1] = mod(h[ans.size()] * BASE + s[j]);
                    ans += s[j];
                }   
                break;
            }   
        }   
    }   
    cout << ans << '\n';
}