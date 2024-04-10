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

int N, sum[500009];
long long S[500009];
char sir[500009];

int vocala (char c)
{
    if (c == 'I') return 1;
    if (c == 'E') return 1;
    if (c == 'A') return 1;
    if (c == 'O') return 1;
    if (c == 'U') return 1;
    if (c == 'Y') return 1;
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1);
N = strlen (sir + 1);

for (int i=1; i<=N; i++)
    sum[i] = sum[i-1] + vocala (sir[i]);

for (int i=1; i<=N; i++)
    S[i] = S[i-1] + sum[i];

double sol = 0.0;
for (int L = 1; L <= N; L ++)
{
    long long curr = S[N] - S[L-1] - S[N-L];
    sol = (double) sol + (double) curr / L;
}
printf ("%.8lf\n", sol);

return 0;
}