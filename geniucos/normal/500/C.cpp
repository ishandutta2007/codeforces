#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, M, ap[509], w[509], a[1009];
long long sol;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &w[i]);
for (int i=1; i<=M; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=M; i++)
{
    int j;
    for (int j=1; j<=N; j++)
        ap[j] = 0;

    for (j=i - 1; j>=1; j--)
        if (a[j] == a[i])
            break;

    for (j = j+1; j<i; j++)
        if (ap[a[j]] == 0)
        {
            ap[a[j]] = 1;
            sol += w[a[j]];
        }
}
printf ("%I64d\n", sol);

return 0;
}