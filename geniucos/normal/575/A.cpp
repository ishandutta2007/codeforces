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
//#define int long long

using namespace std;

int N, M, P, mod, S[200009];
long long K, pos;
map < long long , int > Special_S;
pair < long long , int > wr[100009];

struct mat
{
    int a[3][3];
}arb[400009], ANS, tot, SOL;

mat inm (mat a, mat b)
{
    mat ans;
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
        {
            ans.a[i][j] = 0;
            for (int k=0; k<2; k++)
                ans.a[i][j] = ((long long)ans.a[i][j] + 1LL * a.a[i][k] * b.a[k][j]) % mod;
        }
    return ans;
}

mat pow (mat a, long long B)
{
    mat ans;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            ans.a[i][j] = 0;
    ans.a[0][0] = ans.a[1][1] = 1;
    for (int i=0; (1LL<<i) <= B; i++)
    {
        if (B & (1LL<<i)) ans = inm (ans, a);
        a = inm (a, a);
    }
    return ans;
}

mat muta (mat curr, long long pos, bool pasa)
{
    int V1, V2;
    if (pasa)
    {
        if (Special_S.count (pos - 1)) V2 = Special_S[pos - 1];
        else V2 = S[(pos - 1) % N];

        if (Special_S.count (pos - 2)) V1 = Special_S[pos - 2];
        else V1 = S[(pos - 2) % N];
    }
    else V2 = S[(pos - 1 + N) % N], V1 = S[(pos - 2 + N) % N];
    mat trans;
    trans.a[0][0] = 0, trans.a[1][0] = 1, trans.a[0][1] = V1, trans.a[1][1] = V2;
    curr = inm (curr, trans);
    return curr;
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st)
            ANS = arb[nod];
        else
        {
            //mat trans;
            //trans.a[0][0] = 0, trans.a[0][1] = S[st - 3], trans.a[1][0] = 1, trans.a[1][1] = S[st - 2];
            //ANS = inm (ANS, trans);
//            ANS = muta (ANS, S[st - 3], S[st - 2]);
//            trans.a[0][0] = 0, trans.a[0][1] = S[st - 2], trans.a[1][0] = 1, trans.a[1][1] = S[st - 1];
  //          ANS = inm (ANS, trans);
            ANS = muta (ANS, st - 1, 0);
            ANS = inm (ANS, arb[nod]);
        }
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij) Query (nod<<1, st, mij, x, y);
    if (y > mij) Query ((nod<<1) + 1, mij + 1, dr, x, y);
}

mat GetTransition (long long Left, long long Right)
{
    mat ans;
    long long P1, P2;
    if (Left % N == N - 1) P1 = Left;
    else P1 = Left - Left % N + N - 1;
    P2 = Right - Right % N;
    if (P1 > P2)
    {
        if (Left % N <= Right % N) Query (1, 1, 2 * N, Left % N + 1, Right % N + 1);
        else Query (1, 1, 2 * N, Left % N + 1, Right % N + 1 + N);
        return ANS;
    }
    if (P1 == P2 - 1)
    {
        Query (1, 1, 2 * N, Left % N + 1, Right % N + 1 + N);
        return ANS;
    }
    mat big_trans = pow (tot, (long long) (P2 - P1 - 1) / N);
    Query (1, 1, 2 * N, Left % N + 1, N + 1), ans = ANS;
    //ans = muta (ans, P1, 0);
    ans = inm (ans, big_trans);
    Query (1, 1, 2 * N, 1, Right % N + 1), ans = inm (ans, ANS);
    return ans;
}

void afis (mat a)
{
    printf ("%d %d\n%d %d\n\n", a.a[0][0], a.a[0][1], a.a[1][0], a.a[1][1]);
}

mat brut (long long st, long long dr, bool pasa)
{
    mat ans;
    ans.a[0][0] = ans.a[1][1] = 1;
    ans.a[0][1] = ans.a[1][0] = 0;
    for (long long p = st + 1; p<=dr; p++)
        ans = muta (ans, p, pasa);
    return ans;
}

void Try_Finish ()
{
    if (K - pos <= 100)
    {
        for (long long i = pos + 1; i<=K; i++)
            SOL = muta (SOL, i, 1);
        printf ("%d\n", SOL.a[1][1]);
        exit (0);
    }
}

void build (int nod, int st, int dr)
{
    if (st == dr)
    {
        arb[nod].a[0][0] = arb[nod].a[1][1] = 1;
        arb[nod].a[0][1] = arb[nod].a[1][0] = 0;
        return ;
    }
    int mij = (st + dr) >> 1;
    build (nod<<1, st, mij);
    build ((nod<<1) + 1, mij + 1, dr);

    //mat trans;
    //trans.a[0][0] = 0, trans.a[0][1] = S[mij - 2], trans.a[1][0] = 1, trans.a[1][1] = S[mij - 1];
    //arb[nod] = inm (arb[nod], trans);
    arb[nod] = muta (arb[nod << 1], mij, 0);
//    trans.a[0][0] = 0, trans.a[0][1] = S[mij - 1], trans.a[1][0] = 1, trans.a[1][1] = S[mij];
  //  arb[nod] = inm (arb[nod], trans);
    arb[nod] = inm (arb[nod], arb[(nod<<1) + 1]);

  /*  printf ("la nod = %d\n", nod);
    afis (brut (st - 1, dr - 1, 0));
    afis (arb[nod]);
    printf ("\n\n");*/
}

void DEBUUUUG ()
{
    afis (brut (568, 73898, 0));
    afis (GetTransition (568, 73898));
}

void Forced_Finish (long long pos)
{
    SOL = inm (SOL, GetTransition (pos, K));
    printf ("%d\n", SOL.a[1][1]);
    exit (0);
}

signed main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %d", &K, &P), mod = P;
if (P == 1)
{
    printf ("0\n");
    return 0;
}
if (K == 0)
{
    printf ("0\n");
    return 0;
}
if (K == 1)
{
    printf ("1\n");
    return 0;
}
scanf ("%d", &N);
for (int i=0; i<N; i++)
    scanf ("%d", &S[i]);
scanf ("%d", &M);
for (int i=1; i<=M; i++)
    scanf ("%I64d %d", &wr[i].first, &wr[i].second), Special_S[wr[i].first] = wr[i].second;
sort (wr + 1, wr + M + 1);
for (int i=N; i<2 * N; i++)
    S[i] = S[i-N];
build (1, 1, 2 * N);
Query (1, 1, 2 * N, 1, N + 1), tot = ANS;
//DEBUUUUG ();
//return 0;
SOL.a[0][0] = SOL.a[1][1] = 1;
SOL.a[0][1] = SOL.a[1][0] = 0;
pos = 1;
//printf ("dupa 0 am ajuns la pos = %I64d\n", pos), afis (SOL);
for (int I=1; I<=M; I++)
{
    Try_Finish ();
    if (wr[I].first > K) Forced_Finish (pos);
    SOL = inm (SOL, GetTransition (pos, wr[I].first));
    pos = wr[I].first;
    Try_Finish ();
  //      printf ("dupa %d am ajuns la pos = %I64d\n", I, pos), afis (SOL);
//    afis (brut (1, pos, 1));
    if (wr[I + 1].first - wr[I].first <= 2 && I < M)
    {
        while (wr[I + 1].first - wr[I].first <= 2 && I < M)
        {
            Try_Finish ();
            for (long long j = pos + 1; j<=wr[I + 1].first + 2; j++)
                SOL = muta (SOL, j, 1);
            pos = wr[I + 1].first + 2;
            I ++;
        }
        ////am terminat cu I nu mai modific nimic
    }
    else
    {
        Try_Finish ();
        SOL = muta (SOL, pos + 1, 1);
        SOL = muta (SOL, pos + 2, 1);
        pos += 2;
    }
//    printf ("dupa %d am ajuns la pos = %I64d\n", I, pos), afis (SOL);
  //  afis (brut (1, pos, 1));
}
SOL = inm (SOL, GetTransition (pos, K));
//printf ("sol: "); afis (brut (1, K));
/*printf ("sfarsit GetTransition\n");
afis (GetTransition (pos, K));
afis (brut (pos, K, 1));*/
//printf ("dupa %d am ajuns la pos = %I64d\n", M, K), afis (SOL);
//afis (brut (1, K));
printf ("%d\n", SOL.a[1][1]);
return 0;
}