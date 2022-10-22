#include <bits/stdc++.h>

using namespace std;

#define int long long

map <int, int> prime(int n) {
    map <int, int> ans;
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            ans[d]++;
            n /= d;
        }   
    }   
    if (n != 1) ++ans[n];
    return ans;
}   

bool check(int n) {
    while (n % 2 == 0) n >>= 1;
    return n == 1;
}   

int get(int n) {
    while (!check(n)) ++n;
    return n;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    auto d = prime(n);

    int ans = 1;
    int want = 1;
    for (auto e : d) {
        ans *= e.first;
        int p = e.second;
        want = max(want, get(p));
    }   

    int op = 0;
    int t = want;
    while (t > 1) {
        ++op;
        t >>= 1;
    }   

    bool ch = 0;
    for (auto e : d) {
        ch |= (e.second != want);
    }   

    op += ch;

    cout << ans << ' ' << op << '\n';
    return 0;
}