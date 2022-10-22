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
        string s;
        cin >> s;
        int n = s.size();
        vector <int> a;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (cur)
                    a.app(cur);
                cur = 0;
            }   
            else {
                cur++;
            }   
        }   
        if (cur)
            a.app(cur);

        sort(all(a)); reverse(all(a));
        int ans = 0;
        for (int i = 0; i < a.size(); i += 2)
            ans += a[i];
        cout << ans << endl;
    }   
}