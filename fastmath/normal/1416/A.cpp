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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <vector <int> > pos(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[a[i]].app(i);
        }
        vector <int> ans(n + 1, n + 1);
        for (int x = 1; x <= n; ++x) {  
            if (pos[x].size()) {
                int mx = max(pos[x][0], n - pos[x].back() - 1);
                for (int i = 0; i + 1 < pos[x].size(); ++i)
                    mx = max(mx, pos[x][i + 1] - pos[x][i] - 1);
                ans[mx + 1] = min(ans[mx + 1], x);
            }   
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] = min(ans[i], ans[i - 1]);
            if (ans[i] == n + 1)
                cout << -1 << ' ';
            else
                cout << ans[i] << ' ';
        }   
        cout << endl;
    }

}