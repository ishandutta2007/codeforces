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
void rev(string &s, int l, int r) {
    string t = s.substr(l, r - l + 1);
    reverse(all(t));
    s = s.substr(0, l) + t + s.substr(r + 1, s.size() - r);
}   
string s;
vector <ii> ans;
void make(int i, char w) {
    if (s[i] == w) return;
    for (int j = i + 1; ; ++j) 
        if (s[j] == w) {
            ans.app(mp(i + 1, j + 1));
            rev(s, i, j);
            return;
        }   
    cout << "LOL\n";
    exit(1);
}   
void solve() {
    ans.clear();
    int n, k; cin >> n >> k;
    cin >> s;
    for (int i = 0; i < k - 1; ++i) {
        make(i * 2, '(');
        make(i * 2 + 1, ')');
    }   
    int start = 2 * (k - 1);
    int len = n - start;
    len >>= 1;
    for (int i = start; i < start + len; ++i) {
        make(i, '(');
    }
    for (int i = start + len; i < n; ++i) {
        make(i, ')');
    }   
    cout << ans.size() << '\n';
    for (auto e : ans) cout << e.f << ' ' << e.s << '\n';
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