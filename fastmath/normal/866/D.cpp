#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
int n;
int a[N];
multiset <int> ms;
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ms.size() && *ms.begin() < a[i]) {
            ans += a[i] - *ms.begin();
            ms.erase(ms.begin());
            ms.insert(a[i]);
        }
        ms.insert(a[i]);
    }   
    cout << ans << '\n';;
}