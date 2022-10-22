#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
const int N = 1e6 + 7;
int pref[N], post[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (i - 1 >= 0 && s[i] == 'v' && s[i - 1] == 'v');
    }   
    for (int i = n - 1; i >= 0; --i) {
        post[i] = post[i + 1] + (i + 1 < n && s[i] == 'v' && s[i + 1] == 'v');
    }   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') {
            ans += pref[i] * post[i];
        }   
    }   
    cout << ans << '\n';
}