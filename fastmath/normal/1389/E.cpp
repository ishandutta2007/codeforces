#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int m, d, w;
        cin >> m >> d >> w;
        int t = w / __gcd(d - 1, w);
        int mx = min(m, d);

        auto f = [&] () {
            int cnt = mx/t;
            return cnt * (cnt - 1) / 2;
        };  

        auto f_add = [&] () {
            int cnt = mx/t+1;
            return cnt * (cnt - 1) / 2;
        };

        int k = mx%t;
        cout << k * f_add() + (t - k) * f() << endl;
    }   
}