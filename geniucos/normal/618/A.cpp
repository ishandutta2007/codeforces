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

int N, nr, st[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    st[++nr] = 1;
    while (nr > 1 && st[nr] == st[nr - 1])
        st[-- nr] ++;
}
for (int i=1; i<=nr; i++)
    printf ("%d ", st[i]);
printf ("\n");
return 0;
}