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

        int ptr = 0, cur = 0, ans = 0;
        for (int i = 0; ; ++i) {
            while (ptr < s.size() && cur + i >= 0) {
                if (s[ptr] == '+')
                    ++cur;
                else
                    --cur;
                ++ptr;
            }
            ans += ptr;

            if (ptr == s.size() && cur + i >= 0)
                break;
        }   
        cout << ans << endl;
    }   

}