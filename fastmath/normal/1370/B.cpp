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
        vector <vector <int> > p(2);
        for (int i = 1; i <= 2 * n; ++i) {
            int x; cin >> x;
            p[x&1].app(i);
        }

        vector <ii> ans;
        for (int t = 0; t < 2; ++t) {
            for (int i = 0; i + 1 < p[t].size(); i += 2) {
                ans.app(mp(p[t][i], p[t][i+1]));
            }   
        }   
        for (int i = 0; i < n - 1; ++i) {
            cout << ans[i].f << ' ' << ans[i].s << endl;
        }   
    }   

}