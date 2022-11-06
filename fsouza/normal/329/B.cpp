#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

#define INF 1000000000
#define MAXR 1000
#define MAXC 1000

using namespace std;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int mindist[MAXR][MAXC], blocked[MAXR][MAXC], many[MAXR][MAXC];

void bfs(pair <int, int> start, int nr, int nc)
{
    for (int y = 0; y < nr; y++)
        for (int x = 0; x < nc; x++)
            mindist[y][x] = INF;

    int sy = start.first, sx = start.second;
    queue<pair <int, int> > q;

    mindist[sy][sx] = 0;
    q.push(start);
    
    while (!q.empty()) {
        pair <int, int> n = q.front(); q.pop();
        int ny = n.first, nx = n.second;
        
        for (int dir = 0; dir < 4; dir++) {
            int y2 = ny + dy[dir], x2 = nx + dx[dir];
            if (0 <= y2 && y2 < nr && 0 <= x2 && x2 < nc && !blocked[y2][x2]) {
                if (mindist[y2][x2] > mindist[ny][nx] + 1) {
                    mindist[y2][x2] = mindist[ny][nx] + 1;
                    q.push(make_pair(y2, x2));
                }
            }
        }
    }
    
}

int main()
{
    int nr, nc;

    scanf("%d %d", &nr, &nc);

    int ey, ex;
    int sy, sx;

    for (int y = 0; y < nr; y++) {
        for (int x = 0; x < nc; x++) {
            char c;
            scanf(" %c", &c);

            if (c == 'E') {
                ey = y;
                ex = x;
            }
            if (c == 'S') {
                sy = y;
                sx = x;
            }
            blocked[y][x] = (c=='T');

            if ('0' <= c && c <= '9')
                many[y][x] = c-'0';
            else
                many[y][x] = 0;
        }
    }

    bfs(make_pair(ey, ex), nr, nc);

    int ret = 0;

    for (int y = 0; y < nr; y++)
        for (int x = 0; x < nc; x++)
            if (mindist[y][x] <= mindist[sy][sx])
                ret += many[y][x];

    printf("%d\n", ret);

    return 0;
}