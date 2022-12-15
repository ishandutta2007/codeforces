#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005
#define INF 0x3f3f3f

char pasture[SIZE][SIZE];
int dist[SIZE][SIZE];

int main() {
    int h, w, k;
    scanf("%d %d %d", &h, &w, &k);
    int finalX, finalY;
    queue<pair<int, int>> bfs;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < h; i++) {
        scanf("%s", pasture[i]);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    bfs.push(make_pair(a-1, b-1));
    dist[a-1][b-1] = 0;
    scanf("%d %d", &finalX, &finalY);
    finalX--;
    finalY--;
    //printf("%d %d %d %d\n", a, b, finalX, finalY);

    while(!bfs.empty()) {
        pair<int, int> cur = bfs.front();
        //printf("Distancia ate (%d,%d) = %d\n", cur.first, cur.second, dist[cur.first][cur.second]);
        bfs.pop();
        for(int i = cur.first-1; i >= cur.first - k; i--) {
            if(i < 0 || pasture[i][cur.second] == '#' || (dist[i][cur.second] != -1 && dist[i][cur.second] <= dist[cur.first][cur.second])) {
                break;
            }
            if(dist[i][cur.second] == -1) {
                dist[i][cur.second] = dist[cur.first][cur.second] + 1;
                bfs.push(make_pair(i, cur.second));
            }
        }
        for(int i = cur.first+1; i <= cur.first + k; i++) {
            if(i >= h || pasture[i][cur.second] == '#' || (dist[i][cur.second] != -1 && dist[i][cur.second] <= dist[cur.first][cur.second])) {
                break;
            }
            if(dist[i][cur.second] == -1) {
                dist[i][cur.second] = dist[cur.first][cur.second] + 1;
                bfs.push(make_pair(i, cur.second));
            }
        }
        for(int j = cur.second-1; j>= cur.second - k; j--) {
            if(j < 0 || pasture[cur.first][j] == '#' || (dist[cur.first][j] != -1 && dist[cur.first][j] <= dist[cur.first][cur.second])) {
                break;
            }
            if(dist[cur.first][j] == -1) {
                dist[cur.first][j] = dist[cur.first][cur.second] + 1;
                bfs.push(make_pair(cur.first, j));
            }
        }
        for(int j = cur.second+1; j <= cur.second + k; j++) {
            if(j >= w || pasture[cur.first][j] == '#' || (dist[cur.first][j] != -1 && dist[cur.first][j] <= dist[cur.first][cur.second])) {
                break;
            }
            if(dist[cur.first][j] == -1) {
                dist[cur.first][j] = dist[cur.first][cur.second] + 1;
                bfs.push(make_pair(cur.first, j));
            }
        }
    }
    cout << dist[finalX][finalY];
    return 0;
}