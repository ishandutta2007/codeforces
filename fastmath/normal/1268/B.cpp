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
const int N = 3e5 + 7;
int a[N];
int cnt[2];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    int ans = 0;
    vector <int> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i] >> 1;
        if (a[i] & 1)
            ++cnt[i & 1];
    }
    cout << ans + min(cnt[0], cnt[1]) << '\n';
}