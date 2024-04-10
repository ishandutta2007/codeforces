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
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        vector <int> cnt(10000 + 1);

        int n;
        cin >> n;

        for (int i = 10000; i >= 2; --i) {
            int sh = i * (i - 1) / 2;
            while (n >= sh) {
                ++cnt[i];
                n -= sh;
            }   
        }   

        string ans = "1";
        for (int i = 1; i <= 10000; ++i) {
            ans += "3";
            for (int j = 0; j < cnt[i]; ++j)
                ans += "7";
        }   
        cout << ans << endl;
    }   


}