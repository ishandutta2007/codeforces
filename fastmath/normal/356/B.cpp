#include<bits/stdc++.h>
using namespace std;
#define int long long
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}   
const int C = 26;
int a[C], b[C];
int solve(string s, string t) {
    int d = __gcd(s.size(), t.size());
    int ans = lcm((int)s.size(), (int)t.size());
    for (int r = 0; r < d; ++r) {
        for (int c = 0; c < C; ++c) {
            a[c] = b[c] = 0;
        }   
        for (int i = r; i < (int)s.size(); i += d) {
            ++a[s[i] - 'a'];
        }   
        for (int i = r; i < (int)t.size(); i += d) {
            ++b[t[i] - 'a'];
        }   
        for (int c = 0; c < C; ++c) {
            ans -= a[c] * b[c];
        }
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int len = n * (int)s.size();
    cout << solve(s, t) * (len / lcm((int)s.size(), (int)t.size())) << '\n';
}