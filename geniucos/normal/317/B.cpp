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

int N, Q, a[309][309], ap[309][309];
queue < pair < int , int > > cc;

void try_add (int x, int y)
{
    if (a[x][y] >= 4 && ap[x][y] == 0)
        ap[x][y] = 1, cc.push (make_pair (x, y));
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);

a[150][150] = N;
ap[150][150] = 1;
cc.push (make_pair (150, 150));
while (!cc.empty ())
{
    pair < int , int > curr = cc.front ();
    cc.pop();
    int X = curr.first, Y = curr.second;
    ap[X][Y] = 0;
    if (a[X][Y] < 4)
        continue;
    a[X-1][Y] += a[X][Y] >> 2, try_add (X - 1, Y);
    a[X+1][Y] += a[X][Y] >> 2, try_add (X + 1, Y);
    a[X][Y+1] += a[X][Y] >> 2, try_add (X, Y + 1);
    a[X][Y-1] += a[X][Y] >> 2, try_add (X, Y - 1);
    a[X][Y] &= 3;
}

int mini = 10000, minj = 10000, maxi = -10000, maxj = -10000;
for (int i=1; i<300; i++)
    for (int j=1; j<300; j++)
    if (a[i][j])
    {
        if (i > maxi)
            maxi = i;
        if (i < mini)
            mini = i;
        if (j > maxj)
            maxj = j;
        if (j < minj)
            minj = j;
    }

/*for (int i=mini; i<=maxi; i++, printf ("\n"))
    for (int j=minj; j<=maxj; j++)
        printf ("%d", a[i][j]);*/

scanf ("%d", &Q);
while (Q)
{
    Q --;
    int x, y;
    scanf ("%d %d", &x, &y);
    x += 150, y += 150;
    if (x >= mini && x <= maxi && y >= minj && y <= maxj)
        printf ("%d\n", a[x][y]);
    else
        printf ("0\n");
}

return 0;
}