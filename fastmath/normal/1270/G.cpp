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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e6 + 7;
int to[N];
bool used[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            to[i] = i - x;
        }   

        for (int i = 1; i <= n; ++i)
            used[i] = 0;

        int u = 1;
        vector <int> p;
        while (!used[u]) {
            p.app(u);
            used[u] = 1;
            u = to[u];
        }   
        reverse(all(p));

        vector <int> ans;
        for (int e : p) {
            ans.app(e);
            if (e == u)
                break;
        }   
        cout << ans.size() << '\n';
        for (int e : ans)
            cout << e << ' ';
        cout << '\n';
    }   
}