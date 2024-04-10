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
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <int> pos;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= n - k + 1) {
            pos.app(i);
        }   
    }
    int sum = 0;
    for (int i = n - k + 1; i <= n; ++i)
        sum += i;
    const int MOD = 998244353;
    int cnt = 1;
    for (int i = 0; i + 1 < pos.size(); ++i) {
        cnt = (cnt * (pos[i + 1] - pos[i])) % MOD;
    }   
    cout << sum << ' ' << cnt << endl;;
}