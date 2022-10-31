#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, q, p, v[300][300], noise[300][300], ans, c, tmp[300][300];
char s[300], g[300][300];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '*');
}

void bfs(int i, int j, int c) {
    v[i][j] = c;
    tmp[i][j] = (g[i][j] - 'A' + 1) * q;

    queue<pll> fila;
    fila.push({i, j});

    while(!fila.empty()) {
        pll u = fila.front(); fila.pop();
        if(tmp[u.X][u.Y] == 0) continue;
        noise[u.X][u.Y] += tmp[u.X][u.Y];

        for(int i = 0; i < 4; i++) {
            int nx = u.X + dx[i], ny = u.Y + dy[i];
            if(!valid(nx, ny) || v[nx][ny] == c) continue;

            tmp[nx][ny] = tmp[u.X][u.Y] / 2;
            v[nx][ny] = c;
            fila.push({nx, ny});
        }
    }
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &q, &p);
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        for(int j=0; j<m; j++) {
            g[i][j] = s[j];
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j] >= 'A' && g[i][j] <= 'Z') bfs(i, j, ++c);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(noise[i][j] > p) ans++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}