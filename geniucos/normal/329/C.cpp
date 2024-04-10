#include<cstdio>
#include<algorithm>
using namespace std;
/////valori pentru solutie
int n, m, muc[100009][3], v[100009];

void add_vec (int x, int y)
{
    muc [ x ] [++ muc [ x ] [ 0 ] ] = y;
}

bool muchie (int x, int y)
{
    if (x>y) return muchie (y, x);
    for (int i=0; i<=muc[x][0]; i++)
        if (muc[x][i] == y) return 1;
    return 0;
}

/////valori pentru back
int nr, x[20], y[20], ap[20], fin;

void back (int poz)
{
    if (fin) return ;
    if (poz == nr + 1)
    {
        int deg[10], nm=0;
        for (int i=1; i<=n; i++)
            deg[i] = 0;
        for (int i=1; i<=nr; i++)
            if (ap[i] == 1)
            {
                deg[x[i]]++;
                deg[y[i]]++;
                nm++;
            }
        if (nm != m) return;
        for (int i=1; i<=n; i++)
            if (deg[i]>2) return ;
        fin = 1;
        for (int i=1; i<=nr; i++)
            if (ap[i]) printf ("%d %d\n", x[i], y[i]);
        return;
    }
    back (poz+1);
    ap[poz] = 1;
    back (poz+1);
    ap[poz] = 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d", &n);
scanf ("%d", &m);
if (n<=6)
{
    bool ap[30][30];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            ap[i][j] = 0;

    for (int i=1; i<=m; i++)
    {
        int x, y;
        scanf ("%d%d", &x, &y);
        ap[x][y]=ap[y][x]=1;
    }

    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            if (ap[i][j] == 0)
            {
                nr++;
                x[nr] = i;
                y[nr] = j;
            }

    fin = 0;
    back (1);
    if (fin == 0) printf ("-1\n");
    return 0;
}

for (int i=1; i<=m; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    if (x<y) add_vec(x, y);
    else add_vec(y, x);
}

for (int i=1; i<=n; i++)
    v[i] = i;
v[n+1] = 1;

for (int i=1; i<=n; i++)
    if (muchie (v[i], v[i+1]))
    {
        int j;
        for (j=i+2; j<=n; j++)
            if (muchie (v[i], v[j]) == 0) break;
        if (j<=n)
        {
            reverse (v+i+1, v+j+1);
            continue;
        }
        for (j=i-1; j>1; j--)
            if (muchie (v[i+1], v[j]) == 0 && muchie (v[i], v[j-1]) == 0) break;
        reverse (v+j, v+i+1);
    }

for (int i=1; i<=m; i++)
    printf ("%d %d\n", v[i], v[i+1]);
return 0;
}