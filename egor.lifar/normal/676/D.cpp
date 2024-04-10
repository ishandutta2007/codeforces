#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <map>


using namespace std;

#define y1 y111


int n, m;
int xt, yt;
int xm, ym;
string s[1001];
bool good[1001][1001][4];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};


struct node{
    int x, y, move, dd;
    node(){}
    node(int _x, int _y, int _move, int _dd) {
        x = _x;
        y = _y;
        move = _move;
        dd = _dd;
    }
};


bool operator <(node a, node b) {
    return a.dd < b.dd || (a.dd == b.dd && make_pair(make_pair(a.x, a.y), a.move) < make_pair(make_pair(b.x, b.y), b.move));
}

bool operator ==(node a, node b) {
    return a.x == b.x && a.y == b.y && a.move == b.move && a.dd == b.dd;
}


int d[1001][1001][4];




int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    cin >> xt >> yt;
    xt--;
    yt--;
    cin >> xm >> ym;
    xm--;
    ym--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                continue;
            }
            if (s[i][j] == '<') {
                good[i][j][0] = 1;
                continue;
            }
            if (s[i][j] == '^') {
                good[i][j][1] = 1;
                continue;
            }
            if (s[i][j] == '>') {
                good[i][j][2] = 1;
                continue;
            }
            if (s[i][j] == 'v') {
                good[i][j][3] = 1;
                continue;
            }
            if (s[i][j] == '|') {
                good[i][j][1] = 1;
                good[i][j][3] = 1;
                continue;
            }
            if (s[i][j] == '-') {
                good[i][j][0] = 1;
                good[i][j][2] = 1;
                continue;
            }
            if (s[i][j] == '+') {
                good[i][j][0] = 1;
                good[i][j][1] = 1;
                good[i][j][2] = 1;
                good[i][j][3] = 1;
                continue;
            }
            if (s[i][j] == 'L') {
                good[i][j][1] = 1;
                good[i][j][2] = 1;
                good[i][j][3] = 1;
                continue;
            }
            if (s[i][j] == 'R') {
                good[i][j][0] = 1;
                good[i][j][1] = 1;
                good[i][j][3] = 1;
                continue;
            }
            if (s[i][j] == 'U') {
                good[i][j][0] = 1;
                good[i][j][2] = 1;
                good[i][j][3] = 1;
                continue;
            }
            if (s[i][j] == 'D') {
                good[i][j][0] = 1;
                good[i][j][1] = 1;
                good[i][j][2] = 1;
                continue;
            }
        }
    }
    queue<node> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                d[i][j][k] = 1000000000;
            }
        }
    }
    d[xt][yt][0] = 0;
    q.push(node(xt, yt, 0, 0));
    while (!q.empty()) {
        node a = q.front();
        q.pop();
        int t = (a.move + 1) % 4;
        if (d[a.x][a.y][t] > d[a.x][a.y][a.move] + 1) {
            d[a.x][a.y][t] = d[a.x][a.y][a.move] + 1;
            q.push(node(a.x, a.y, t, d[a.x][a.y][t]));
        }
        for (int k = 0; k < 4; k++) {
            int x1 = a.x + dx[k];
            int y1 = a.y + dy[k];
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) {
                continue;
            }
            if (good[a.x][a.y][(k - a.move + 4) % 4]) {
                if (good[x1][y1][(k + 2 - a.move + 4) % 4]) {
                    if (d[x1][y1][a.move] > d[a.x][a.y][a.move] + 1) {
                        d[x1][y1][a.move] = d[a.x][a.y][a.move] + 1;
                        q.push(node(x1, y1, a.move, d[x1][y1][a.move]));
                    }
                }
            }
        }
    }
    int ans = 1000000000;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, d[xm][ym][i]);
    }
    if (ans == 1000000000) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}