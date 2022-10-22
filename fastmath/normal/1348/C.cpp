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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(all(s));

        if (s[k - 1] != s[0]) {
            cout << s[k - 1] << endl;
            continue;
        }
        else if (s[k] == s.back()) {
            int t = n - k;
            int cnt = (t + k - 1) / k;
            string ans;
            ans += s[0];
            for (int i = 0; i < cnt; ++i)
                ans += s[k];
            cout << ans << endl;
        }   
        else {
            cout << s.substr(k - 1, n - k + 1) << endl;
        }                      

        /*
        int ptr = 0;
        string ans;
        while (ptr < s.size()) {

            string add;
            for (int i = ptr; i < ptr + k && i < s.size(); ++i)
                add += s[i];

            if (add[0] == add.back()) {
                ans += add[0];
                ptr += add.size();
                continue;
            }   
            else {
                for (int i = ptr; i < s.size(); ++i)
                    ans += s[i];
                break;
            }   

            ptr += k;
        }   
        cout << ans << endl;
        */
    }   
}