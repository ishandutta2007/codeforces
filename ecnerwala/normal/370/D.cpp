#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
char c[4000][4000];

void drawSquare(int x, int y, int d) {
for(int i = 0; i < d; i++) {
if(c[x][y + i] != 'w') c[x][y + i] = '+';
if(c[x + i][y] != 'w') c[x + i][y] = '+';
if(c[x + i][y + d-1] != 'w') c[x + i][y + d-1] = '+';
if(c[x + d-1][y + i] != 'w') c[x + d-1][y + i] = '+';
}
}

bool go() {
int cnt = 0;
int minx = N;
int maxx = 0;
int miny = M;
int maxy = 0;
for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
if(c[i][j] == 'w') {
cnt++;
minx = min(minx, i);
maxx = max(maxx, i);
miny = min(miny, j);
maxy = max(maxy, j);
}
}
if(cnt == 1) return true;
for(int i = minx + 1; i < maxx; i++) for(int j = miny + 1; j < maxy; j++) {
if(c[i][j] == 'w') {
return false;
}
}
int dx = maxx - minx + 1;
int dy = maxy - miny + 1;
int d = max(dx, dy);
if(d > min(N, M)) return false;
if(dx == dy) {
drawSquare(minx, miny, dx);
return true;
} else if (dx > dy) {
int vy = -1;
for(int i = minx + 1; i < maxx; i++) for(int j = miny; j <= maxy; j ++){
if(c[i][j] == 'w') {
if(vy == -1) vy = j;
else if(vy != j) return false;
}
}
if(vy == -1) {
drawSquare(minx, max(0, maxy - d + 1), d);
return true;
}
if(vy == maxy && maxy - d + 1 >= 0) {
drawSquare(minx, maxy - d + 1, d);
return true;
}
if(vy == miny && miny + d - 1 < M) {
drawSquare(minx, miny, d);
return true;
}
return false;
} else {
int vx = -1;
for(int i = miny + 1; i < maxy; i++) for(int j = minx; j <= maxx; j ++){
if(c[j][i] == 'w') {
if(vx == -1) vx = j;
else if(vx != j) return false;
}
}
if(vx == -1) {
drawSquare(max(0, maxx - d + 1), miny, d);
return true;
}
if(vx == maxx && maxx - d + 1 >= 0) {
drawSquare(maxx - d + 1, miny, d);
return true;
}
if(vx == minx && minx + d - 1 < N) {
drawSquare(minx, miny, d);
return true;
}
return false;
}


}

int main() {
cin >> N >> M;
for(int i = 0; i < N; i++) cin >> c[i];

if(go()) {
for(int i = 0; i < N; i++) cout << c[i] << '\n';
} else cout << -1 << '\n';
return 0;
}