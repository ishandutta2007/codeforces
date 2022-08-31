#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> pos[25];
int a[400010], n;
ll init[22][22];
ll dp[1 << 20];
ll d[1 << 20][20];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        a[i]--;
        pos[a[i]].push_back(i);
    }
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++) {
            if(i == j) continue;
            for(int x = 0, y = 0; x < pos[i].size(); x++) {
                for(; y < pos[j].size() && pos[j][y] < pos[i][x]; y++);
                init[i][j] += y;
            }
            ll tmp = init[i][j];
            for(int k = 0; k < 1 << 20; k++) {
                if((k & (1 << j)) && (k & (1 << i))) d[k][j] += tmp;
            }
        }
    for(int i = 1; i < 1 << 20; i++) {
        dp[i] = 1e18;
        for(int j = 0; j < 20; j++) {
            if(i & (1 << j)) {
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + d[i][j]);
            }
        }
    }
    return cout << dp[(1 << 20) - 1] << endl, 0;
}