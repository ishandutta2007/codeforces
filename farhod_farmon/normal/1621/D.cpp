#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 555;

using namespace std;

int n;
long long a[N][N];
long long d[N][N];

void solve()
{
    long long res = 0;
    cin >> n;
    set<pair<long long, int>> s;
    long long inf = 1e18;
    for(int i = 0; i < 2 * n; i++){
        for(int j = 0; j < 2 * n; j++){
            cin >> a[i][j];
            if(i >= n && j >= n){
                res += a[i][j];
            }
        }
    }
    long long tot = inf;
    for (int x : {0, n - 1}) {
        for (int y : {n, 2 * n - 1}) {
            tot = min(tot, a[x][y]);
            tot = min(tot, a[y][x]);
        }
    }

    cout << res + tot << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}