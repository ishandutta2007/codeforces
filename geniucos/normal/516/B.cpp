#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, nr[2014][2014];
char sir[2014][2014];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

queue < pair < int,  int > > cc;

void FIX (int i, int j, int ik, int jk)
{
    if (j == jk)
    {
        if (i < ik) sir[i][j] = '^', sir[ik][j] = 'v';
        else sir[i][j] = 'v', sir[ik][j] = '^';
    }
    else
    {
        if (j < jk) sir[i][j] = '<', sir[i][jk] = '>';
        else sir[i][j] = '>', sir[i][jk] = '<';
    }
}

void refresh (int i, int j)
{
    for (int k=0; k<4; k++)
        if (sir[i+dx[k]][j+dy[k]] == '.')
        {
            nr[i+dx[k]][j+dy[k]] ++;
            if (nr[i+dx[k]][j+dy[k]] == 3)
                cc.push(make_pair (i + dx[k], j + dy[k]));
        }
}

void finish_it ()
{
    for (int i=1; i<=N; i++, printf ("\n"))
        for (int j=1; j<=M; j++)
            printf ("%c", sir[i][j]);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
{
    gets (sir[i] + 1);
    sir[i][0] = '*';
    sir[i][M + 1] = '*';
}

for (int j=1; j<=M; j++)
    sir[0][j] = sir[N+1][j] = '*';

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    if (sir[i][j] == '.')
    {
        for (int k=0; k<4; k++)
            if (sir[i+dx[k]][j+dy[k]] == '*')
                nr[i][j] ++;

        if (nr[i][j] == 4)
        {
            printf ("Not unique\n");
            return 0;
        }

        if (nr[i][j] == 3)
            cc.push(make_pair (i, j));
    }

while (!cc.empty())
{
    pair < int, int > xx = cc.front();
    cc.pop();
    int i, j;
    i = xx.first;
    j = xx.second;
    //printf ("%d %d\n", i, j);

    if (nr[i][j] == 4 && sir[i][j] == '.')
    {
        printf ("Not unique\n");
        return 0;
    }

    if (sir[i][j] != '.' || nr[i][j] != 3)
        continue;

    int xk, yk;
    for (int k=0; k<4; k++)
        if (sir[i+dx[k]][j+dy[k]] == '.')
            xk = i + dx[k], yk = j + dy[k];

    FIX (i, j, xk, yk);

    refresh (i, j);
    refresh (xk, yk);

    //finish_it ();
    //printf ("\n\n");
}

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '.')
        {
            printf ("Not unique\n");
            return 0;
        }

finish_it ();

return 0;
}