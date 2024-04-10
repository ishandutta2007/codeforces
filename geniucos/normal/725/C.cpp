#include<bits/stdc++.h>

using namespace std;

int p1, p2, a[30], b[30], N, M, mat[30][30], nr, cod[3][40], ap[300];
char sir[100], ans[3][100], c;
bool deja = 0;

/*vector < pair < int, int > > ans[30][30];

bool ok (int x, int y){return (1<=x&&x<=2&&1<=y&&y<=M);}

void back (int pos, int x, int y)
{
    if (pos == 1)
        pos = 1;
    if (pos == 28)
    {
        for (int i=1; i<pos; i++)
            for (int j=i+1; j<pos; j++)
                if (cod[a[i]][b[i]] == cod[a[j]][b[j]])
                {
                    int p = i, q = j;
                    if (ans[p][q].empty ())
                    {
                        for (int k=1; k<pos; k++)
                            ans[p][q].push_back (make_pair (a[k], b[k]));
                    }
                    i = pos; break;
                }
        return ;
    }
    a[pos] = x, b[pos] = y;
    int x2 = x, y2 = y + 1;
    if (ok (x2, y2) && ap[cod[x2][y2]] <= 1 - deja)
    {
        if (ap[cod[x2][y2]] == 1) deja = 1;
        ap[cod[x2][y2]] ++;
        back (pos + 1, x2, y2);
        ap[cod[x2][y2]] --;
        if (ap[cod[x2][y2]] == 1) deja = 0;
    }
    x2 = 3 - x2;
    if (ok (x2, y2) && ap[cod[x2][y2]] <= 1 - deja)
    {
        if (ap[cod[x2][y2]] == 1) deja = 1;
        ap[cod[x2][y2]] ++;
        back (pos + 1, x2, y2);
        ap[cod[x2][y2]] --;
        if (ap[cod[x2][y2]] == 1) deja = 0;
    }
    y2 --;
    if (ok (x2, y2) && ap[cod[x2][y2]] <= 1 - deja)
    {
        if (ap[cod[x2][y2]] == 1) deja = 1;
        ap[cod[x2][y2]] ++;
        back (pos + 1, x2, y2);
        ap[cod[x2][y2]] --;
        if (ap[cod[x2][y2]] == 1) deja = 0;
    }
    y2 --;
    if (ok (x2, y2) && ap[cod[x2][y2]] <= 1 - deja)
    {
        if (ap[cod[x2][y2]] == 1) deja = 1;
        ap[cod[x2][y2]] ++;
        back (pos + 1, x2, y2);
        ap[cod[x2][y2]] --;
        if (ap[cod[x2][y2]] == 1) deja = 0;
    }
    x2 = 3-x2;
    if (ok (x2, y2) && ap[cod[x2][y2]] <= 1 - deja)
    {
        if (ap[cod[x2][y2]] == 1) deja = 1;
        ap[cod[x2][y2]] ++;
        back (pos + 1, x2, y2);
        ap[cod[x2][y2]] --;
        if (ap[cod[x2][y2]] == 1) deja = 0;
    }
}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*M = 13;
for (int i=1; i<=2; i++)
    for (int j=1; j<=M; j++)
        cod[i][j] = ++nr;
for (int i=1; i<=M; i++)
    ap[cod[1][i]] = 1, back (1, 1, i), ap[cod[1][i]] = 0;*/

gets (sir + 1), N = 27, M = 13;
for (int i=1; i<=N; i++)
    ap[sir[i]] ++;
for (int i=N + 1; i<=2 * N; i++)
    sir[i] = sir[i - N];
for (int i='A'; i<='Z'; i++)
    if (ap[i] == 0 || ap[i] > 2)
    {
        printf ("Impossible\n");
        return 0;
    }
    else
    if (ap[i] == 2) c = i;
for (int i=1; i<=N; i++)
    if (sir[i] == c)
    {
        if (p1 == 0) p1 = i;
        else p2 = i;
    }
if (p1 % 2 == p2 % 2)
{
    int J = (p2 - p1) / 2, pos = p1 - 1;
    for (int j=J; j>=1; j--)
        ans[1][j] = sir[++pos];
    for (int j=1; j<=J; j++)
        ans[2][j] = sir[++pos];
    pos ++;
    for (int j=J + 1; j<=M; j++)
        ans[1][j] = sir[++pos];
    for (int j=M; j>J; j--)
        ans[2][j] = sir[++pos];
}
else
if (p1 != p2 - 1)
{
    int J = (p2 - p1) / 2 + 1, pos = p1 - 1;
    for (int j=J; j>=1; j--)
        ans[1][j] = sir[++pos];
    for (int j=1; j<J; j++)
        ans[2][j] = sir[++pos];
    pos ++;
    ans[2][J] = sir[++pos];
    for (int j=J + 1; j<=M; j++)
        ans[2][j] = sir[++pos];
    for (int j=M; j>J; j--)
        ans[1][j] = sir[++pos];
}
else
{
    printf ("Impossible\n");
    return 0;
}
for (int i=1; i<=2; i++, printf ("\n"))
    for (int j=1; j<=M; j++)
        printf ("%c", ans[i][j]);
/*for (int i=1; i<=27; i++)
    for (int j=i+1; j<=27; j++)
        if (!ans[i][j].empty ())
        {
            printf ("%d %d:\n", i, j);
            for (int k=0; k<27; k++)
                mat[ans[i][j][k].first][ans[i][j][k].second] = k;
            for (int k=1; k<3; k++, printf ("\n"))
                for (int p=1; p<=M; p++)
                    printf ("%2d ", mat[k][p]);
            printf ("\n");
        }*/
return 0;
}