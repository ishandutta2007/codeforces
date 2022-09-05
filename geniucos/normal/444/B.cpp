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

int N, x, a[100009], b[100009], ans[200009], pos[100009];
unsigned int B[33][6000], C[7000];
char lg[(1<<18) + 1];

int GetNextX ()
{
    x = ((long long) 1LL * x * 37 + 10007) % 1000000007;
    return x;
}

void Read ()
{
    int d;
    scanf ("%d %d %d", &N, &d, &x);
    for (int i=0; i<N; i++)
        a[i] = i + 1;
    for (int i=0; i<N; i++)
        swap (a[i], a[GetNextX () % (i + 1)]);
    for (int i=0; i<N; i++)
        b[i] = (i < d);
    for (int i=0; i<N; i++)
        swap (b[i], b[GetNextX () % (i + 1)]);
}

void Update (int surp, int val, int msk)
{
    while (msk)
    {
        int bit = lg[msk - (msk & (msk - 1))];
        if (bit + surp < N) ans[bit + surp] = val;
        msk &= msk - 1;
    }
}

void Try (int pos, int val)
{
    int lin = pos & 31, sft = pos >> 5;
    for (int j=0; (j<<5) <= N + lin; j++)
    {
        int curr = B[lin][j];
        if ((C[j + sft] & curr) != curr)
        {
            unsigned int msk = curr ^ (curr & C[j + sft]);
            Update (((j + sft) << 5), val, msk & 32767);
            Update (((j + sft) << 5) + 15, val, msk >> 15);
            C[j + sft] |= curr;
        }
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
for (int i=0; i<N; i++)
{
    pos[a[i]] = i;
    if (b[i]) B[0][i>>5] |= 1<<(i & 31);
}

for (int i=1; i<32; i++)
{
    /////vreau sa precalculez cate ceva ca sa shiftez B cu oricate pozitii super eificent
    bool curr = 0;
    for (int j=0; (j << 5) <= N + i; j++)
    {
        bool ol = 0;
        if (B[i-1][j] & 2147483648) ol = 1, B[i][j] = ((B[i-1][j] ^ 2147483648) << 1);
        else B[i][j] = (B[i-1][j] << 1);
        if (curr) B[i][j] |= 1;
        curr = ol;
    }
}

for (int i=0; i<17; i++)
    lg[1<<i] = i;

for (int i=N; i>=1; i--)
    Try (pos[i], i);

for (int i=0; i<N; i++)
    printf ("%d\n", ans[i]);

return 0;
}