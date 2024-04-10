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
        int n;
        cin >> n;
        string s = to_string(n);
        string post;
        vector <string> ans;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            if (s[i] > '0') {
                ans.app(s[i] + post);
            }   
            post += '0';
        }   
        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << ' ';
        cout << endl;
    }   
}