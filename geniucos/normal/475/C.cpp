#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int OKKK, h, L, n, m, l1, l2, X, Y, L1, L2, mini, ap[1009][1009], a[1009][1009];
char sir[1009];

int mod (int x)
{
    if (x<0) return -x;
    return x;
}

bool ok (int c1, int c2, int c3, int c4)
{
    if (c1*c2*c3*c4 == 1) return 1;
    if (c1+c2+c3+c4 == 0) return 1;
    if (c1 + c2 + c3 + c4 == 1) return 1;
    if (c1 + c2 + c3 + c4 == 2)
    {
        if (c1*c4 || c2*c3) return 0;
        return 1;
    }
    ////acum sunt la 3
    if (c4 == 0 || c1 == 0) return 0;
    return 1;
}

int merg (int x, int y, int d1, int d2)
{
    int nr=0;
    while (1)
    {
        nr += a[x][y];
        x+=d1;
        y+=d2;
        if (a[x][y] == 0) break;
    }
    return nr;
}

void dfs (int i, int j)
{
    if (a[i][j] == 0||ap[i][j]) return ;
    ap[i][j]=1;
    dfs (i+1, j);
    dfs (i-1, j);
    dfs (i, j+1);
    dfs (i, j-1);
}

void fill (int a1, int b1, int a2, int b2, int v)
{
    for (int i=a1; i<=a2; i++)
        for (int j=b1; j<=b2; j++)
            ap[i][j] = v;
}

void solve (int X, int Y, int l1, int l2)
{
    //if (X==3&&Y==1&&l1==2&&l2==2)
        //l1=2;
    if (a[X+l1][Y] && a[X][Y+l2])
    {
        OKKK = 1;
        return ;
    }
    if (a[X+l1][Y])
    {
        fill (X+l1, Y, X+l1, Y+l2-1, 1);
        solve (X+1, Y, l1, l2);
    }
    if (a[X][Y+l2])
    {
        fill (X, Y+l2, X+l1-1, Y+l2, 1);
        solve (X, Y+1, l1, l2);
    }
}

bool merge (int l1, int l2)
{
    fill(1,1,n,m,0);
    fill(X, Y, X+l1-1, Y+l2-1, 1);
    OKKK = 0;
    solve (X, Y, l1, l2);
    if (OKKK == 1) return 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (ap[i][j] == 0 && a[i][j] == 1)
                return 0;
    if (l1*l2<mini)
        mini = l1*l2;
    return 1;
}

void Try (int l1, int l2)
{
    if (l1 == 0)
    {
        int i;
        for (i=X; i<=n; i++)
            if (a[i][Y+l2]) break;
        if (i == n+1) merge (1, L2);
        else
        {
            h = X + L1 - 1 - i + 1;
            merge (h, l2);
        }
    }
    if (l2 == 0)
    {
        int j;
        for (j=Y; j<=m; j++)
            if (a[X+l1][j]) break;
        if (j==m+1)
            merge (L1, 1);
        else
        {
            L=Y+L2-1-j+1;
            merge (l1, L);
        }
    }
}

int main()
{

//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d %d\n", &n, &m);
mini = n*m+1;
for (int i=1; i<=n; i++)
{
    gets (sir+1);
    for (int j=1; j<=m; j++)
        a[i][j] = (sir[j] == 'X');
}

for (int i=1; i<n; i++)
    for (int j=1; j<m; j++)
    {
        if (!ok(a[i][j], a[i][j+1], a[i+1][j], a[i+1][j+1]))
        {
            printf ("-1\n");
            return 0;
        }
    }
for (int i=1; i<=n; i++)
{
    for (int j=1; j<=m; j++)
        if (a[i][j])
        {
            X=i;
            Y=j;
            break;
        }
    if (X!=0) break;
}
if (X==0)
{
    printf ("0\n");
    return 0;
}
dfs (X, Y);
for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        if (ap[i][j] == 0 && a[i][j] == 1)
        {
            printf ("-1\n");
            return 0;
        }
L1 = l1 = merg (X, Y, 1, 0);
L2 = l2 = merg (X, Y, 0, 1);
/////ori are inaltimea l1, ori lungimea l2
Try(l1, 0);
Try(0, l2);
if (mini == n*m+1)
{
    printf ("-1\n");
    return 0;
}
printf ("%d\n", mini);
return 0;
}