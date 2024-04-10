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

int N, M, tip[100009], ans[100009], x[100009], y[100009], len[100009];
int aib_N[2], aib_M[2], aib[2][5009][10009];

void set_size (int lin, int n, int m)
{
    aib_N[lin] = n;
    aib_M[lin] = m;
}

void Update (int lin, int p1, int p2, int val)
{
    /*if (val < 0) printf ("%d la aibul %d, coordonate %d %d\n", val, lin, p1, p2);
    else printf ("+%d la aibul %d, coordonate %d %d\n", val, lin, p1, p2);*/
    for (int i=p1; i<=aib_N[lin]; i += i - (i & (i - 1)))
        for (int j=p2; j<=aib_M[lin]; j += j - (j & (j - 1)))
            aib[lin][i][j] += val;
}

int Query (int lin, int p1, int p2)
{
    int ans = 0;
    for (int i=p1; i>=1; i &= i-1)
        for(int j=p2; j>=1; j &= j-1)
            ans += aib[lin][i][j];
    //printf ("Query la aib %d, coordonate %d %d -> %d\n", lin, p1, p2, ans);
    return ans;
}

void Clear (int lin)
{
    memset (aib[lin], 0, sizeof (aib[lin]));
    aib_N[lin] = aib_M[lin] = 0;
}
//int old[5009][5009], mat[5009][5009];
void Rotate_Right ()
{
    for (int i=1; i<=M; i++)
    {
        int a = x[i], b = y[i];
        x[i] = b, y[i] = N - a + 1;
    }
/*    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            old[i][j] = mat[i][j];
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            mat[j][N - i + 1] = old[i][j];*/
}

void Proces_Queries (int wanted_type)
{
    set_size (0, N, N + 1), set_size (1, N, 2 * N + 1);
    for (int i=1; i<=M; i++)
    {
        if (tip[i] == wanted_type)
        {
            Update (0, x[i], y[i], 1);
            Update (0, x[i] + len[i] + 1, y[i], -1);
            Update (1, x[i], x[i] + y[i] + len[i] + 1, -1);
            Update (1, x[i] + len[i] + 1, x[i] + y[i] + len[i] + 1, 1);
/*            for (int j=x[i]; j<=x[i]+len[i]; j++)
                for (int k=y[i]; k+j<=x[i]+y[i]+len[i]; k++)
                    mat[j][k] ++;*/
        }
        else
        if (tip[i] == 6)
        {
            int curr = Query (0, x[i], y[i]) + Query (1, x[i], x[i] + y[i]);
            //if (curr != mat[x[i]][y[i]])
              //  printf ("when I wanted %d at %dth query we've got a wrong value\n", wanted_type, i), printf ("corect value %d, returned value %d\n", mat[x[i]][y[i]], curr);
            ans[i] += curr;
        }
    }
/*    for (int i=1; i<=N; i++, printf ("\n"))
        for (int j=1; j<=N; j++)
            printf ("%2d ", mat[i][j]), mat[i][j] = 0;
    for (int i=1; i<=M; i++)
        if (tip[i] == 6) printf ("%d ", ans[i]);
    printf ("\n\n");*/
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), set_size (0, N, N);
for (int i=1; i<=M; i++)
{
    int T;
    scanf ("%d", &T);
    if (T == 1)
    {
        scanf ("%d %d %d %d", &tip[i], &x[i], &y[i], &len[i]);
        if (len[i] == 0)
        {
            tip[i] = 5;
            aib[0][x[i]][y[i]] ++;
        }
    }
    else
    {
        tip[i] = 6;
        scanf ("%d %d", &x[i], &y[i]);
        ans[i] = aib[0][x[i]][y[i]];
    }
}
Clear (0);

Proces_Queries (1);
Rotate_Right (), Clear (0), Clear (1);
Proces_Queries (3);
Rotate_Right (), Clear (0), Clear (1);
Proces_Queries (4);
Rotate_Right (), Clear (0), Clear (1);
Proces_Queries (2);

for (int i=1; i<=M; i++)
    if (tip[i] == 6)
        printf ("%d\n", ans[i]);

return 0;
}