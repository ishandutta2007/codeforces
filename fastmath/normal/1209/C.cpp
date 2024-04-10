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
const int N = 2e5 + 7;
bool used[N];
int a[N];
ii mn[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        a[i] = c - '0';
        used[i] = 0;
    }   
    mn[n] = {N, N};
    for (int i = n - 1; i >= 0; --i) {
        mn[i] = min(mp(a[i], i), mn[i + 1]);
    }   
    int l = 0;
    while (l < n) {
        int i = mn[l].s;
        used[i] = 1;
        l = i + 1;
    }   
    int mn = N;
    for (int i = 0; i < n; ++i) if (!used[i]) mn = min(mn, a[i]);
    for (int i = 0; i < n; ++i) used[i] &= a[i] <= mn;
    int last = -1;
    for (int i = 0; i < n; ++i) if (used[i]) last = a[i];
    vector <int> b;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) b.app(a[i]);
    }   
    for (int i = 0; i + 1 < (int)b.size(); ++i) if (b[i] > b[i + 1]) { cout << "-\n"; return; }
    if (b.size() && last > b[0]) { cout << "-\n"; return; }
    for (int i = 0; i < n; ++i) {
        if (used[i]) cout << '1';
        else cout << '2';
    }   
    cout << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) solve();
}