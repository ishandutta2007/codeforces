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
    int u, v;
    cin >> u >> v;
    if (u > v || ((v - u) & 1)) {
        cout << "-1\n";
    }   
    else {
        const int LG = 61;
        vector <int> ans;
        if (u)
            ans.app(u);
        int x = (v - u) >> 1;
        if (x) {
            if (ans.size() && (ans.back() & x) == 0)
                ans.back() += x;
            else
                ans.app(x);
            ans.app(x);
        }   
        cout << ans.size() << endl;
        for (int e : ans)
            cout << e << ' ';
        cout << endl;
    }   
}