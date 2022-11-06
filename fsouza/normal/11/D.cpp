#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 19

typedef long long lint;

using namespace std;

int adj[MAXN][MAXN];
lint dp[1<<MAXN][MAXN];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }

    lint result = 0;
    int fullmask = (1<<n)-1;

    for (int right = n-1; right >= 2; right--) {
        fullmask ^= 1<<right;

        for (int s = 0; s <= fullmask; s++)
            for (int last = 0; last <= right; last++)
                dp[s][last] = 0;
        dp[0][right] = 1;

        for (int s = 0; s <= fullmask; s++) {
            int many = __builtin_popcount(s);

            for (int last = 0; last <= right; last++) {
                if (last != right && !(s & (1<<last))) continue;

                for (int newlast = 0; newlast < right; newlast++) {
                    if (s & (1<<newlast)) continue;
                    
                    if (adj[last][newlast])
                        dp[s|(1<<newlast)][newlast] += dp[s][last];
                }
                
                if (many >= 2 && adj[last][right])
                    result += dp[s][last];
            }
        }
    }

    cout << result/2 << endl;

    return 0;
}