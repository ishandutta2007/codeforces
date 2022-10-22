#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 51;
const int INF = 1e9 + 7;
int n;
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    int mn = INF;
    for (int i = 0; i < n; ++i) mn = min(mn, a[i]);
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += a[i] == mn;
    if (cnt > n / 2) {
        cout << "Bob\n";
    }   
    else {
        cout << "Alice\n";
    }   
}