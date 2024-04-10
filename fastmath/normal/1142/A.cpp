#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18 + 7;
int n, k;
int get1(int l) {
    int w = n * k;
    return w / __gcd(w, l);
}   
int ans_min = INF, ans_max = -INF;
void get(int y) {
    for (int i = y; i <= n * k; i += k) {
        if (i) {
            ans_min = min(ans_min, get1(i));
            ans_max = max(ans_max, get1(i));
        }
    }   
}   
int mod(int n) {
    return (n % k + k) % k;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    int a, b;
    cin >> a >> b;
    vector <int> v1 = {mod(a), mod(-a)};
    vector <int> v2 = {mod(b), mod(-b)};
    for (int e1 : v1) {
        for (int e2 : v2) {
            int y = mod(e2 - e1);
            get(y);
        }   
    }   
    cout << ans_min << ' ' << ans_max << '\n';
}