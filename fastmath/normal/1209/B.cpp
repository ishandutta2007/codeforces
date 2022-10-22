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
const int C = 1e5, N = 101;
string s;
int a[N], b[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n >> s;
    for (int i = 0; i < n; ++i) { cin >> a[i] >> b[i]; swap(a[i], b[i]); }
    int ans = 0;
    for (int t = 0; t < C; ++t) {
        int nn = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            if (t >= a[i]) cnt = 1 + (t - a[i]) / b[i];
            nn += (s[i] == '1') ^ (cnt & 1);
        }   
        ans = max(ans, nn);
    }   
    cout << ans << '\n';
}