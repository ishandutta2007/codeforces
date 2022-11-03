#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 1e6 + 13;

int sum(int a, int b) {
    a += b;

    if(a >= M)
        a -= M;

    return a;
}

int pow2(int n, int k) {
    if(k <= 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k & 1)
        return pw * 1ll * pw % M * n % M;
    else
        return pw * 1ll * pw % M;
}

int d[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    int ans = pow2(2, n - 2);
    for(int i = 2; i <= n; i++) {
        if(d[i] == 0) {
            d[i] = i;
            if(i * 1ll * i <= n)
                for(int j = i * i; j <= n; j += i)
                    d[j] = i;
        }

        int x = i;
        map<int, int> mp;
        while(x > 1) {
            mp[d[x]]++;
            x /= d[x];
        }

        int res = 1;
        for(auto p : mp)
            res = res * (p.s + 1);

//        cout << i << ' ' << res << ' ' << pow2(2, n - i - 1) << endl;

        ans = sum(ans, res * 1ll * pow2(2, n - i - 1) % M);
    }

    cout << ans << endl;
}