#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
const int LG = 31;
int n;
int a[N], pr[N], mag[LG];
int ans = 0;
void add(int x) {
    for (int i = LG - 1; i >= 0; --i) {
        if ((x >> i) & 1) {
            if (!mag[i]) {
                mag[i] = x;
                ++ans;
                break;
            }
            else {
                x ^= mag[i];
            }   
        }   
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) pr[i + 1] = pr[i] ^ a[i];
    if (!pr[n]) {
        cout << "-1\n";
        exit(0);
    }   
    for (int i = 0; i < n; ++i) {
        add(pr[i + 1]);
    }   
    cout << ans << '\n';
}