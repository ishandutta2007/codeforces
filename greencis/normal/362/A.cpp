#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
char s[15][15];
int d[15][15][15][15];
int dx[4] = {2,2,-2,-2};
int dy[4] = {2,-2,-2,2};

int main()
{
    cin >> n;
    while (n--) {
        int kx = -1, ky = -1, kx2 = -1, ky2 = -1;
        for (int i = 0; i < 8; ++i) {
            cin >> s[i];
            for (int j = 0; j < 8; ++j) {
                if (s[i][j] == 'K') {
                    if (kx == -1) kx = j, ky = i, s[i][j] = '.';
                    else kx2 = j, ky2 = i, s[i][j] = '.';
                }
            }
        }
        for (int i = 0; i < 15; ++i)
            for (int j = 0; j < 15; ++j)
                for (int ii = 0; ii < 15; ++ii)
                    for (int jj = 0; jj < 15; ++jj)
                        d[i][j][ii][jj] = 0;
        queue< pair< pii, pii > > q;
        q.push(make_pair(make_pair(kx, ky), make_pair(kx2, ky2)));
        while (!q.empty()) {
            int curx1 = q.front().first.first;
            int cury1 = q.front().first.second;
            int curx2 = q.front().second.first;
            int cury2 = q.front().second.second;
            q.pop();
            if (curx1 < 0 || curx1 >= 8 || cury1 < 0 || cury1 >= 8) continue;
            if (curx2 < 0 || curx2 >= 8 || cury2 < 0 || cury2 >= 8) continue;
            if (d[cury1][curx1][cury2][curx2]) continue;
            d[cury1][curx1][cury2][curx2] = 1;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    q.push(make_pair(
                                     make_pair(curx1 + dx[i], cury1 + dy[i]),
                                     make_pair(curx2 + dx[j], cury2 + dy[j])));
        }

        bool good = false;
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                if (s[i][j] != '#' && d[i][j][i][j]) good = true;
        if (good) puts("YES");
        else puts("NO");
    }

    return 0;
}