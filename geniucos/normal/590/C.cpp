#include<cstdio>
#include<bitset>
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

int M, nr, N, Nr, ap[1009][1009], cod[1009][1009], d[4][1009][1009];
char sir[1009][1009];
queue < pair < int , int > > cc;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fll (int i, int j, int val)
{
    if (sir[i][j] < '1' || sir[i][j] > '3' || ap[i][j] || cod[i][j] == 0) return ;
    ap[i][j] = val;
    fll (i + 1, j, val);
    fll (i - 1, j, val);
    fll (i, j + 1, val);
    fll (i, j - 1, val);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] != '#') cod[i][j] = ++nr;//, X[nr] = i, Y[nr] = j;
/*for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (cod[i][j])
        {
            for (int k=0; k<4; k++)
                if (cod[i + dx[k]][j + dy[k]])
                    v[cod[i][j]].push_back (cod[i + dx[k]][j + dy[k]);
        }*/
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] >= '1' && sir[i][j] <= '3' && ap[i][j] == 0)
        {
            Nr ++;
            fll (i, j, Nr);
        }

if (Nr == 1)
{
    printf ("0\n");
    return 0;
}

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] >= '1' && sir[i][j] <= '3') sir[i][j] = ap[i][j];

for (int val=1; val<=Nr; val++)
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
        {
            ap[i][j] = 0, d[val][i][j] = 1000001;
            if (sir[i][j] == val)
                cc.push (make_pair (i, j)), d[val][i][j] = 0;
        }
    while (!cc.empty ())
    {
        pair < int , int > curr = cc.front ();
        cc.pop ();
        for (int k=0; k<4; k++)
            if (cod[curr.first + dx[k]][curr.second + dy[k]] && d[val][curr.first + dx[k]][curr.second + dy[k]] > d[val][curr.first][curr.second] + 1)
            {
                d[val][curr.first + dx[k]][curr.second + dy[k]] = d[val][curr.first][curr.second] + 1;
                cc.push (make_pair (curr.first + dx[k], curr.second + dy[k]));
            }
    }
}
int mini = 1000001;
if (Nr == 2)
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (sir[i][j] == 1 && d[2][i][j] - 1 < mini)
                mini = d[2][i][j] - 1;
}
if (Nr == 3)
{
    int min1 = 1000001, min2 = 1000001, min3 = 1000001;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (sir[i][j] == 1 && d[2][i][j] - 1 < min1)
                min1 = d[2][i][j] - 1;

    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (sir[i][j] == 1 && d[3][i][j] - 1 < min2)
                min2 = d[3][i][j] - 1;

    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if (sir[i][j] == 2 && d[3][i][j] - 1 < min3)
                min3 = d[3][i][j] - 1;
    if (min1 + min2 < mini) mini = min1 + min2;
    if (min1 + min3 < mini) mini = min1 + min3;
    if (min2 + min3 < mini) mini = min2 + min3;
}
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '.')
        {
            int cost = 0;
            for (int val = 1; val <= Nr; val ++)
                cost += d[val][i][j];
            cost -= (Nr - 1);
            if (cost < mini) mini = cost;
        }

if (mini >= 1000001 - 5) printf ("-1\n");
else printf ("%d\n", mini);

return 0;
}