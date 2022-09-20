#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int m;
int a[N];
long long d[N];
long long f[N];
long long inf = 1e18;
pair<int, int> b[N];
long long pref[N], suf[N];

void solve(vector<int> &A, vector<int> &B, int X)
{
        for(int i = 0; i <= B.size(); i++){
                f[i] = inf;
        }

        for(int i = 0; i <= A.size(); i++){
                pref[i] = suf[i] = inf;
        }
        for(int i = A.size() - 1; i >= 0; i--){
                suf[i] = min(suf[i + 1], d[i] + X - 2ll * b[A[i]].se);
        }
        for(int i = 1; i <= A.size(); i++){
                pref[i] = min(pref[i - 1], d[i - 1] - b[A[i - 1]].se);
        }

        f[0] = d[A.size()];
        for(int i = 0; i < A.size(); i++){
                f[0] = min(f[0], d[i] + X - b[A[i]].se);
        }

        for(int i = 1, j = A.size(); i <= B.size(); i++){
                f[i] = d[A.size()] + b[B[i - 1]].fi - X;

                while(j > 0 && X - b[A[j - 1]].se <= b[B[i - 1]].fi - X){
                        j -= 1;
                }
                f[i] = min(f[i], suf[j] + b[B[i - 1]].fi);
                f[i] = min(f[i], pref[j] + 2ll * b[B[i - 1]].fi - X);
        }
        for(int i = 0; i <= B.size(); i++){
                d[i] = f[i];
        }
}

void solve()
{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1; i <= m; i++){
                cin >> b[i].fi >> b[i].se;
        }
        for(int i = 0; i <= m + 1; i++){
                d[i] = f[i] = 0;
        }

        sort(b + 1, b + m + 1);
        vector<pair<int, int>> nb;
        for(int i = 1; i <= m; i++){
                while(!nb.empty() && b[i].se <= nb.back().se){
                        nb.pop_back();
                }
                nb.push_back(b[i]);
        }
        m = nb.size();
        for(int i = 1; i <= m; i++){
                b[i] = nb[i - 1];
        }

        sort(a + 1, a + n + 1);

        a[0] = -1e9 - 1;
        a[n + 1] = 1e9 + 1;
        vector<vector<int>> blocks;
        for(int i = 0, j = 1; i <= n; i++){
                blocks.push_back({});
                while(j <= m && b[j].fi <= a[i]){
                        j += 1;
                }
                while(j <= m && b[j].se < a[i + 1]){
                        blocks.back().push_back(j);
                        j += 1;
                }
        }

        for(int j = 0; j <= blocks[0].size(); j++){
                d[j] = inf;
        }
        d[0] = 0;
        for(int i = 1; i <= n; i++){
                solve(blocks[i - 1], blocks[i], a[i]);
        }

        cout << d[blocks.back().size()] << "\n";
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                solve();
        }
}