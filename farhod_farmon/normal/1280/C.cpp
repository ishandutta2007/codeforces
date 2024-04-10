#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int s[N];
long long A, B;
vector < pair < int, int > > v[N];

int dfs(int x, int p, long long dip = 0)
{
        int cnt = 1;
        A += dip;
        s[x] = 1;
        for(auto y: v[x]){
                if(y.fi == p){
                        continue;
                }
                int sh = dfs(y.fi, x, dip + y.se);
                int g = min(cnt, sh);
                A -= 2ll * dip * g;
                cnt += sh - 2 * g;

                s[x] += s[y.fi];
                B += 1ll * y.se * min(s[y.fi], n - s[y.fi]);
        }

        return cnt;
}

void solve()
{
        cin >> n;
        n = 2 * n;
        for(int i = 1; i <= n; i++){
                v[i].clear();
                s[i] = 0;
        }
        for(int i = 1; i < n; i++){
                int x, y, w;
                cin >> x >> y >> w;
                v[x].push_back({y, w});
                v[y].push_back({x, w});
        }

        A = B = 0;
        assert(dfs(1, 1) == 0);

        cout << A << " " << B << "\n";
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int T;
        cin >> T;
        while(T--){
                solve();
        }
}