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
        int n;
        cin >> n;
        map <int, int> d;
        d[0] = 1;
        int cur = 0, ans = 0;
        string s;
        cin >> s;
        for (int i = 1; i <= n; ++i) {
            int x = s[i-1]-'0';
            cur += x;
            ans += d[cur-i];
            d[cur-i]++;
        }   
        cout << ans << endl;
    }   
}