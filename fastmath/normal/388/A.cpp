#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 101;
int n;
int a[N];
bool check(int ans) {   
    int h = n / ans;
    int r = n % ans;
    int l = ans - r;
    vector <int> w;
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < h; ++j) w.push_back(j);
    }   
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j <= h; ++j) w.push_back(j);
    }   
    sort(w.begin(), w.end());
    for (int i = 0; i < n; ++i) {
        if (a[i] < w[i]) return 0;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int ans = 1; ; ++ans) {
        if (check(ans)) {
            cout << ans << '\n';
            exit(0);
        }   
    }   
}