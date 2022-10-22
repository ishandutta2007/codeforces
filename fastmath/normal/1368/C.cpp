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
    int n;
    cin >> n;

    vector <ii> ans;

    int x = 0, y = 0;
    for (int i = 0; i <= n; ++i) {
        for (int dx = 0; dx < 3; ++dx) {
            for (int dy = 0; dy < 3; ++dy) {
                if (dx == 1 && dy == 1)
                    continue;
                if (dx == 2 && dy == 2)
                    continue;
                ans.app(mp(x+dx, y+dy));
            }   
        }   
        x += 2;
        y += 2;
    }   
    ans.app(mp(x, y));

    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e.f << ' ' << e.s << endl;    
}