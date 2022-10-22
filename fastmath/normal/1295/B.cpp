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
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int b = 0;
        map <int, int> d;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')
                ++b;
            else
                --b;
            ++d[b];
        }   
        if (b == 0) {
            if (d[x])
                cout << "-1\n";
            else
                cout << "0\n";
        }   
        else {
            int ans = 0;
            int b1 = 0;

            int mod = abs(b);

            for (int i = 0; i < n; ++i) {
                if ((b1 % mod + mod) % mod == (x % mod + mod) % mod) {
                    if (b > 0)
                        ans += x >= b1;
                    else
                        ans += x <= b1;
                }   

                if (s[i] == '0')
                    ++b1;
                else
                    --b1;            
            }   
            cout << ans << '\n';
        }   
    }   
}