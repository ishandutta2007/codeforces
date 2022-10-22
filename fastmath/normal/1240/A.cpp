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
const int N = 2e5 + 7;
int ar[N];
bool check(int n, int x, int a, int y, int b, int k) {
    int t = (a * b) / __gcd(a, b);
    t = n / t;
    int sum = 0;
    for (int i = 0; i < t; ++i) sum += ar[i] * (x + y);
    int t1 = n / a - t;
    for (int i = t; i < t + t1; ++i) sum += ar[i] * x;
    int t2 = n / b - t;
    for (int i = t + t1; i < t + t1 + t2; ++i) sum += ar[i] * y;
    return sum >= k;
}   
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) { cin >> ar[i]; ar[i] /= 100; }
    sort(ar, ar + n); reverse(ar, ar + n);
    int x, a, y, b, k; cin >> x >> a >> y >> b >> k;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }   
    int l = 0, r = n + 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (check(m, x, a, y, b, k)) r = m;
        else l = m;
    }   
    if (r == n + 1) cout << "-1\n";
    else cout << r << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int q; cin >> q;
    while (q--) solve();
}