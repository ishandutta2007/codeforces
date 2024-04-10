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
        string s;
        cin >> s;
        vector <bool> have(2);
        for (char c : s)
            have[c - '0'] = 1;
        if (have[0] && have[1]) {
            string ans;

            int pos = 0;
            for (char c : s) {
                int add = c - '0';
                if (add ^ pos) {
                    pos ^= 1;
                    ans += '0' + (add ^ 1);
                }   
                ans += c;
                pos ^= 1;
            }   

            cout << ans << endl;
        }   
        else {
            cout << s << endl;
        }   

    }   
}