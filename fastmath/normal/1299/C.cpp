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
    cout.precision(20);
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> ans;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ans.app(mp(x, 1));
        while (ans.size() > 1 && ans.back().f * ans[ans.size() - 2].s < ans[ans.size() - 2].f * ans.back().s) {
            int x = ans.back().f, y = ans.back().s;
            ans.pop_back();
            ans.back().f += x; 
            ans.back().s += y;
        }   
    }   
    for (auto e : ans) 
        for (int i = 0; i < e.s; ++i)
            cout << (double)e.f / e.s << '\n';
}