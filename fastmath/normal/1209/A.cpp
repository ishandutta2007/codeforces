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
const int N = 101;
bool a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    while (n--) {
        int x; cin >> x;
        a[x] = 1;
    }   
    int ans = 0;
    while (1) {
        int mn = 0;
        for (int i = 1; i < N; ++i) {
            if (a[i]) { mn = i; break; }
        }   
        if (!mn) break;
        ++ans;
        for (int i = mn; i < N; i += mn) a[i] = 0;
    }   
    cout << ans << '\n';
}