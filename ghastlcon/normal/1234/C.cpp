#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#define N 200020
using namespace std;

class State
{
public:
    int k;
    int x;
    int y;

    State(void)
    {
        return;
    }

    State(int _k, int _x, int _y) : k(_k), x(_x), y(_y)
    {
        return;
    }
};

int n;
char a[3][N];
queue<State> q;
bool u[3][4][N];

void Check(int k, int x, int y)
{
    if(u[k][x][y])
        return;
    u[k][x][y] = true;
    q.push(State(k, x, y));

    return;
}

bool BFS(int x, int y)
{
    State s;
    int k;

    u[0][x][y] = true;
    while(!q.empty())
        q.pop();
    for(q.push(State(0, x, y)); !q.empty(); q.pop())
    {
        s = q.front();
        if(s.y == n + 1)
        {
            if(s.x == 2)
                return true;
            continue;
        }
        if(s.x < 1 || s.x > 2)
            continue;
        x = s.x;
        y = s.y;
        k = s.k;

        if(a[x][y] == '1' || a[x][y] == '2')
        {
            if(k != 0)
                continue;
            Check(0, x, y + 1);
        }
        else
        {
            if(k == 0)
            {
                Check(1, x + 1, y);
                Check(2, x - 1, y);
            }
            else
                Check(0, x, y + 1);
        }
    }

    return false;
}

int main(void)
{
    int t;
    int i;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %s %s", &n, a[1] + 1, a[2] + 1);
        for(i = 0; i <= n + 1; i ++)
        {
            u[0][0][i] = u[0][1][i] = u[0][2][i] = u[0][3][i] = false;
            u[1][0][i] = u[1][1][i] = u[1][2][i] = u[1][3][i] = false;
            u[2][0][i] = u[2][1][i] = u[2][2][i] = u[2][3][i] = false;
        }
        printf("%s\n", BFS(1, 1) ? "YES" : "NO");
    }

    return 0;
}