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
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans;
    for (int i = 0; i < n; ++i)
        ans += '9';
    for (int i = 0; i < n; ++i) {
        string t = s.substr(i, n - i) + s.substr(0, i);
        int sh = (10 - (t[0] - '0')) % 10;
        string nn;
        for (char c : t) {
            nn += (char)('0' + (c - '0' + sh) % 10);            
        }   
        ans = min(ans, nn);
    }   
    cout << ans << '\n';
}