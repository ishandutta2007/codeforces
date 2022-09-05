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

int nr, N, a[100009], v[100009];
long long sol;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

sort (a + 1, a + N + 1);
reverse (a + 1, a + N + 1);

for (int i=1; i<N; i++)
{
    if (a[i] == a[i+1])
        v[++nr] = a[i], i++;
    else
    if (a[i] == a[i+1] + 1)
        a[i] --, i --;
}

for (int i=1; i <= nr; i += 2)
    sol += 1LL * v[i] * v[i+1];
printf ("%I64d\n", sol);

return 0;
}