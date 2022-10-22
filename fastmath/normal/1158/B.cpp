#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(string s, int len) {
    map <string, int> d;
    for (int i = 0; i + len - 1 < (int)s.size(); ++i) {
        ++d[s.substr(i, len)];
    }   
    for (auto e : d) if (e.second == 1) return 1;
    return 0;
}
int get(string s) {
    for (int len = 1; ; ++len) {
        if (check(s, len)) {
            return len;
        }   
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    if (n == k) {
        for (int i = 0; i < n; ++i) cout << '0';
        cout << '\n';
        exit(0);
    }   
    int p = (n - k) >> 1;
    ++p;
    string ans;
    for (int i = 1; i <= n; ++i) {
        ans += '0' + (bool)(i % p);
    }   
    cout << ans << '\n';
}