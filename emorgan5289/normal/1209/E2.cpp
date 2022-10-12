#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 12;
int dp[N+1][N][1<<N], p[N+1][1<<N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[j][i];
        sort(all(a), [](vector<int>& x, vector<int>& y){
            return *max_element(all(x)) > *max_element(all(y)); 
        });
        while (a.size() > n) a.pop_back();
        while (a.size() < n) a.pb(vector<int>(n, 0));
        for (int i = 1; i <= n; i++) {
            auto& r = a[i-1];
            for (int k = 0; k < 1<<n; k++) p[i][k] = 0;
            for (int j = 0; j < n; j++) {
                rotate(r.begin(), r.begin()+1, r.end());
                for (int k = 1; k < 1<<n; k++) {
                    dp[i][j][k] = p[i-1][k];
                    for (int l = 0; l < n; l++)
                        if (k&(1<<l))
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j][k^(1<<l)]+r[l]);
                    p[i][k] = max(p[i][k], dp[i][j][k]);
                }
            }
        }
        cout << p[n][(1<<n)-1] << "\n";
    }
}