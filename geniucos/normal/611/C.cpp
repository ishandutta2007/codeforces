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

int N, M, Q;
char mat[509][509];

class matrix
{
    public:
    int N, M, a[509][509], s[509][509];
    void fix (int i, int j, int val)
    {
        a[i][j] = val;
    }
    void run ()
    {
        for (int i=0; i<=N; i++)
            for (int j=0; j<=M; j++)
                s[i][j] = 0;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
/*        for (int i=1; i<=N; i++, printf ("\n"))
            for (int j=1; j<=M; j++)
                printf ("%d", a[i][j]);*/
    }
    int query (int a1, int b1, int a2, int b2)
    {
        if (a1 > a2 || b1 > b2) return 0;
        return s[a2][b2] - s[a1 - 1][b2] - s[a2][b1 - 1] + s[a1 - 1][b1 - 1];
    }
}mat1, mat2;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (mat[i] + 1);
mat1.N = N - 1, mat1.M = M;
mat2.N = N, mat2.M = M - 1;
for (int i=1; i<N; i++)
    for (int j=1; j<=M; j++)
    {
        int curr = 0;
        if (mat[i][j] == '.' && mat[i + 1][j] == '.') curr = 1;
        mat1.fix (i, j, curr);
    }
for (int i=1; i<=N; i++)
    for (int j=1; j<M; j++)
    {
        int curr = 0;
        if (mat[i][j] == '.' && mat[i][j + 1] == '.') curr = 1;
        mat2.fix (i, j, curr);
    }
mat1.run (), mat2.run ();
scanf ("%d", &Q);
while (Q --)
{
    int a1, b1, a2, b2;
    scanf ("%d %d %d %d", &a1, &b1, &a2, &b2);
    int sol = mat1.query (a1, b1, a2 - 1, b2) + mat2.query (a1, b1, a2, b2 - 1);
    printf ("%d\n", sol);
}
return 0;
}