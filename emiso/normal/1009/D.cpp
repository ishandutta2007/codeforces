#include <bits/stdc++.h>

#define lim 11000

using namespace std;

int n, m, c;
vector<pair<int, int> > resp(100010);

int main() {
    scanf("%d %d", &n, &m);
    vector<vector<bool> > used(lim, vector<bool>(n+1, 0));

    if(n < lim) {
        c = 0;
        for(int x = 1; x <= n && c < m; x++) {
            for(int i = 1; i + x <= n && c < m; i++) {
                if(used[i][i+x]) continue;
                if(__gcd(x, i) == 1) {
                    for(int j = i + x; j <= n && c < m; j += i) {
                        used[i][j] = used[j][i] = 1;
                        resp[c++] = {i, j};
                    }
                }
            }
        }
    } else {
        c = 0;
        for(int x = 1; x <= n && c < m; x++) {
            for(int i = 1; i + x <= n && c < m; i += x) {
                resp[c++] = {i, i+x};
            }
        }
    }

    if(c == m && m >= n - 1) {
        puts("Possible");
        for(int i = 0; i < m; i++) {
            printf("%d %d\n", resp[i].first, resp[i].second);
        }
    } else puts("Impossible");

    return 0;
}