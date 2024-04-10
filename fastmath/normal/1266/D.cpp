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
const int N = 5e5 + 7;
int n, m;
int sum[N];
struct Edge {
    int u, v, c;
};  
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        sum[u] -= c;
        sum[v] += c;
    }   
    vector <int> l, r;
    for (int i = 1; i <= n; ++i) {
        if (sum[i] < 0)
            l.app(i);
        else if (sum[i] > 0)
            r.app(i);
    }
    for (int i = 1; i <= n; ++i)
        sum[i] = abs(sum[i]);
    vector <Edge> ans;
    int ptr = 0;
    for (int i : l) {
        while (ptr < r.size()) {
            int j = r[ptr];
            if (sum[i] <= sum[j]) {
                if (sum[i])
                    ans.app({i, j, sum[i]});
                sum[j] -= sum[i];
                break;
            }   
            else {
                if (sum[j])
                    ans.app({i, j, sum[j]});
                sum[i] -= sum[j];
                ++ptr;
            }   
        }   
    }   
    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e.u << ' ' << e.v << ' ' << e.c << '\n';
}