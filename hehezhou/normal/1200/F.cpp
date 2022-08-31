#include <bits/stdc++.h>
using namespace std;
const int mod = 2520;
int n;
int insta[1010][2530], ans[1010][2530];
int w[1010];
int dep[1010][2530];
int son[1010][12], len[1010];
int sta[2530000];
int cnt[1010];
inline int dfs(int x, int y) {
    insta[x][y] = 1;
    if(ans[x][y]) return ans[x][y];
    sta[dep[x][y]] = x;
    int newx = son[x][y % len[x]], newy = (y + w[newx]) % mod;
    if(insta[newx][newy]) {
        if(ans[newx][newy]) return ans[x][y] = ans[newx][newy];
        int l = dep[newx][newy], r = dep[x][y];
        for(int i = l; i <= r; i++) cnt[sta[i]] = 0;
        for(int i = l; i <= r; i++) if(cnt[sta[i]] == 0) cnt[sta[i]] = 1, ans[x][y]++;
        return ans[x][y];
    }
    dep[newx][newy] = dep[x][y] + 1;
    ans[x][y] = dfs(newx, newy);
    return ans[x][y];
}
int main() {
    ios :: sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i], w[i] = (w[i] % mod + mod) % mod;
    for(int i = 1; i <= n; i++) {
        cin >> len[i];
        for(int j = 0; j < len[i]; j++) cin >> son[i][j];
    }
    int q;
    cin >> q;
    while(q--) {
        int x, c;
        cin >> x >> c;
        c = (c % mod + mod) % mod;
        cout << dfs(x, (c + w[x]) % mod) << endl;
    }
    return 0;
}