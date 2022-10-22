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
const int N = 1e6 + 7;
int suff[N];
int l[N], r[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    string s;
    cin >> s;
    int ans = n * (n - 1) / 2;
    for (int i = 0; i < n; ++i) {
        if (i && s[i - 1] == s[i])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;
    }   
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] != s[i])
            ans -= l[i - 1];
    }   
    for (int i = n - 1; i >= 0; --i)
        if (i + 1 < n && s[i + 1] == s[i])
            r[i] = r[i + 1] + 1;
        else
            r[i] = 1;
    for (int i = 0; i + 1 < n; ++i)
        if (s[i] != s[i + 1])
            ans -= r[i + 1];
    for (int i = 0; i + 1 < n; ++i)
        ans += s[i] != s[i + 1];
    cout << ans << endl;            
}