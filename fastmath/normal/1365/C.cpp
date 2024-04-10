#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
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
    int n;
    cin >> n;
    vector <int> a(n), b(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }   
    vector <int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; --b[i];
        ++w[(pos[b[i]] - i + n) % n];
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, w[i]);
    cout << ans << endl;
}