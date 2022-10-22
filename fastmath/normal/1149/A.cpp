#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int a[N];
int cnt[3];
bool prime(int n) {
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return 0;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }   
    if (!cnt[1]) {
        for (int i = 0; i < n; ++i) cout << "2 ";
        cout << '\n';
        exit(0);
    }   
    if (!cnt[2]) {
        for (int i = 0; i < n; ++i) cout << "1 ";
        cout << '\n';
        exit(0);       
    }   
    cout << "2 1 ";
    for (int i = 0; i < cnt[2] - 1; ++i) cout << "2 ";
    for (int i = 0; i < cnt[1] - 1; ++i) cout << "1 ";
    cout << '\n';
}