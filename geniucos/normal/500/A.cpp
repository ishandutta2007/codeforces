#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, K, ap[30009], a[30009];

void dfs (int nod)
{
    ap[nod] = 1;
    if (ap[a[nod]] == 0)
        dfs (a[nod]);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    a[i] += i;
}

dfs (1);

if (ap[K]) printf ("YES\n");
else printf ("NO\n");

return 0;
}