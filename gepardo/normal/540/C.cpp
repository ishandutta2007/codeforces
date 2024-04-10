#include <iostream>
#include <queue>
#include <algorithm>

#define try(x, y) if (!used[x][y] && a[x][y] == '.') used[x][y] = true, q.push({x, y});

using namespace std;

int n, m;
char a[1001][1001];
int dx, dy;
int sx, sy;
bool dstCrack = false;
bool used[1001][1001];

const int inf = 123456789;

int neighbourCount(int x, int y)
{
    int nc = 0;
    if (a[x + 1][y] == '.') nc++;
    if (a[x - 1][y] == '.') nc++;
    if (a[x][y + 1] == '.') nc++;
    if (a[x][y - 1] == '.') nc++;
    return nc;
}

int main()
{
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            a[i][j] = 'X';
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i] + 1;
    cin >> sx >> sy >> dx >> dy;
    a[sx][sy] = '.';
    if (a[dx][dy] == 'X') dstCrack = true, a[dx][dy] = '.';


    queue < pair<int,int> > q;
    q.push({sx, sy}); used[sx][sy] = true;

    while (!q.empty())
    {
        pair <int,int> p = q.front(); q.pop();
        try(p.first + 1, p.second);
        try(p.first - 1, p.second);
        try(p.first, p.second + 1);
        try(p.first, p.second - 1);
    }

    if (!used[dx][dy]) { cout << "NO"; return 0; }
    if (dstCrack) { cout << "YES"; return 0; }

    int mnc = 0;
    if (dx == sx && dy == sy) mnc = 0; else mnc = 1;

    if (neighbourCount(dx, dy) > mnc) cout << "YES"; else cout << "NO";

}