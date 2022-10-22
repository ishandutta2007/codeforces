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
const int N = 1e5 + 7, INF = 1e9 + 7;
int n, k, a[N], pref[N], post[N];
bool check(int m) {
    int l = 0;
    for (int i = 0; i < n; ++i) {
        while (l < n && a[l] <= a[i] + m) ++l;
        if (a[i] * i - pref[i] + post[l] - (a[i] + m) * (n - l) <= k) return 1;
    }   
    int r = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (r >= 0 && a[r] >= a[i] - m) --r;
        if ((a[i] - m) * (r + 1) - pref[r + 1] + post[i + 1] - a[i] * (n - i - 1) <= k) return 1;
    }   
    return 0;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; --i) post[i] = post[i + 1] + a[i];
    int l = -1;
    int r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << '\n';
}