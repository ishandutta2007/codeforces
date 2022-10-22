#include <string>
#include <iostream>

using namespace std;

int k, n, m, i, j, p, x, y, rez;
int a[50][50][50], dx[6] = {-1, 0, 1, 0, 0, 0}, dy[6] = {0, -1, 0, 1, 0, 0}, dz[6] = {0, 0, 0, 0, -1, 1};
string s[50][50];

void fill(int x, int y, int z) {
    a[x][y][z] = 2;
    ++rez;
    for (int i = 0; i < 6; ++i)
        if (a[x + dx[i]][y + dy[i]][z + dz[i]] == 1)
            fill(x + dx[i], y + dy[i], z + dz[i]);
}
            
int main() {
    cin >> k >> n >> m;
    for (i = 1; i <= k; ++i)
        for (j = 1; j <= n; ++j)
            cin >> s[i][j];

    for (i = 1; i <= k; ++i)
        for (j = 1; j <= n; ++j)
            for (p = 1; p <= m; ++p)
                if (s[i][j][p - 1] == '.')
                    a[i][j][p] = 1;
                else
                    a[i][j][p] = 0;
    
    cin >> x >> y;
    fill(1, x, y);
    cout << rez;
}