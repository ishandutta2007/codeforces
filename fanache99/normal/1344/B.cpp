#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

char color[1 + MAXN][1 + MAXM];
bool seen[1 + MAXN][1 + MAXM];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool onLine[1 + MAXN], onColumn[1 + MAXM];

void BFS(int x, int y, int n, int m) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    seen[x][y] = true;
    while (!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x0 = x + dx[i], y0 = y + dy[i];
            if (x0 >= 1 && x0 <= n && y0 >= 1 && y0 <= m && color[x0][y0] == '#' && !seen[x0][y0]) {
                seen[x0][y0] = true;
                q.push(make_pair(x0, y0));
            }
        }
    }
}

int main(){
    //ifstream cin("input.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> color[i] + 1;
    bool bad = false;
    int components = 0;
    bool found = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (color[i][j] == '#') {
                onLine[i] = onColumn[j] = true;
                found = true;
                if (!seen[i][j]) {
                    components++;
                    BFS(i, j, n, m);
                }
            }
    if (!found) {
        cout << "0\n";
        return 0;
    }
    bool emptyLine = false;
    for (int i = 1; i <= n; i++) {
        emptyLine |= (!onLine[i]);
        int first = 0, last = 0, howMany = 0;
        for (int j = 1; j <= m; j++)
            if (color[i][j] == '#') {
                if (!first)
                    first = j;
                last = j;
                howMany++;
            }
        if (howMany > 0 && last - first + 1 != howMany)
            bad = true;
    }
    bool emptyColumn = false;
    for (int j = 1; j <= m; j++) {
        emptyColumn |= (!onColumn[j]);
        int first = 0, last = 0, howMany = 0;
        for (int i = 1; i <= n; i++)
            if (color[i][j] == '#') {
                if (!first)
                    first = i;
                last = i;
                howMany++;
            }
        if (howMany > 0 && last - first + 1 != howMany)
            bad = true;
    }
    if ((emptyLine && !emptyColumn) || (!emptyLine && emptyColumn))
        bad = true;
    if (bad)
        cout << "-1\n";
    else
        cout << components << "\n";
    return 0;
}