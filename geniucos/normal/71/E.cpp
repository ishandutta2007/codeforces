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

string elems[] =
{"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As",
"Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd",
"Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am",
"Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Uut","Fl","Uup","Lv","Uus","Uuo"};

map < string , int > mp;

int nr, N, K, B[109], D[109], E[109], dp[(1<<17) + 3], how[(1<<17) + 3], sum[(1<<17) + 3], ans[109], curr[109];
string A[109], C[109];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<100; i++)
    mp[elems[i]] = i + 1;

scanf ("%d %d\n", &N, &K);
for (int i=0; i<N; i++)
{
    char sir[5];
    scanf ("%s", sir + 1);
    A[i] = sir + 1, B[i] = mp[A[i]];
}

for (int i=1; i<=K; i++)
{
    char sir[5];
    scanf ("%s", sir + 1);
    C[i] = sir + 1, D[i] = mp[C[i]], E[i] = E[i-1] + D[i];
}

for (int i=1; i<(1<<N); i++)
    for (int j=0; j<N; j++)
        if (i & (1 << j)) sum[i] += B[j];

dp[0] = 1;
for (int i=1; i<=K; i++)
    for (int j=0; j<(1<<N); j++)
        if (sum[j] == E[i])
        {
            for (int k=j; ; k = (k - 1) & j)
            {
                if (sum[k] == D[i] && dp[j ^ k])
                {
                    dp[j] = 1, how[j] = k;
                    break;
                }
                if (k == 0) break;
            }
        }

int msk = -1, i = K;
for (int j=0; j<(1<<N); j++)
    if (dp[j] && sum[j] == E[K])
        msk = j;

if (msk == -1)
{
    printf ("NO\n");
    return 0;
}

while (msk)
{
    int val = how[msk];
    ans[i --] = val;
    msk -= val;
}

printf ("YES\n");
for (int i=1; i<=K; i++)
{
    nr = 0;
    for (int j=0; j<N; j++)
        if (ans[i] & (1 << j)) curr[++nr] = j;
    for (int j=1; j<=nr; j++)
    {
        printf ("%s", A[curr[j]].c_str ());
        if (j == nr) printf ("->");
        else printf ("+");
    }
    printf ("%s\n", C[i].c_str ());
}
return 0;
}