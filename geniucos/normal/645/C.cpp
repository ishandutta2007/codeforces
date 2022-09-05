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

int N, K, s[100009];
char sir[100009];

bool ok (int D)
{
    for (int i=1; i<=N; i++)
        if (sir[i] == '0')
        {
            int st = max (1, i - D), dr = min (N, i + D);
            if (s[dr] - s[st - 1] - 1 >= K) return 1;
        }
    return 0;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &K);
gets (sir + 1);
for (int i=1; i<=N; i++)
    s[i] = s[i - 1] + (sir[i] == '0');
int p = 1, u = N, mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);

return 0;
}