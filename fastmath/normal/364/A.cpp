#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4007;
const int C = N * 10;
int cnt[C];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int w;
    cin >> w;
    string s;
    cin >> s;
    int n = s.size();
    int x = 0;
    for (int l = 0; l < n; ++l) {
        int cur = 0;
        for (int r = l; r < n; ++r) {
            cur += s[r] - '0';
            ++cnt[cur];
            x += cur == 0;
        }   
    }   
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        int cur = 0;
        for (int r = l; r < n; ++r) {
            cur += s[r] - '0';
            if (w) {
                if (cur && w % cur == 0 && w / cur < C) {
                    ans += cnt[w / cur];
                }   
            }
            else {
                if (cur == 0) {
                    ans += n * (n + 1) / 2;
                }   
                else {
                    ans += x;
                }   
            }   
        }   
    }   
    cout << ans << '\n';
}