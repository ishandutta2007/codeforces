#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int pos, buc, lg, mod1, mod2, N, cof[200009];
pair < int , int > val1[200009], val2[200009];
char A[200009], B[200009];
string curr;

pair < int , int > get_hash ()
{
    int p1 = 0, p2 = 0;
    for (int i=0; i<buc; i++)
    {
        p1 = ((long long) p1 + 1LL * cof[i] * curr[i]) % mod1;
        p2 = ((long long) p2 + 1LL * cof[i] * curr[i]) % mod2;
    }
    return make_pair (p1, p2);
}

int val (pair < int, int > hsh)
{
    return ((long long)hsh.first + 1LL * 2 * hsh.second) % mod1;
}

int get1 (int st, int dr, int dp)
{
    if ((dr - st + 1) & 1)
        return val (val1[(st-1)/buc]);
    int mij = (st + dr) >> 1, v1, v2;
    v1 = get1 (st, mij, dp + 1);
    v2 = get1 (mij + 1, dr, dp + 1);
    if (v1 > v2)
        swap (v1, v2);
    //printf ("la 1 pe [%d, %d] am %d\n", st, dr, (1LL * cof[0] * v1 + 1LL * dp * v2) % mod1);
    return (1LL * cof[0] * v1 + 1LL * dp * v2) % mod1;
}

int get2 (int st, int dr, int dp)
{
    if ((dr - st + 1) & 1)
        return val (val2[(st-1)/buc]);
    int mij = (st + dr) >> 1, v1, v2;
    v1 = get2 (st, mij, dp + 1);
    v2 = get2 (mij + 1, dr, dp + 1);
    if (v1 > v2)
        swap (v1, v2);
    //printf ("la 2 pe [%d, %d] am %d\n", st, dr, (1LL * cof[0] * v1 + 1LL * dp * v2) % mod1);
    return (1LL * cof[0] * v1 + 1LL * dp * v2) % mod1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (A + 1), N = strlen (A + 1);
gets (B + 1);

for (int i=0; (1<<i) <= N; i++)
    if ((N % (1<<i)) == 0)
        lg = i;
buc = N / (1<<lg);
srand (time (0));
mod1 = 1e9 + 7;
mod2 = 1e9 + 9;
for (int i=0; i<buc; i++)
    cof[i] = rand () % (mod1 - 1) + 1;

for (int i=1; i<=N; i+=buc)
{
    curr.clear ();
    for (int j=i; j<=i+buc-1; j++)
        curr += A[j];
    val1[pos++] = get_hash ();
}
pos = 0;
for (int i=1; i<=N; i+=buc)
{
    curr.clear ();
    for (int j=i; j<=i+buc-1; j++)
        curr += B[j];
    val2[pos++] = get_hash ();
}
int v1 = get1 (1, N, 100);
int v2 = get2 (1, N, 100);
if (v1 == v2)
{
    printf ("YES\n");
    return 0;
}
printf ("NO\n");
return 0;
}