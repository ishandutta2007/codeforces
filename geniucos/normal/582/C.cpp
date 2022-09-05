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

int N, i_N[200009], a[200009];
bool bun[400009];
long long sol;

int gcd (int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void add (int l, int d)
{
    for (int i=1; i<=l; i++)
        if (i_N[i] == d)
            sol += l - i + 1;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    i_N[i] = gcd (i, N);
    scanf ("%d", &a[i - 1]);
}

for (int d = 1; d < N; d ++)
    if (N % d == 0)
    {
        bool macar = 0;
        for (int i=0; i<d; i++)
        {
            int maxi = 0;
            for (int j=i; j<N; j+=d)
                if (a[j] > maxi) maxi = a[j];
            for (int j=i; j<N; j+=d)
            {
                bun[j] = (a[j] == maxi);
                if (a[j] != maxi) macar = 1;
            }
        }
        if (!macar)
        {
            for (int i=1; i<N; i++)
                if (i_N[i] == d)
                    sol += N;
            continue;
        }
        for (int j=N; j<2 * N; j++)
            bun[j] = bun[j - N];
        int beg = 0;
        while (bun[beg]) beg ++;
        for (int i=beg; i<=N; i++)
        if (bun[i])
        {
            int j;
            for (j=i; j<2 * N; j++)
                if (bun[j] == 0) break;
            j --;
            add (j - i + 1, d);
            i = j;
        }
    }
printf ("%I64d\n", sol);

return 0;
}