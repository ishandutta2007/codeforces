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

    auto type = [](int a, int b) {
        return a < b;
    };   

    while (t--) {
        int n;
        cin >> n;

        vector <int> ans;

        while (n--) {
            int x;
            cin >> x;

            while (ans.size() >= 2 && type(ans[ans.size() - 2], ans.back()) == type(ans.back(), x)) {
                ans.pop_back();
            }   
            ans.app(x);

        }   

        cout << ans.size() << endl;
        for (auto e : ans)
            cout << e << ' ';
        cout << endl;

    }   

}