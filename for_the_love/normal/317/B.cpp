#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int w[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
const int dx = 150;
const int dy = 150;
struct Qnode{
    int x, y;
} now, t;
int n, m, x, y;
queue <Qnode> q;
int s[355][355], v[355][355];
int main(){
    scanf("%d%d", &n, &m);
    now.x = dx; now.y = dy; s[now.x][now.y] = n;
    if (n >= 4){
        q.push(now);
        v[now.x][now.y] = 1;
    }
    while (!q.empty()){
        t = q.front(); q.pop();
        int d = s[t.x][t.y] / 4;
        s[t.x][t.y] %= 4;
        for (int k = 0; k < 4; k++){
            now = t;
            now.x += w[k][0];
            now.y += w[k][1];
            s[now.x][now.y] += d;
            if (s[now.x][now.y] >= 4 && !v[now.x][now.y]){
                q.push(now);
                v[now.x][now.y] = 1;
            }
        }
        now = t;
        v[now.x][now.y] = 0;
    }
    while (m--){
        scanf("%d%d", &x, &y);
        if (x + dx < 0 || x + dx > 300 || y + dy < 0 || y + dy > 300) puts("0"); else printf("%d\n", s[x + dx][y + dy]);
    }
}