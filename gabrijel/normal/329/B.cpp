#include <bits/stdc++.h>
using namespace std;

int n, m, vr, rj = 0;
char mat [1005] [1005];
pair <int, int> poc;
pair <int, int> kr;
queue <pair <int, int> > q;
int dist [1005] [1005];
int smjx [] = {-1, 0, 1, 0};
int smjy [] = {0, 1, 0, -1};

inline bool moze (int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (dist [x] [y] != -1) return 0;
    if (mat [x] [y] == 'T') return 0;
    return 1;
}

void bfs (pair <int, int> par)
{
    pair <int, int> tr;
    pair <int, int> novi;
    memset(dist, -1, sizeof dist);
    dist [par.first] [par.second] = 0;
    q.push(par);
    while (!q.empty())
    {
        tr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            novi = make_pair(tr.first + smjx [i], tr.second + smjy [i]);
            if (moze (novi.first, novi.second))
            {
                dist [novi.first] [novi.second] = dist [tr.first] [tr.second] + 1;
                q.push(novi);
            }
        }
    }
}

void bfs2 (pair <int, int> par)
{
    pair <int, int> tr;
    pair <int, int> novi;
    memset(dist, -1, sizeof dist);
    dist [par.first] [par.second] = 0;
    q.push(par);
    while (!q.empty())
    {
        tr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            novi = make_pair(tr.first + smjx [i], tr.second + smjy [i]);
            if (moze (novi.first, novi.second))
            {
                dist [novi.first] [novi.second] = dist [tr.first] [tr.second] + 1;
                if (mat [novi.first] [novi.second] > '0' && mat [novi.first] [novi.second] <= '9' && dist [novi.first] [novi.second] <= vr) rj += mat [novi.first] [novi.second] - '0';
                q.push(novi);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", mat [i]);
        for (int j = 0; j < m; j++)
        {
            if (mat [i] [j] == 'S') poc = make_pair(i, j);
            if (mat [i] [j] == 'E') kr = make_pair(i, j);
        }
    }
    bfs (poc);
    vr = dist [kr.first] [kr.second];
    bfs2 (kr);
    printf("%d", rj);
    return 0;
}