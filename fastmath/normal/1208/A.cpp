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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t;
    while (t--) {
        int a, b, n; cin >> a >> b >> n;
        if (n % 3 == 0) cout << a << '\n';
        else if (n % 3 == 1) cout << b << '\n';
        else cout << (a ^ b) << '\n';
    }
}