#include<bits/stdc++.h>

using namespace std;

int cnt, N, a[4][109], toX[409], toY[409];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector < pair < int, pair < int, int > > > ans;

void print ()
{
    printf ("%d\n", ans.size ());
    for (auto curr : ans)
        printf ("%d %d %d\n", curr.first, curr.second.first + 1, curr.second.second);
}

void performMove (int id, int i, int j)
{
//    printf ("%d %d %d\n", id, i + 1, j);
    ans.push_back ({id, {i, j}});
}

pair < int, int > findEmptyNeighbor (int i, int j)
{
    for (int k=0; k<4; k++)
        if (a[i + dx[k]][j + dy[k]] == 0 && 0 < i + dx[k] && i + dx[k] < 3 && 1 <= j + dy[k] && j + dy[k] <= N)
            return {i + dx[k], j + dy[k]};
    return {-1, -1};
}

void swapCells (int i, int j, int x, int y)
{
    if (a[i][j] != 0)
        swap (i, x), swap (j, y);
    assert (a[i][j] == 0 && a[x][y] != 0);
    performMove (a[x][y], i, j);
    swap (a[i][j], a[x][y]);
}

void changeLine (int x, int y)
{
    if (a[3 - x][y] == 0) swapCells (x, y, 3 - x, y);
    else
    {
        for (int k=-1; k<=1; k+=2)
            if (1 <= y + k && y + k <= N && (a[x][y + k] == 0 || a[3 - x][y + k] == 0))
            {
                if (a[3 - x][y + k] != 0)
                    swapCells (x, y + k, 3 - x, y + k);
                swapCells (3 - x, y + k, 3 - x, y);
                swapCells (3 - x, y, x, y);
                break;
            }
    }
}

void changeColumn (int x, int y, int dir)
{
    if (a[x][y + dir] == 0) swapCells (x, y, x, y + dir);
    else
    {
        vector < pair < int, int > > curr = {{x, y - dir}, {3 - x, y - dir}, {3 - x, y}, {3 - x, y + dir}, {x, y + dir}};
        for (int i=4; i>=0; i--)
            if (a[curr[i].first][curr[i].second] == 0)
            {
                for (int j=i; j<4; j++)
                    swapCells (curr[j].first, curr[j].second, curr[j + 1].first, curr[j + 1].second);
                break;
            }
        swapCells (x, y, x, y + dir);
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &cnt);
for (int i=0; i<4; i++)
    for (int j=1; j<=N; j++)
    {
        scanf ("%d", &a[i][j]);
        if (i == 0 || i == 3)
            toX[a[i][j]] = i, toY[a[i][j]] = j;
    }
if (cnt == 2 * N)
{
    for (int i=1; i<=2; i++)
        for (int j=1; j<=N; j++)
            if (a[i][j] == a[i ^ 1][j])
                performMove (a[i][j], i ^ 1, j), a[i][j] = a[i ^ 1][j] = 0, cnt --;
    if (ans.empty ())
    {
        printf ("-1\n");
        return 0;
    }
}
while (cnt > 0)
{
    int x = -1, y = -1;
    for (int i=1; i<=2; i++)
        for (int j=1; j<=N; j++)
            if (a[i][j] != 0)
            {
                auto curr = findEmptyNeighbor (i, j);
                if (curr.first != -1)
                {
                    x = i, y = j;
                    i = 4; break;
                }
            }
    if (x != (toX[a[x][y]] ^1))
        changeLine (x, y), x = 3 - x;
    while (y != toY[a[x][y]])
    {
        if (y < toY[a[x][y]]) changeColumn (x, y, +1), y ++;
        else changeColumn (x, y, -1), y --;
    }
    performMove (a[x][y], x ^ 1, y);
    a[x][y] = a[x ^ 1][y] = 0, cnt --;
}
print ();
return 0;
}